# The python code in this file does the same as ACT-01 to ACT-05 of opm-tests/actionx/ACTIONX_WCONPROD.DATA
import datetime
import opm_embedded

ecl_state = opm_embedded.current_ecl_state
summary_state = opm_embedded.current_summary_state
schedule = opm_embedded.current_schedule
report_step = opm_embedded.current_report_step

if (not 'setup_done' in locals()):
    executed = [False] * 4
    setup_done = True

current_time = schedule.start + datetime.timedelta(seconds=summary_state.elapsed())

wells_WWCT = [summary_state.well_var("P1", "WWCT"), summary_state.well_var("P2", "WWCT"), summary_state.well_var("P3", "WWCT"), summary_state.well_var("P4", "WWCT"), summary_state.well_var("INJ", "WWCT")]

ready_to_exit = True
for wwct in wells_WWCT:
    ready_to_exit = ready_to_exit and (wwct > 0.50)

if (report_step == 1):
    print("PYACTION triggered at {}\n".format(current_time))
    kw = """
    EXIT
    99 /
    """
    schedule.insert_keywords(kw)
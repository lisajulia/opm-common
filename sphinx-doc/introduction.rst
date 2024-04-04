Introduction
============

The PYACTION keyword is a flow specific keyword which allows for Python
programming in the SCHEDULE section.

The PYACTION keyword is inspired
by the ACTIONX keyword, but instead of a .DATA formatted condition you
are allowed to implement the condition with a general Python script. The
ACTIONX keywords are very clearly separated in a condition part and an
action part in the form of a list of keywords which are effectively injected in
the SCHEDULE section when the condition evaluates to true. This is not so
for PYACTION where there is only one Python script which can both evaluate
conditions and apply changes. In principle the script can run arbitrary code,
but due to the complexity of the SCHEDULE datamodel the “current best”
way to actually change the course of the simulation is through the use of an
additional dummy ACTIONX keyword.

In order to enable the PYACTION keyword flow must be compiled with the
cmake switches -DOPM ENABLE EMBEDDED PYTHON=ON and -DOPM ENABLE PYTHON=ON,
the default is to build with these switches set to OFF. Before you enable
PYACTION in your flow installation please read carefully through section 3.5
for security implications of PYACTION.
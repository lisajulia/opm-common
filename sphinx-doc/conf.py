# Configuration file for the Sphinx documentation builder for opm_embedded
# Build the documentation by calling "sphinx-build -M html sphinx-doc/ sphinx-doc/" in opm-common

import os
import sys
sys.path.insert(0, os.path.abspath('../build-cmake/python'))
sys.path.insert(0, os.path.abspath('../build-cmake/python/opm'))

autosummary_generate = True

templates_path = ["_templates"]
exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]

html_theme = "sphinx_rtd_theme"

extensions = [
    "sphinx.ext.autodoc",
    "sphinx.ext.intersphinx",
    "sphinx.ext.autosummary",
    "sphinx.ext.napoleon",
]

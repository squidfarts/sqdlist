#!/user/bin/env python3
###################################################################################
#                                                                                 #
# NAME: build.py                                                                  #
#                                                                                 #
# AUTHOR: Michael Brockus.                                                        #
#                                                                                 #
# CONTACT: <mailto:michael@squidfarts.com>                                        #
#                                                                                 #
# NOTICES:                                                                        #
#                                                                                 #
# License: Apache-2.0                                                             #
#                                                                                 #
###################################################################################
import subprocess, os

subprocess.call('meson setup build_dir -Dwith_tests=enabled -Db_coverage=true --backend=ninja', shell=True)
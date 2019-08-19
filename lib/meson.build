###################################################################################
#                                                                                 #
# NAME: lib/meson.build                                                           #
#                                                                                 #
# AUTHOR: Michael Brockus.                                                        #
#                                                                                 #
# CONTACT: <mailto:michael@squidfarts.com>                                        #
#                                                                                 #
# NOTICES:                                                                        #
#                                                                                 #
# License: Apache 2.0 :http://www.apache.org/licenses/LICENSE-2.0                 #
#                                                                                 #
###################################################################################



sqdlist_dir = include_directories('.')

sqdlist_lib = static_library(meson.project_name(), 
    sources: 'list.c',
    include_directories: sqdlist_dir)

sqdlist_dep = declare_dependency(
    version: meson.project_version(),
    link_with: sqdlist_lib,
    include_directories: sqdlist_dir)
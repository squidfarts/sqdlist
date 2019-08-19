###################################################################################
#                                                                                 #
# NAME: src/test/meson.build                                                      #
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



test_cases = [
    ['01-case', ['test.c', 'test_runner.c']]
    ]

foreach test_case : test_cases
    test_exe = executable(
        test_case[0], 
        test_case[1], 
        dependencies: [ unity_dep, sqdlist_dep ])
    test('Running test case ' + test_case[0], test_exe)

endforeach
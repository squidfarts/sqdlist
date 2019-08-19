/***********************************************************************************
 *                                                                                 *
 * NAME: test_runner.c                                                             *
 *                                                                                 *
 * AUTHOR: Michael Brockus.                                                        *
 *                                                                                 *
 * CONTACT: <mailto:michael@squidfarts.com>                                        *
 *                                                                                 *
 * PURPOSE:                                                                        *
 *                                                                                 *
 * In this file the `main()` function will call `UNITY_BEGIN()`, then `RUN_TEST`   *
 * for each test, and finally `UNITY_END()`.  This is what will actually trigger   *
 * each of those test functions to run, so it is important that each function      *
 * gets its own `RUN_TEST` call.                                                   *
 *                                                                                 *
 * NOTICES:                                                                        *
 *                                                                                 *
 * License: Apache 2.0 :http://www.apache.org/licenses/LICENSE-2.0                 *
 *                                                                                 *
 ***********************************************************************************/
#include <unity.h>
#include "list.h"

/*
 *  Prototype functions for setup and teardown.
 */
extern void setUp(void);
extern void tearDown(void);

/*
 *  Prototype functions from the external test file.
 */
extern void test_insertNode(void);
extern void test_insertHead(void);
extern void test_insertTeal(void);
extern void test_set(void);
extern void test_getFrom(void);
extern void test_getHead(void);
extern void test_getTail(void);
extern void test_removeNode(void);
extern void test_removeHead(void);
extern void test_removeTail(void);
extern void test_iterEach(void);
extern void test_iterEachReverse(void);
extern void test_clear(void);

/*
 *  This function runs test from the external test
 *  file.
 */
int main(void)
{
    UNITY_BEGIN();
    
    RUN_TEST(test_insertNode);
    RUN_TEST(test_insertHead);
    RUN_TEST(test_insertTeal);
    RUN_TEST(test_set);
    RUN_TEST(test_getFrom);
    RUN_TEST(test_getHead);
    RUN_TEST(test_getTail);
    RUN_TEST(test_removeNode);
    RUN_TEST(test_removeHead);
    RUN_TEST(test_removeTail);
    RUN_TEST(test_iterEach);
    RUN_TEST(test_iterEachReverse);
    RUN_TEST(test_clear);
    
    return UNITY_END();
}//end of function main

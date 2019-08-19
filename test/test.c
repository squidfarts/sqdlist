/***********************************************************************************
 *                                                                                 *
 * NAME: test.c                                                                    *
 *                                                                                 *
 * AUTHOR: Michael Brockus.                                                        *
 *                                                                                 *
 * CONTACT: <mailto:michael@squidfarts.com>                                        *
 *                                                                                 *
 * PURPOSE:                                                                        *
 *                                                                                 *
 * The majority of the file will be a series of test functions. Test functions     *
 * follow the convention of starting with the word "test_" or "spec_". You don't   *
 * HAVE to name them this way, but it makes it clear what functions are tests for  *
 * other developers.  Also, the automated scripts that come with Unity or Ceedling *
 * will default to looking for test functions to be prefixed this way. Test        *
 * functions take no arguments and return nothing. All test accounting is handled  *
 * internally in Unity.                                                            *
 *                                                                                 *
 * NOTICES:                                                                        *
 *                                                                                 *
 * License: Apache 2.0 :http://www.apache.org/licenses/LICENSE-2.0                 *
 *                                                                                 *
 ***********************************************************************************/
#include <unity.h>
#include "list.h"

enum { MAX_STR_TEST_SIZE = 50 };

/* Global variables */
size_t each_a = 1, each_b = 2, each_c = 3;
SqdListOf * testList;
SqdListOf * testEachList;
char  a = 'A';
int   b = 15;
const char *c = "str";

/*
 *  Prototype functions for setup and teardown.
 */
void setUp(void)
{
    testList = createList();
}//end of function setUp



void tearDown(void)
{
    destroyList(testList);
}//end of function tearDown


/*
 *  Prototype functions from the external test file.
 */
void test_insertNode(void);
void test_insertHead(void);
void test_insertTeal(void);
void test_set(void);
void test_getFrom(void);
void test_getHead(void);
void test_getTail(void);
void test_removeNode(void);
void test_removeHead(void);
void test_removeTail(void);
void test_iterEach(void);
void test_iterEachReverse(void);
void test_clear(void);


void test_insertNode(void)
{
    TEST_ASSERT_NULL(getFrom(testList, 0));
    
    insertAtTail(testList, &a);
    insertAtTail(testList, &b);
    insertAtTail(testList, &c);
    
    TEST_ASSERT_NOT_NULL(getFrom(testList, 0));/* Get from an invalid position */
}//end of test case



void test_set(void)
{
    TEST_ASSERT_NULL(getFrom(testList, 0));
    
    insertAtTail(testList, &a);
    insertAtTail(testList, &b);
    insertAtTail(testList, &c);
    
    /* Set at an unused position */
    TEST_ASSERT_EQUAL(NULL, setNode(testList, &a, -1));
    
    TEST_ASSERT_EQUAL(&a, setNode(testList, &c, 0));
    TEST_ASSERT_EQUAL(&c, testList->_headPtr->_data);
    TEST_ASSERT_EQUAL(&b, testList->_headPtr->_nextPtr->_data);
    
    TEST_ASSERT_EQUAL(&c, setNode(testList, &a, 2));
    TEST_ASSERT_EQUAL(&a, testList->_tailPtr->_data);
    TEST_ASSERT_EQUAL(&b, testList->_tailPtr->_prevPtr->_data);
    
}//end of test case



void test_removeNode(void)
{
    TEST_ASSERT_NULL(getFrom(testList, 0));
    
    insertAtTail(testList, &a); // Index 0
    insertAtTail(testList, &b); // Index 1
    insertAtTail(testList, &c); // Index 2
    
    removeNodeFrom(testList, 1);
    
    TEST_ASSERT_EQUAL_PTR(&c, getTail(testList));
    TEST_ASSERT_EQUAL_PTR(&c, getTail(testList));
    
}//end of test case



void test_getFrom(void)
{
    
    TEST_ASSERT_NULL(getFrom(testList, 0));
    
    insertAtTail(testList, &a);
    insertAtTail(testList, &b);
    insertAtTail(testList, &c);
    
    TEST_ASSERT_NULL(getFrom(testList, 3));/* Get from an unused position */
    TEST_ASSERT_NULL(getFrom(testList, -1));/* Get from an invalid position */
    
}//end of test case



void test_getHead(void)
{
    
    insertAtTail(testList, &a);
    insertAtTail(testList, &b);
    insertAtTail(testList, &c);
    
    TEST_ASSERT_EQUAL_PTR(&a, getHead(testList));
    removeFromHead(testList);
    TEST_ASSERT_EQUAL_PTR(&b, getHead(testList));
    
}//end of test case



void test_getTail(void)
{
    
    insertAtTail(testList, &a);
    insertAtTail(testList, &b);
    insertAtTail(testList, &c);
    
    TEST_ASSERT_EQUAL_PTR(&c, getTail(testList));
    removeFromTail(testList);
    TEST_ASSERT_EQUAL_PTR(&b, getTail(testList));
    
}//end of test case



void test_insertHead(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, testList->_size);
    
    insertAtHead(testList, &a);
    
    TEST_ASSERT_NOT_NULL(testList);
    TEST_ASSERT_EQUAL_UINT8(1, testList->_size);
    TEST_ASSERT_EQUAL_PTR(&a, getHead(testList));
    
}//end of test case



void test_insertTeal(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, testList->_size);
    
    insertAtHead(testList, &a);
    insertAtTail(testList, &b);
    
    TEST_ASSERT_NOT_NULL(testList);
    TEST_ASSERT_EQUAL_UINT8(2, testList->_size);
    TEST_ASSERT_EQUAL_PTR(&b, getTail(testList));
}//end of test case



void test_removeHead(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, testList->_size);
    
    insertAtHead(testList, &a);
    insertAtTail(testList, &b);
    removeFromHead(testList);
    
    TEST_ASSERT_NOT_NULL(testList);
    TEST_ASSERT_EQUAL_UINT8(1, testList->_size);
    TEST_ASSERT_EQUAL_PTR(&b, getHead(testList));
}//end of test case



void test_removeTail(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, testList->_size);
    
    insertAtHead(testList, &a);
    insertAtTail(testList, &b);
    removeFromTail(testList);
    
    TEST_ASSERT_NOT_NULL(testList);
    TEST_ASSERT_EQUAL_UINT8(1, testList->_size);
    TEST_ASSERT_EQUAL_PTR(&a, getTail(testList));
}//end of test case


static void each_test_function(void *x)
{
    insertAtTail(testEachList, x);
}


void test_iterEach(void)
{
    testEachList = createList();
    
    insertAtTail(testList, &each_a);
    insertAtTail(testList, &each_b);
    insertAtTail(testList, &each_c);
    
    forEachNode(testList, each_test_function);
    
    TEST_ASSERT_EQUAL_UINT8(&each_a, getFrom(testEachList, 0));
    TEST_ASSERT_EQUAL_UINT8(&each_b, getFrom(testEachList, 1));
    TEST_ASSERT_EQUAL_UINT8(&each_c, getFrom(testEachList, 2));
    
    insertAtTail(testList, &each_a);
    insertAtTail(testList, &each_b);
    insertAtTail(testList, &each_c);
    
    destroyList(testEachList);
}//end of test case



void test_iterEachReverse(void)
{
    testEachList = createList();
    
    insertAtTail(testList, &each_a);
    insertAtTail(testList, &each_b);
    insertAtTail(testList, &each_c);
    
    forEachNodeReverse(testList, each_test_function);
    
    TEST_ASSERT_EQUAL_UINT8(&each_a, getFrom(testEachList, 2));
    TEST_ASSERT_EQUAL_UINT8(&each_b, getFrom(testEachList, 1));
    TEST_ASSERT_EQUAL_UINT8(&each_c, getFrom(testEachList, 0));
    
    insertAtTail(testList, &each_a);
    insertAtTail(testList, &each_b);
    insertAtTail(testList, &each_c);
    
    destroyList(testEachList);
}//end of test case



void test_clear(void)
{
    TEST_ASSERT_EQUAL_UINT8(0, testList->_size);
    
    insertAtTail(testList, &a);
    insertAtTail(testList, &b);
    insertAtTail(testList, &c);
    
    TEST_ASSERT_EQUAL_UINT8(3, testList->_size);
    clearList(testList);
    
    TEST_ASSERT_EQUAL_UINT8(0, testList->_size);
    TEST_ASSERT_NULL(testList->_headPtr);
    TEST_ASSERT_NULL(testList->_tailPtr);
}//end of test case

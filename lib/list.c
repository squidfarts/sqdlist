/***********************************************************************************
 *                                                                                 *
 * NAME: list.c                                                                    *
 *                                                                                 *
 * AUTHOR: Michael Brockus.                                                        *
 *                                                                                 *
 * CONTACT: <mailto:michael@squidfarts.com>                                        *
 *                                                                                 *
 * PURPOSE:                                                                        *
 *                                                                                 *
 * This file contains function prototypes for this project.  It is where all       *
 * required functions are defined for later use.                                   *
 *                                                                                 *
 * NOTICES:                                                                        *
 *                                                                                 *
 * MIT License                                                                     *
 *                                                                                 *
 * Copyright (c) 2019 Micheal Brockus                                              *
 *                                                                                 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy    *
 * of this software and associated documentation files (the "Software"), to deal   *
 * in the Software without restriction, including without limitation the rights    *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is           *
 * furnished to do so, subject to the following conditions:                        *
 *                                                                                 *
 * The above copyright notice and this permission notice shall be included in all  *
 * copies or substantial portions of the Software.                                 *
 *                                                                                 *
 * DISCLAIMERS:                                                                    *
 *                                                                                 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   *
 * SOFTWARE.                                                                       *
 *                                                                                 *
 ***********************************************************************************/
#include "list.h"

/*
 * Find a node from the list.
 *
 */
static SqdNodeOf * findNode(SqdListOf * dll, const size_t pos)
{
    if(pos > dll->_size) return NULL;
    
    SqdNodeOf * currNode;
    size_t currPos;
    size_t reverse;
    
    /* decide where to start iterating from (font or back of the list) */
    if (pos > ((dll->_size -1) / 2))
    {
        reverse  = 1;
        currPos  = dll->_size - 1;
        currNode = dll->_tailPtr;
    }
    else
    {
        reverse = 0;
        currPos = 0;
        currNode = dll->_headPtr;
    }
    
    while(currNode != NULL)
    {
        if(currPos == pos) break;
        
        currNode = (reverse ? (currNode->_prevPtr) : (currNode->_nextPtr));
        currPos  = (reverse ? (--currPos) : (++currPos));
    }
    return currNode;
}

/*
 * Create a new node by allocating memory for one.
 *
 */
static SqdNodeOf * createNode(void * data)
{
    SqdNodeOf * newNode = malloc(sizeof(* newNode));
    
    if (newNode)
    {
        newNode->_nextPtr = NULL;
        newNode->_prevPtr = NULL;
        newNode->_data = data;
    }
    else return NULL;
    
    return newNode;
}

/*
 * Create a new list by allocating memory for one.
 *
 */
SqdListOf * createList(void)
{
    SqdListOf * newList = malloc(sizeof(* newList));
    
    if (newList)
    {
        newList->_headPtr = NULL;
        newList->_tailPtr = NULL;
        newList->_size = 0;
    }
    return (newList)? newList : NULL;
}

/*
 * Get a node from any position you like.
 *
 */
void *getFrom(SqdListOf * dll, const size_t pos)
{
    SqdNodeOf * node = findNode(dll, pos);
    return (node)? node->_data : NULL;
}

/*
 * Get a node from head of list.
 *
 */
void *getHead(SqdListOf * dll)
{
    return (!dll->_headPtr)? NULL : dll->_headPtr->_data;
}

/*
 * Get a node from tail of list.
 *
 */
void *getTail(SqdListOf * dll)
{
    return (!dll->_tailPtr)? NULL : dll->_tailPtr->_data;
}

/*
 * Check to see if list is null.
 *
 */
int isNullList(SqdListOf * dll)
{
    return (dll != NULL)?  1 : 0;
}

/*
 * Check to see if list is not null.
 *
 */
int notNullList(SqdListOf * dll)
{
    return (dll != NULL)?  1 : 0;
}

/*
 * Set a node's value to any value you like.
 *
 */
void * setNode(SqdListOf * dll, void * data, const size_t pos)
{
    SqdNodeOf * currNode = findNode(dll, pos);
    
    if (!currNode) return NULL;
    
    void * oldData = currNode->_data;
    currNode->_data = data;
    
    return oldData;
}

/*
 * Insert a node of any type you like into your linked list
 *
 */
int8_t insertNode(SqdListOf * dll, void * data, const size_t pos)
{
    if(pos > dll->_size) return EXIT_FAILURE;
    
    SqdNodeOf * newNode, * currNode;
    
    /* Create the new node */
    newNode = createNode(data);
    
    /* if list is empty */
    if(dll->_size == 0)
    {
        dll->_headPtr = newNode;
        dll->_tailPtr = newNode;
        
        ++dll->_size;
        return EXIT_SUCCESS;
    }
    
    /* if list is not empty */
    currNode = findNode(dll, pos);
    
    /* adding at the front or in the middle */
    if(currNode)
    {
        newNode->_prevPtr = currNode->_prevPtr;
        newNode->_nextPtr = currNode;
    
        if(currNode->_prevPtr == NULL)
        {
            dll->_headPtr = newNode;
        }
        else
        {
            currNode->_prevPtr->_nextPtr = newNode;
        }
        currNode->_prevPtr = newNode;
    }
    else
    { /* adding at the end */
        dll->_tailPtr->_nextPtr = newNode;
        newNode->_prevPtr = dll->_tailPtr;
        dll->_tailPtr = newNode;
    }
    dll->_size++;
    return EXIT_SUCCESS;
}

/*
 * Insert a node of any type into the head of the linked list
 *
 */
int8_t insertAtHead(SqdListOf * dll, void * data)
{
    SqdNodeOf * newNode = createNode(data);
    
    /* if list is empty */
    if(dll->_size == 0)
    {
        dll->_tailPtr = newNode;
    }
    else
    {
        /* if there is at least one element */
        dll->_headPtr->_prevPtr = newNode;
        newNode->_nextPtr = dll->_headPtr;
    }
    dll->_headPtr = newNode;
    ++dll->_size;
    return EXIT_SUCCESS;
}

/*
 * Insert a node of any type into the tail of the linked list
 *
 */
int8_t insertAtTail(SqdListOf * dll, void * data)
{
    /* initialize new node */
    SqdNodeOf * newNode = createNode(data);
    
    /* if list is empty */
    if(dll->_size == 0)
    {
        dll->_headPtr = newNode;
    }
    else
    {
        /* if there is at least one element */
        dll->_tailPtr->_nextPtr = newNode;
        newNode->_prevPtr = dll->_tailPtr;
    }
    dll->_tailPtr = newNode;
    ++dll->_size;
    return EXIT_SUCCESS;
}

/*
 * Remove list node from any position you like.
 *
 */
void * removeNodeFrom(SqdListOf * dll, const size_t pos)
{
    if(!dll) return NULL;
    SqdNodeOf * currNode = findNode(dll, pos);

    if(!currNode) return NULL;
    void * data = currNode->_data;
    
    if(!currNode->_prevPtr)
    {
        dll->_headPtr = iterNext(&currNode);
    }
    else
    {
        currNode->_prevPtr->_nextPtr = iterNext(&currNode);
    }
    if(!currNode->_nextPtr)
    {
        dll->_tailPtr = iterPrev(&currNode);
    }
    else
    {
        currNode->_nextPtr->_prevPtr = currNode->_prevPtr;
    }
    --dll->_size;
    
    free(currNode);
    return data;
}

/*
 * Remove list node from the head.
 *
 */
void *removeFromHead(SqdListOf * dll)
{
    if(!dll) return NULL;
    
    SqdNodeOf * node = dll->_headPtr;
    if(!node) return NULL;
    
    void *data = node->_data;
    if(!removeNodeFrom(dll, 0))
    {
        return NULL;
    }
    return data;
}

/*
 * Remove list node from tail.
 *
 */
void *removeFromTail(SqdListOf * dll)
{
    SqdNodeOf * node = dll->_tailPtr;
    if (!node) return NULL;
    
    void *data = node->_data;
    
    if (!removeNodeFrom(dll, (dll->_size -1)))
    {
        return NULL;
    }
    return data;
}

/*
 * Iterate each item in the list
 *
 */
SqdNodeOf * iterNext(SqdNodeOf ** dll)
{
    if (dll == NULL) return NULL;
    else return (*dll)->_nextPtr;
}

/*
 * Iterate each item in the list in reverse
 *
 */
SqdNodeOf * iterPrev(SqdNodeOf ** dll)
{
    if (dll == NULL) return NULL;
    else return (*dll)->_prevPtr;
}

/*
 * Function to reverse a Doubly Linked List
 *
 */
void reverseList(SqdNodeOf ** dllRef)
{
    SqdNodeOf *temp = NULL;
    SqdNodeOf *currNode = * dllRef;
    
    /*
     * swap next and prev for all nodes of
     * doubly linked list
     */
    while (currNode !=  NULL)
    {
        temp = currNode->_prevPtr;
        currNode->_prevPtr = iterNext(&currNode);
        currNode->_nextPtr = temp;
        currNode = iterPrev(&currNode);
    }
    
    /*
     * Before changing head, check for the cases like empty
     * list and list with only one node
     */
    if(temp != NULL) *dllRef = iterPrev(&temp);
}

/*
 * For each item in the list
 *
 */
void forEachNode(SqdListOf * dll, void (*fun)(void *))
{
    SqdNodeOf * currNode = dll->_headPtr;
    
    while(currNode)
    {
        (*fun)(currNode->_data);
        currNode = iterNext(&currNode);
    }
}

/*
 * For each item in the list in reverse
 *
 */
void forEachNodeReverse(SqdListOf * dll, void (*fun)(void *))
{
    SqdNodeOf * currNode = dll->_tailPtr;
    
    while(currNode)
    {
        (*fun)(currNode->_data);
        currNode = iterPrev(&currNode);
    }
}

/*
 * Clear your data from your list
 *
 */
void clearList(SqdListOf * dll)
{
    SqdNodeOf * currNode = dll->_headPtr;
    SqdNodeOf * _nextPtrNode;
    
    while(currNode)
    {
        _nextPtrNode = iterNext(&currNode);
        free(currNode);
        currNode = _nextPtrNode;
    }
    
    dll->_headPtr = dll->_tailPtr = NULL;
    dll->_size = 0;
}

/*
 * Destructively destroy your linked list.
 *
 */
void destroyList(SqdListOf * dll)
{
    clearList(dll);
    free(dll);
}

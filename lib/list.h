/***********************************************************************************
 *                                                                                 *
 * NAME: list.h                                                                    *
 *                                                                                 *
 * AUTHOR: Michael Brockus.                                                        *
 *                                                                                 *
 * CONTACT: <mailto:michael@squidfarts.com>                                        *
 *                                                                                 *
 * PURPOSE:                                                                        *
 *                                                                                 *
 * This file contains function prototypes for this project.  It is where all       *
 * linked list of prototype functions are defined.                                 *
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
#ifndef SQUID_DOUBLY_LINKED_LIST_H
#define SQUID_DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct SqdNodeOf_s// Structure of a Node
{
    void * _data;
    struct SqdNodeOf_s * _nextPtr;
    struct SqdNodeOf_s * _prevPtr;
}
SqdNodeOf;

// Structure of a List
typedef struct SqdListOf_s
{
    size_t _size;
    struct SqdNodeOf_s * _headPtr;
    struct SqdNodeOf_s * _tailPtr;
}
SqdListOf;


/*  create new list */
SqdListOf * createList(void);

/*  get/find functions */
void * getFrom(SqdListOf * dll, const size_t pos);
void * getHead(SqdListOf * dll);
void * getTail(SqdListOf * dll);
int isNullList(SqdListOf * dll);
int notNullList(SqdListOf * dll);
void reverseList(SqdNodeOf ** dllRef);

/*  add functions */
void * setNode(SqdListOf * dll, void * data, const size_t pos);
int8_t insertNode(SqdListOf * dll, void * data, const size_t pos);
int8_t insertAtHead(SqdListOf * dll, void * data);
int8_t insertAtTail(SqdListOf * dll, void * data);

/*  remove functions */
void * removeNodeFrom(SqdListOf * dll, const size_t pos);
void * removeFromHead(SqdListOf * dll);
void * removeFromTail(SqdListOf * dll);

/*  iterate functions */
SqdNodeOf * iterNext(SqdNodeOf ** dll);
SqdNodeOf * iterPrev(SqdNodeOf ** dll);

/*  for each functions */
void forEachNode(SqdListOf * dll, void (*fun)(void *));
void forEachNodeReverse(SqdListOf * dll, void (*fun)(void *));

/*  destructive functions */
void clearList(SqdListOf * dll);
void destroyList(SqdListOf * dll);

#endif /* SQUID_HEADER_H */

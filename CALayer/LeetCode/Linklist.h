//
//  Linklist.h
//  LeetCode
//
//  Created by Jeremy on 2019/3/20.
//  Copyright © 2019 Jeremy. All rights reserved.
//

#ifndef Linklist_h
#define Linklist_h

#include <stdio.h>

typedef struct linkList{
    int Element;
    struct linkList* next;
}LinkList;


void fastSort(int array[],int l,int r);


#endif /* Linklist_h */

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

/*
 *https://zhidao.baidu.com/question/122162641.html
 */
int sortArray(int a[10]);


#endif /* Linklist_h */

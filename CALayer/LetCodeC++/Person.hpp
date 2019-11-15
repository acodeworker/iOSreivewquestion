//
//  Person.hpp
//  LetCodeC++
//
//  Created by zmodo on 2019/10/24.
//  Copyright © 2019 Jeremy. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>


/**
 给定两个 非空 链表来表示两个非负整数。位数按照 逆序 方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
 
 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 
 示例：
 
 输入： (2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出： 7 -> 0 -> 8
 原因： 342 + 465 = 807
 */
/**
 * Add Two Numbers
 * 两数相加
 */

struct ListNode {
public:
    int value;
    ListNode* next;
    ListNode(int num);
    void printValue(ListNode* &l);
    
};

class Person {
    
    
public:
    ListNode* addNum(ListNode*l1,ListNode*l2);
    int moveToNextNode(ListNode* &l1);
};


#endif /* Person_hpp */

//
//  Person.cpp
//  LetCodeC++
//
//  Created by zmodo on 2019/10/24.
//  Copyright © 2019 Jeremy. All rights reserved.
//

#include "Person.hpp"
#include <iostream>


ListNode* Person::addNum(ListNode* l1, ListNode* l2){
    /**
     int a = 5; int* p = &a; 然后令*p = 8;  则a = 8;
     */
    ListNode* h = NULL; ListNode ** t = &h;
    
    int carry = 0;
    while (l1 !=NULL ||l2 !=NULL) {
        int a = moveToNextNode(l1);
        int b = moveToNextNode(l2);
        
        int num =  a + b + carry;
        ListNode* node = new ListNode(num%10);
        *t = node;
        t = &(node->next);
        carry = num/10;
    }
    
    if (carry > 0) {
        ListNode* node = new ListNode(carry);
        node->next = NULL;
        *t = node;
    }else{
        *t = NULL;
    }
    return h;
}
//形参：函数的传参
//实参：调用这个函数时传人的参数。
//list* &l 这样写的话，函数就可以改变实参的值
int Person::moveToNextNode(ListNode* &l){
    int num = 0;
    if (l != NULL) {
        num = l->value;
        l = l->next;
    }
    return num;
}
 
void ListNode::printValue(ListNode *&l){
    while (l != NULL) {
        std::clog<<l->value<<"->";
        l = l->next;
    }
    std::clog<<std::endl;
}

ListNode::ListNode(int num){
    value = num;
}

//
//  main.cpp
//  LetCodeC++
//
//  Created by Jeremy on 2019/10/16.
//  Copyright © 2019 Jeremy. All rights reserved.
//

#include <iostream>


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

    int value;
    ListNode* next;
    ListNode(int val){
        value = val;
    };
    void print(ListNode* &l1);
};

void ListNode::print(ListNode* &l1){
    while (l1 != NULL) {
        std::clog<<l1->value<<"->";
        l1 = l1->next;
    }
    std::clog<<std::endl;
}

class Solution {

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int x=0, y=0, carry=0, sum=0;
        ListNode *h = NULL, **t = &h;
  /**
   int a; int* p = &a; 操作 *p = 6; 那么a = 6;
   ListNode *h = NULL, **t = &h; 就是这个逻辑
   */
        while (l1!=NULL || l2!=NULL){
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);
            
            sum = carry + x + y;
            
            ListNode *node = new ListNode(sum%10);
            *t = node;
            //第一次执行时，把第一个节点给了h
            t = (&node->next);
            // 执行完这行，下次再操作*t就是操作node->next
            carry = sum/10;
        }
        
        if (carry > 0) {
            ListNode *node = new ListNode(carry%10);
            node->next = NULL;
            *t = node;
            
        }else{
            *t = NULL;
        }
        
        return h;
    }
private:
    // & 代表可以操作实参。
    int getValueAndMoveNext(ListNode* &l){
        int x = 0;
        if (l != NULL){
            x = l->value;
            l = l->next;
        }
        return x;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    ListNode* node4 = NULL;
    ListNode* node1 = new ListNode(2);
    node4 = node1;
    node1->next = new  ListNode(3);
    node1 = node1->next;
    node1->next = new  ListNode(4);
    node1 = node1->next;
    node1->next = NULL;
    
//    node4->print(node4);

    
    
    ListNode* node3 = NULL;
    ListNode* node2 = new ListNode(9);
    node3 = node2;
    node2->next = new  ListNode(3);
    node2 = node2->next;
    node2->next = new  ListNode(4);
    node2 = node2->next;
    node2->next = NULL;
    
    Solution s;
    ListNode* node = s.addTwoNumbers(node3, node4);
    node->print(node);
    return 0;
}

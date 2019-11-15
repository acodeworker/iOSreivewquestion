//
//  Linklist.c
//  LeetCode
//
//  Created by Jeremy on 2019/3/20.
//  Copyright © 2019 Jeremy. All rights reserved.
//

#include "Linklist.h"


LinkList* list_init(int value){
    LinkList* headNode = (LinkList*)malloc(sizeof(LinkList));
    headNode->Element = value;
    headNode->next = NULL;
    return headNode;
}

//创建链表
void CreatList(LinkList* headNode, int* intData,int dataNum ){

    LinkList* currentNode = headNode;
    for (int i = 0; i<dataNum; i++) {
        currentNode->Element = intData[i];
        if (i< dataNum - 1) {//最后一个不执行
            currentNode->next = (LinkList*)malloc(sizeof(LinkList));
            currentNode = currentNode->next;
        }
    }
    currentNode->next = NULL;
}

//插入值 index 前
void insert(LinkList* headNode,int value, int index){
    LinkList* currentNode = headNode;
    int i = 1;
    LinkList* newnode = malloc(sizeof(LinkList));
    while (currentNode && i< index-1) {
        currentNode = currentNode->next;
        i++;
    }
    newnode->next = currentNode->next;
    newnode->Element = value;
    currentNode->next = newnode;
}

//删除对应的结点
void deleteList(LinkList * HeadNode,int index, int * DataToDel){
    LinkList* tempNode;
    LinkList* currentNode = HeadNode;
    int i = 1;
    while (currentNode && i< index-1) {
        currentNode = currentNode->next;
        i++;
    }
    tempNode = currentNode->next;
    currentNode->next = tempNode->next;
//    free(tempNode);
}

//获取链表长度
int getListLength(LinkList *HeadNode)
{
    int listLength = 0;
    LinkList* currentNode = HeadNode;
    while (currentNode) {
        listLength++;
        currentNode = currentNode->next;
    }
    return listLength;
}

int getDataIndex(LinkList* headNode,int value){
    
    LinkList* currentNode = headNode;
    int i = -1;
    int targetIndex = 0;
    while ( i != -1) {
        if (currentNode->Element == value) {
            i= 0;
        }
        targetIndex++;
        currentNode = currentNode->next;
    }
    return targetIndex;
}

int destorylinkList(LinkList* list){
    LinkList* currentNode = list;
    LinkList* tempList;
    while (currentNode) {
        tempList = currentNode;
//        free(currentNode);
        currentNode = tempList->next;
    }
    list->next = NULL;
    return 1;
}

//反转链表
LinkList* rotateLinkList(LinkList* list){
    LinkList* prelist,*currentList,*NextList;
    prelist = malloc(sizeof(LinkList));
    currentList = list;
    prelist->next = currentList;
    while (currentList->next) {
        NextList = currentList->next;
        currentList->next = NextList->next;
        NextList->next = prelist->next;
        prelist->next = NextList;
    }
    return prelist->next;
//    https://blog.csdn.net/u012531536/article/details/80170893
}

//判断链表是否有环
/***
 判断链表是否存在环的过程中，通常最先想到的方法就是从定义下手，有环的话就没有尾结点，也就是说不存在一个结点的next指针是null。通过这种思路可以对有环无环进行判定，但需要判定到何时呢？
 
 当遍历了4000个结点都没有遇到null结点，难道就可以断定这就是一个有环的链表吗？如果它的第4001个结点就是尾结点呢？很多情况下，我们是不知道链表的长度的，所以我们很难确定需要判定到哪一个结点才能确定链表是否为环形链表。因此我们需要借助快指针、慢指针的概念，这是目前用来判断链表内有环无环的最通用有效的方法。
 
 假设有这样一种情况，有两辆车，一辆车每秒钟可以跑n米，另外一辆速度要快一些，每秒能跑2n米，这两辆车都匀速运行。如果在一个没有交叉点的跑道上，这时跑道上有一个终点，快车和慢车同时在起始点相遇出发之后，一直到终点，快车和慢车的距离只会越拉越大，等到快车到达终点的时候，两者之间的距离差最大。假想一种情况，如果跑道的终点与起始点连接了起来，虽然说从慢车的角度看，快车在前方越来越远。但快车的角度看，慢车在后面越来越远，但在前面看的话确实越来越近。所以在一个环形的跑道上，快车终究会有第二次与慢车相遇，此时正好超车一圈。
 ---------------------
 作者：zql_3393089
 来源：CSDN
 原文：https://blog.csdn.net/u012531536/article/details/80170893
 版权声明：本文为博主原创文章，转载请附上博文链接！
 */
//bool isThereCircle(LinkList* headList){
//    LinkList* fastList,*slowList;
//    fastList = slowList = headList;
//    while (fastList&& slowList) {
//        slowList = slowList->next;
//        if (fastList->next) {
//            fastList = fastList->next->next;
//        }else{
//            fastList = fastList->next;
//        }
//        if (fastList == slowList) {
//            return true;
//        }
//    }
//    return false;
//}

/*
input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
LinkList* solution(LinkList* list1,LinkList*list2){
    LinkList* dumy = list_init(-1);
    LinkList* curl = dumy;
    int carry = 0;
    while (list1&& list2) {
        int v1 = list1->Element?list1->Element:0;
        int v2 = list2->Element?list2->Element:0;
        int sum = v1 + v2 + carry;
        curl->next = list_init(sum%10);
        carry = sum/10;
        list1 = list1->next;
        list2 = list2->next;
    }
    if (carry) {
        curl->next = list_init(1);
    }
    return dumy->next;
}

//hashmap
//https://www.cnblogs.com/chengxiao/p/6059914.html

/**
 Reverse digits of an integer.
 
 Example1: x = 123, return 321
 Example2: x = -123, return -321
 */
int reverse (int x){
    int res = 0;
    while (x != 0) {
//        if (abs(res)>(INT_MAX/10)) {
//            return 0;}
        res = res*10 + x%10;
        x = x/10;
    }
    return res;
}


/**
 描述：判断是不是回文数字，从头到尾，和从尾到头一样。
 121 14441
 */
//bool isciclenumber(int)number{
//    int div = 1;
//    while(number/div (>=) 10){
//        div *= 10;
//    }
//    while(number>0){
//        int left = number/div;
//        int right = number % 10;
//        if(left != right) return false;
//        x = (x%div) /10;
//        div /= 100;
//    }
//    return true;
//}

//快速排序         int a[10] = {6,1,2,7,9,3,4,5,11,9};

//https://www.cnblogs.com/menglong1108/p/11749616.html
void fastSort(int array[],int l,int r){
    int left,right,flag,temp;
    if (l >= r) {

        return ;
    }
    left = l;
    right = r;
    flag = array[l];
    while ( left< right) {
        //先从右侧找
        while (array[right] >= flag && left< right) {
            right -- ;
        }
        //从左侧
         while (array[left] <= flag && left< right) {
            left ++ ;
        }
         
        //交换
        if (left< right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
        
    }
    //把基准值放中间
    array [l] = array[left];
    array[left]= flag;
    // 分别递归
    fastSort(array, l, left - 1);
    fastSort(array, left + 1, r);
}

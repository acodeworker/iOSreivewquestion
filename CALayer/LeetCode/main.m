//
//  main.m
//  LeetCode
//
//  Created by Jeremy on 2019/3/20.
//  Copyright © 2019 Jeremy. All rights reserved.
//

#import "Leetcode.h"
#import "Linklist.h"

struct Books
{
    char title[50];
    char author[50];
    char suject[50];
    int book_id;
};

 


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        int a[10] = {9,12,31,91,4,1,2,8,5,0};
//        sizeof(a)/sizeof(int)
        sortArray(a);
        
        int array[10] = {6,1,2,7,9,3,4,5,11,9};
        fastSort(array, 0, 9);
        for (int i =0; i< 10; i++) {
           printf("%d\n",a[i]);
        }
      }
}

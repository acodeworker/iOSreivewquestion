//
//  main.m
//  LeetCode
//
//  Created by Jeremy on 2019/3/20.
//  Copyright © 2019 Jeremy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Leetcode.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...

//    NSLog(@"%@", [Leetcode inputArray:@[@(2),@(7),@(11),@(15)] target:22]);
    
     NSLog(@"%@", [Leetcode iputString:@"abcabcbb"]);
        char greeting[] = "hello\n";
        char greeting2[] = "helloddd\n";

        printf("%p",strchr(greeting2, 'l'));
        printf("%p",strchr(greeting2, 'l'));
        printf("%p",strchr(greeting2, 'l'));
        printf("%p",strchr(greeting2, 'l'));

         printf("%p",strchr(greeting2, 'l'));
     }
    return 0;
}


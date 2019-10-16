//
//  main.m
//  LeetCode
//
//  Created by Jeremy on 2019/3/20.
//  Copyright © 2019 Jeremy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Leetcode.h"

struct Books
{
    char title[50];
    char author[50];
    char suject[50];
    int book_id;
};

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...

//    NSLog(@"%@", [Leetcode inputArray:@[@(2),@(7),@(11),@(15)] target:22]);
    
//     NSLog(@"%@", [Leetcode iputString:@"abcabcbb"]);
        FILE *fp = NULL;
        
        fp = fopen("/Users/jeremy/Desktop/test.txt", "r+");
//        fprintf(fp, "This is testing for fprintf...\n");
//        fputs("This is testing for fputs...\n", fp);
//        fclose(fp);
         char buff[255];
        

        fprintf(fp, "This is testing for fprintf...\n");
        fseek(fp, 10, SEEK_SET);
        if (fputc(65,fp) == EOF) {
            printf("fputc fail");
        }
        fgets(buff, 255, (FILE*)fp);
        printf("2: %s\n", buff );
        

        fclose(fp);
        
     }
    return 0;
}


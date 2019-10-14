//
//  ViewController.m
//  CALayer
//
//  Created by JeremyLu on 2018/3/17.
//  Copyright © 2018年 JeremyLu. All rights reserved.
//

#import "ViewController.h"
#define WIDTH 50

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
   NSLog(@"%@", [self inputArray:@[@(2),@(7),@(11),@(15)] target:9]);
}

//算法题目：

/**
 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
 
 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
 
 示例:
 
 给定 nums = [2, 7, 11, 15], target = 9
 
 因为 nums[0] + nums[1] = 2 + 7 = 9
 所以返回 [0, 1]
 */
- (NSArray*)inputArray:(NSArray*)sourceArray target:(NSInteger)target{
    NSMutableDictionary* dic = [NSMutableDictionary dictionaryWithCapacity:sourceArray.count];
    for (int i = 0; i<sourceArray.count; i++) {
        NSNumber* num = sourceArray[i];
        [dic setObject:@(i) forKey:num];
    }
    for (int i = 0; i<sourceArray.count; i++) {
        NSInteger num = target - [sourceArray[i] integerValue];
        if ([dic objectForKey:@(num)]) {//找到了
            NSNumber* index = [dic objectForKey:@(num)];
            return @[index, @(i)];
        };
     }
    
    return @[];
}



#pragma mark 绘制图层
-(void)drawMyLayer{
    CGSize size=[UIScreen mainScreen].bounds.size;
    
    //获得根图层
    CALayer *layer=[[CALayer alloc]init];
    //设置背景颜色,由于QuartzCore是跨平台框架，无法直接使用UIColor
    layer.backgroundColor=[UIColor colorWithRed:0 green:146/255.0 blue:1.0 alpha:1.0].CGColor;
    //设置中心点
    layer.position = CGPointMake(size.width/2, size.height/2);
    //设置大小
    layer.bounds = CGRectMake(0, 0, WIDTH,WIDTH);
    //设置圆角,当圆角半径等于矩形的一半时看起来就是一个圆形
    layer.cornerRadius=WIDTH/2;
    //设置阴影
    layer.shadowColor=[UIColor grayColor].CGColor;
    layer.shadowOffset=CGSizeMake(2, 2);
    layer.shadowOpacity=.9;
    //设置边框
    //    layer.borderColor=[UIColor whiteColor].CGColor;
    //    layer.borderWidth=1;
    
    //设置锚点
    //    layer.anchorPoint=CGPointZero;
    
    [self.view.layer addSublayer:layer];
    
}

#pragma mark 点击放大
-(void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event{
    UITouch *touch=[touches anyObject];
    CALayer *layer=self.view.layer.sublayers[0];
    CGFloat width=layer.bounds.size.width;
    if (width==WIDTH) {
        width=WIDTH*4;
    }else{
        width=WIDTH;
    }
    layer.bounds=CGRectMake(0, 0, width, width);
    layer.position=[touch locationInView:self.view];
    layer.cornerRadius=width/2;
}

@end

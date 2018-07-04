//
//  NSString+MD5.h
//  IPHttpRequestManager
//
//  Created by Mac on 2018/7/4.
//  Copyright © 2018年 Mac. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (MD5)

// MD5加密
+ (NSString *)md5HexDigest:(NSString *)str;

// 根据参数生成sign
+ (NSString *)signByParameters:(NSDictionary *)parmters;
+ (NSString *)signByParameters:(NSDictionary *)paramters unixTime:(NSTimeInterval)unixTime;


@end

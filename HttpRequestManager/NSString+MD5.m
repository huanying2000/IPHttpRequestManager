//
//  NSString+MD5.m
//  IPHttpRequestManager
//
//  Created by Mac on 2018/7/4.
//  Copyright © 2018年 Mac. All rights reserved.
//

#import <CommonCrypto/CommonDigest.h>
#import "NSString+MD5.h"
#import <UIKit/UIKit.h>




static NSString *const key = @"inpark07";


@implementation NSString (MD5)

+ (NSString *)md5HexDigest:(NSString *)str {
    const char *cStr = [str UTF8String];
    unsigned char result[16];
    CC_MD5(cStr, strlen(cStr), result);
    return [NSString stringWithFormat:
            @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
            result[0], result[1], result[2], result[3],
            result[4], result[5], result[6], result[7],
            result[8], result[9], result[10], result[11],
            result[12], result[13], result[14], result[15]
            ];
}


+ (NSString *)signByParameters:(NSDictionary *)parmters {
    return [self signByParameters:parmters unixTime:[[NSDate date] timeIntervalSince1970]];
}

+(NSString *)signByParameters:(NSDictionary *)paramters unixTime:(NSTimeInterval)unixTime {
    NSLog(@"upload data 上传参数  %@",paramters);
    NSMutableDictionary *mutableDictionary = [paramters mutableCopy];
    mutableDictionary[@"timePoint"] = @(unixTime).stringValue;
    NSArray *newArray = [[mutableDictionary allKeys] sortedArrayUsingSelector:@selector(compare:)];
    NSMutableArray *urlArray = [NSMutableArray array];
    for (NSInteger i = 0; i < newArray.count; i ++) {
        NSString *value = mutableDictionary[newArray[i]];
        value = [value stringByAddingPercentEncodingWithAllowedCharacters:[[NSCharacterSet characterSetWithCharactersInString:@"!*'\"{}();:@&=+$,/?%#[]%^ "] invertedSet]];
        value = [value stringByReplacingOccurrencesOfString:@"%20" withString:@"+"];
        value = [value stringByReplacingOccurrencesOfString:@"\n" withString:@"%0A"];
        NSString *string = [NSString stringWithFormat:@"%@=\"%@\"",newArray[i],value];
        [urlArray addObject:string];
    }
    NSString *retrunString = [urlArray componentsJoinedByString:@"&"];
    NSLog(@"嘿嘿嘿  %@",retrunString);
    NSLog(@"处理过的参数%@",[self md5HexDigest: [retrunString stringByAppendingString:key]]);
     return [self md5HexDigest: [retrunString stringByAppendingString:key]];
}

@end

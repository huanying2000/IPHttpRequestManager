//
//  IPNetWorkCache.m
//  IPHttpRequestManager
//
//  Created by Mac on 2018/7/4.
//  Copyright © 2018年 Mac. All rights reserved.
//  缓存类

#import "IPNetWorkCache.h"

static NSString *const IPNetworkResponseCache = @"IPNetworkResponseCache";

@implementation IPNetWorkCache

static YYCache *_dataCache;

+ (void) initialize {
    _dataCache = [YYCache cacheWithName:IPNetworkResponseCache];
}


+ (void)setHttpCache:(id)httpData URL:(NSString *)URL parameters:(id)parameters {
    NSString *cacheKey = [self cacheKeyWithURL:URL parameters:parameters];
    //异步缓存 不会阻塞线程
    [_dataCache setObject:httpData forKey:cacheKey];
}

//取出数据
+ (id) httpCacheForURL:(NSString *)URL parameters:(id)parameters {
    NSString *cacheKey = [self cacheKeyWithURL:URL parameters:parameters];
    return [_dataCache objectForKey:cacheKey];
}

//缓存的大小
+ (NSInteger)getAllHttpCacheSize {
    return [_dataCache.diskCache totalCost];
}

+ (void)removeAllHttpCache {
    [_dataCache.diskCache removeAllObjects];
}


//制作缓存的key
+ (NSString *)cacheKeyWithURL:(NSString *)URL parameters:(NSDictionary *)parameters {
    if (!parameters || parameters.count == 0) {
        return URL;
    }
    //将参数字典转换成字符串
    NSData *stringData = [NSJSONSerialization dataWithJSONObject:parameters options:0 error:nil];
    NSString *paraString = [[NSString alloc] initWithData:stringData encoding:NSUTF8StringEncoding];
    return [NSString stringWithFormat:@"%@%@",URL,paraString];
}


@end

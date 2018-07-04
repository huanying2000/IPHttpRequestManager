//
//  IPNetWorkCache.h
//  IPHttpRequestManager
//
//  Created by Mac on 2018/7/4.
//  Copyright © 2018年 Mac. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<YYCache/YYCache.h>)
#import <YYCache/YYCache.h>
#else
#import "YYCache.h"
#endif


//过期提醒
#define IPDeprecated(instead) NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, instead)

#pragma mark - 网络缓存数据类

@interface IPNetWorkCache : NSObject

/**
 *  异步缓存网络数据,根据请求的 URL与parameters
 *  做KEY存储数据, 这样就能缓存多级页面的数据
 *
 *  @param httpData   服务器返回的数据
 *  @param URL        请求的URL地址
 *  @param parameters 请求的参数
 */
+ (void) setHttpCache:(id)httpData URL:(NSString *)URL parameters:(id)parameters;


/**
 *  根据请求的 URL与parameters 同步取出缓存数据
 *
 *  @param URL        请求的URL
 *  @param parameters 请求的参数
 *
 *  @return 缓存的服务器数据
 */
+ (id)httpCacheForURL:(NSString *)URL parameters:(id)parameters;




//获取网络缓存的总大小 (bytes 字节)
+ (NSInteger) getAllHttpCacheSize;


//删除所有的网络缓存
+ (void) removeAllHttpCache;


@end

//
//  IPNetWorkHelper.h
//  IPHttpRequestManager
//
//  Created by Mac on 2018/7/4.
//  Copyright © 2018年 Mac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IPNetWorkHeader.h"

#if __has_include(<AFNetworking/AFNetworking.h>)
#import <AFNetworking/AFNetworking.h>
#else
#import "AFNetworking.h"
#endif







typedef NS_ENUM(NSUInteger,IPNetworkStatusType) {
    /// 未知网络
    IPNetworkStatusUnknown,
    /// 无网络
    IPNetworkStatusNotReachable,
    /// 手机网络
    IPNetworkStatusReachableViaWWAN,
    /// WIFI网络
    IPNetworkStatusReachableViaWiFi
};

//设置请求的数据格式
typedef NS_ENUM(NSUInteger,IPRequestSerializer) {
    /// 设置响应数据为JSON格式
    IPResponseSerializerJSON,
    /// 设置响应数据为二进制格式
    IPResponseSerializerHTTP
};
//成功
typedef void(^IPHttpRequestSuccess)(id responseObject);
//失败
typedef void(^IPHttpRequestFailed)(NSError *error);
//缓存的Block
typedef void(^IPHttpRequestCache)(id responseCache);
//上传或者下载的进度, Progress.completedUnitCount:当前大小 - Progress.totalUnitCount:总大小
typedef void (^IPHttpProgress)(NSProgress *progress);
//网络状态的Block
typedef void(^IPNetworkStatus)(IPNetworkStatusType status);


@interface IPNetWorkHelper : NSObject

/// 有网YES, 无网:NO
+ (BOOL)isNetwork;
/// 手机网络:YES, 反之:NO
+ (BOOL)isWWANNetwork;
/// WiFi网络:YES, 反之:NO
+ (BOOL)isWiFiNetwork;
/// 取消所有HTTP请求
+ (void)cancelAllRequest;
/// 实时获取网络状态,通过Block回调实时获取(此方法可多次调用)
+ (void)networkStatusWithBlock:(IPNetworkStatus)networkStatus;
/// 取消指定URL的HTTP请求
+ (void)cancelRequestWithURL:(NSString *)URL;


/**
 *  GET请求,无缓存
 *
 *  @param URL        请求地址
 *  @param parameters 请求参数
 *  @param success    请求成功的回调
 *  @param failure    请求失败的回调
 *
 *  @return 返回的对象可取消请求,调用cancel方法
 */
+ (__kindof NSURLSessionTask *)GET:(NSString *)URL
                        parameters:(id)parameters
                           success:(IPHttpRequestSuccess)success
                           failure:(IPHttpRequestFailed)failure;


/**
 *  GET请求,自动缓存
 *
 *  @param URL           请求地址
 *  @param parameters    请求参数
 *  @param responseCache 缓存数据的回调
 *  @param success       请求成功的回调
 *  @param failure       请求失败的回调
 *
 *  @return 返回的对象可取消请求,调用cancel方法
 */
+ (__kindof NSURLSessionTask *)GET:(NSString *)URL
                        parameters:(id)parameters
                     responseCache:(IPHttpRequestCache)responseCache
                           success:(IPHttpRequestSuccess)success
                           failure:(IPHttpRequestFailed)failure;





/**
 *  POST请求,无缓存
 *  @return 返回的对象可取消请求,调用cancel方法
 */
+ (__kindof NSURLSessionTask *)POST:(NSString *)URL
                         parameters:(id)parameters
                            success:(IPHttpRequestSuccess)success
                            failure:(IPHttpRequestFailed)failure;





/**
 *  POST请求,自动缓存
 *  @return 返回的对象可取消请求,调用cancel方法
 */
+ (__kindof NSURLSessionTask *)POST:(NSString *)URL
                         parameters:(id)parameters
                      responseCache:(IPHttpRequestCache)responseCache
                            success:(IPHttpRequestSuccess)success
                            failure:(IPHttpRequestFailed)failure;



/**
 *  上传文件
 *  @return 返回的对象可取消请求,调用cancel方法
 */
+ (__kindof NSURLSessionTask *)uploadFileWithURL:(NSString *)URL
                                      parameters:(id)parameters
                                            name:(NSString *)name
                                        filePath:(NSString *)filePath
                                        progress:(IPHttpProgress)progress
                                         success:(IPHttpRequestSuccess)success
                                         failure:(IPHttpRequestFailed)failure;


/**
 *  上传单/多张图片
 *
 *  @param URL        请求地址
 *  @param parameters 请求参数
 *  @param name       图片对应服务器上的字段
 *  @param images     图片数组
 *  @param fileNames  图片文件名数组, 可以为nil, 数组内的文件名默认为当前日期时间"yyyyMMddHHmmss"
 *  @param imageScale 图片文件压缩比 范围 (0.f ~ 1.f)
 *  @param imageType  图片文件的类型,例:png、jpg(默认类型)....
 *  @param progress   上传进度信息
 *  @param success    请求成功的回调
 *  @param failure    请求失败的回调
 *
 *  @return 返回的对象可取消请求,调用cancel方法
 */
+ (__kindof NSURLSessionTask *)uploadImagesWithURL:(NSString *)URL
                                        parameters:(id)parameters
                                              name:(NSString *)name
                                            images:(NSArray<UIImage *> *)images
                                         fileNames:(NSArray<NSString *> *)fileNames
                                        imageScale:(CGFloat)imageScale
                                         imageType:(NSString *)imageType
                                          progress:(IPHttpProgress)progress
                                           success:(IPHttpRequestSuccess)success
                                           failure:(IPHttpRequestFailed)failure;



/**
 *  下载文件
 *
 *  @param URL      请求地址
 *  @param fileDir  文件存储目录(默认存储目录为Download)
 *  @param progress 文件下载的进度信息
 *  @param success  下载成功的回调(回调参数filePath:文件的路径)
 *  @param failure  下载失败的回调
 *
 *  @return 返回NSURLSessionDownloadTask实例，可用于暂停继续，暂停调用suspend方法，开始下载调用resume方法
 */
+ (__kindof NSURLSessionTask *)downloadWithURL:(NSString *)URL
                                       fileDir:(NSString *)fileDir
                                      progress:(IPHttpProgress)progress
                                       success:(void(^)(NSString *filePath))success
                                       failure:(IPHttpRequestFailed)failure;


@end

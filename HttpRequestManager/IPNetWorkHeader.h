//
//  IPNetWorkHeader.h
//  IPHttpRequestManager
//
//  Created by Mac on 2018/7/4.
//  Copyright © 2018年 Mac. All rights reserved.
//

#ifndef IPNetWorkHeader_h
#define IPNetWorkHeader_h
#import <Foundation/Foundation.h>
#import "IPNetWorkHelper.h"
#import "IPNetWorkCache.h"
#import "NSString+MD5.h"


#ifdef DEBUG

#define NSLog( s, ... ) printf("class: <%p %s:(%d) > method: %s \n%s\n", self, [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __PRETTY_FUNCTION__, [[NSString stringWithFormat:(s), ##__VA_ARGS__] UTF8String] );

#else

#define NSLog( s, ... )

#endif

#ifdef DEBUG

#define IPBaseUrl  @"http://servi.in-park.cn/test/easily_inpark"
#define IPBaseImageUrl  @"http://servi.in-park.cn"
//#define IPQuqry = @"test/easily_inpark";

#else

#define IPBaseUrl IPBaseUrl  @"http://servi.in-park.cn/client_new/easily_inpark"
#define IPBaseImageUrl IPBaseImageUrl  @"http://servi.in-park.cn"
//#define IPQuqry = @"client_new/easily_inpark";

#endif



#endif /* IPNetWorkHeader_h */

/*
 *
 * Copyright (c) 2015-2020  Bonree Company
 * 北京博睿宏远科技发展有限公司  版权所有 2015-2020
 *
 * PROPRIETARY RIGHTS of Bonree Company are involved in the
 * subject matter of this material.  All manufacturing, reproduction, use,
 * and sales rights pertaining to this subject matter are governed by the
 * license agreement.  The recipient of this software implicitly accepts
 * the terms of the license.
 * 本软件文档资料是博睿公司的资产,任何人士阅读和使用本资料必须获得
 * 相应的书面授权,承担保密责任和接受相应的法律约束.
 *
 */

#import <Foundation/Foundation.h>

//是否捕获crash信息,默认打开
#define BRSOption_Crash         (1 << 0)
//是否打开位置服务,默认关闭
#define BRSOption_Location      (1 << 1)
//是否异步启动.异步启动会加快启动速度,但可能会捕获不到刚启动约150ms的网络数据.默认同步启动
#define BRSOption_AsyncStart    (1 << 2)

@interface BRSAgent : NSObject

//启动bonreeAgent
+ (void)startWithAppID:(NSString*)appid;

//启动bonreeAgent,并指明是否使用位置服务
+ (void)startWithAppID:(NSString*)appId location:(BOOL)locationAllowed;

//启动bonreeAgent,并指定启动概率,如50%的概率启动,rate赋为0.5即可
+ (void)startWithAppID:(NSString*)appId rateOfLaunch:(double)rate;

//启动bonreeAgent,同时指定启动概率和是否使用位置服务
+ (void)startWithAppID:(NSString*)appId location:(BOOL)locationAllowed rateOfLaunch:(double)rate;

//设置是否捕获崩溃日志,默认打开
+ (void) enableCrashReporting:(BOOL)enable;

//设置是否获取位置信息,默认关闭
+ (void)enableLocation:(BOOL)enable;

//设置启动概率,默认100%
+ (void)setRateOfLaunch:(double)rate;

//设置config地址,默认公有云不用设置
+ (void)setConfigAddress:(NSString*)configAddress;

//设置启动选项
+ (void)setOption:(int)option;

//行为数据

//设置下载渠道名称
+ (void)setChannelName:(NSString*)channelName;

//自定义事件
+ (void)trackEvent:(NSString*)eventID name:(NSString*)eventName;

/*
 标记页面开始和结束,这两个接口需要成对调用.
 在viewWillAppear或者viewDidAppear调用trackPageBegin方法
 在viewWillDisappear或者viewDidDisappear调用trackPageEnd方法
 */
+ (void)trackPageBegin:(NSString *)pageId pageName:(NSString *)pageName;
+ (void)trackPageEnd:(NSString *)pageId pageName:(NSString*)pageName;


//设置会员id
+ (void)setMemberId:(NSString *)memberId;

@end

/*
 Example 1:
 最简单的,默认关闭位置服务,默认打开捕获崩溃信息,启动概率为100%,同步启动
 [BRSAgent startWithAppID:@"xxxx"];
 
 Example 2:
 打开位置服务,启动概率为50%
 [BRSAgent startWithAppID:@"xxxx"
                 location:YES
             rateOfLaunch:0.5];
 
 Example 3:
 打开捕获崩溃信息,关闭位置服务,异步启动
 [BRSAgent setOption:BRSOption_Crash|BRSOption_AsyncStart];
 [BRSAgent startWithAppID:@"xxxx"];
*/
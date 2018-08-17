//
//  ViewController.m
//  voteMultiple
//
//  Created by allen du on 2018/8/17.
//  Copyright © 2018年 allen. All rights reserved.
//

#import "ViewController.h"
#import <WebKit/WebKit.h>
#import "GDCAMasonry.h"

@interface ViewController ()
@property (nonatomic,strong) WKWebView *webView;
@property (nonatomic,strong)  UIButton *btn;
@property (assign,nonatomic) int number;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.number = 8062;
    self.number += 1;
    [self weChat];
    
    
}
-(void)weChat
{
    WKWebView *wkWebView = [[WKWebView alloc] initWithFrame:CGRectZero];
    
    [wkWebView evaluateJavaScript:@"navigator.userAgent" completionHandler:^(id result, NSError *error) {
        NSString *newUserAgent = @"mozilla/5.0 (iphone; cpu iphone os 9_1_2 like mac os x) > applewebkit/537.51.2 (khtml, like gecko) mobile/11d257 > micromessenger/6.0.1 nettype/wifi";
        NSDictionary *dictionary = [NSDictionary dictionaryWithObjectsAndKeys:newUserAgent, @"UserAgent", nil];
        [[NSUserDefaults standardUserDefaults] registerDefaults:dictionary];
        
        
        dispatch_async(dispatch_get_main_queue(), ^{
            // 重新初始化WKWebView
            [self createView];
        });
    }];
}
-(void)createView
{
    [self.webView removeFromSuperview];
    WKWebViewConfiguration *configuration = [[WKWebViewConfiguration alloc] init];
    self.webView = [[WKWebView alloc]initWithFrame:CGRectZero configuration:configuration];
    //    self.webView.customUserAgent = @"";
    [self.view addSubview:self.webView];
    [self.webView mas_makeConstraints:^(GDCAMASConstraintMaker *make) {
        make.edges.equalTo(self.view);
    }];
    NSURL *url = [NSURL URLWithString:@"https://file20e5daac6a81.aiwall.com/v3/idea/prNxskKX?page=6&mod=5b5c11732d4b7f1b439b3169_20180813_0f1151977296&from=timeline&isappinstalled=0&suid=C80F45A4-DC86-4194-A118-248711E63E41&sl=3#page=6&mod=5b5c11732d4b7f1b439b3169_20180813_0f1151977296&from=timeline&isappinstalled=0&suid=20180816121041--1221582434-8595&sl=3"];
    [self.webView loadRequest:[NSURLRequest requestWithURL:url]];
    
    [self.btn removeFromSuperview];
    self.btn= [UIButton buttonWithType:UIButtonTypeCustom];
    [self.view addSubview:_btn];
    [_btn mas_makeConstraints:^(GDCAMASConstraintMaker *make) {
        make.bottom.equalTo(self.view);
        make.width.equalTo(@100);
        make.height.equalTo(@40);
        make.centerX.equalTo(self.view);
    }];
    [_btn setTitle:@"刷新" forState:UIControlStateNormal];
    [_btn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [_btn addTarget:self action:@selector(clearCache) forControlEvents:UIControlEventTouchUpInside];
}
-(void)clearCache
{
    [self.webView.configuration.websiteDataStore.httpCookieStore getAllCookies:^(NSArray<NSHTTPCookie *> * _Nonnull arr) {
        for (int i=0; i<arr.count; i++) {
            NSHTTPCookie *cookie = arr[i];
            NSLog(@"cookie name %@  value %@  ",cookie.name,cookie.value);
            if ([cookie.name isEqualToString:@"wx398d72182f69dfe3.id"]||[cookie.name isEqualToString:@"vx.unid"]) {
                NSMutableDictionary *dic = [NSMutableDictionary dictionaryWithDictionary:cookie.properties];
                NSString *p = @"20180817160911--1221582434-";
                self.number += 1;
                
                dic[@"Value"] = [NSString stringWithFormat:@"%@%d",p,self.number];
                NSHTTPCookie *newCookie = [NSHTTPCookie cookieWithProperties:dic];
                NSLog(@"newCookie name %@  value %@  ",newCookie.name,newCookie.value);
                
                [self.webView.configuration.websiteDataStore.httpCookieStore setCookie:newCookie completionHandler:^{
                    [self.webView reload];
                }];
            }
            
        }
    }];
    
    
//    NSSet *websiteDataTypes = [WKWebsiteDataStore allWebsiteDataTypes];
//
//    //// Date from
//
//    NSDate *dateFrom = [NSDate dateWithTimeIntervalSince1970:0];
//
//    //// Execute
//
//
//    [[WKWebsiteDataStore defaultDataStore] removeDataOfTypes:websiteDataTypes modifiedSince:dateFrom completionHandler:^{
//
//        // Done
//        WKWebView *wkWebView = [[WKWebView alloc] initWithFrame:CGRectZero];
//        [wkWebView evaluateJavaScript:@"navigator.userAgent" completionHandler:^(id result, NSError *error) {
//            NSString *newUserAgent = @"mozilla/5.0 (iphone; cpu iphone os 9_1_2 like mac os x) > applewebkit/537.51.2 (khtml, like gecko) mobile/11d257 > nettype/wifi";
//            NSDictionary *dictionary = [NSDictionary dictionaryWithObjectsAndKeys:newUserAgent, @"UserAgent", nil];
//            [[NSUserDefaults standardUserDefaults] registerDefaults:dictionary];
//            [self createView];
//            [self performSelector:@selector(weChat) withObject:nil afterDelay:3];
//        }];
//    }];
    
    
    
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end

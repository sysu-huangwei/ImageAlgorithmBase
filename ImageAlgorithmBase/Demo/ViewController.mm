//
//  ViewController.m
//  Demo
//
//  Created by HW on 2018/11/1.
//  Copyright © 2018 meitu. All rights reserved.
//

#import "ViewController.h"

#import "UIImage+ImageData.h"
#include "ImageLoader.hpp"
#include "PSDissolve.hpp"

@interface ViewController ()
@property (strong, nonatomic) IBOutlet UIImageView *imageView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    NSString* imageAPath = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"Resource/A.jpg"];
    NSString* imageBPath = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"Resource/B.jpg"];
    
    int widthA = 0, heightA = 0;
    int widthB = 0, heightB = 0;
    unsigned char* imageAData = iab::loadImageFromFile([imageAPath UTF8String], widthA, heightA);
    unsigned char* imageBData = iab::loadImageFromFile([imageBPath UTF8String], widthB, heightB);
    
    unsigned char* dissolveData = iab::PSDissolve::Run(imageAData, imageBData, widthA, heightA);
    
    UIImage* dissolveImage = [UIImage imageWithRGBAData:dissolveData withWidth:widthA withHeight:heightA];
    
    [_imageView setImage:resultImage];
    
}


@end

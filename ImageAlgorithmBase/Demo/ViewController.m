//
//  ViewController.m
//  Demo
//
//  Created by HW on 2018/11/1.
//  Copyright © 2018 meitu. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (strong, nonatomic) IBOutlet UIImageView *imageView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    NSString* imageAPath = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"Resource/A.jpg"];
    NSString* imageBPath = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"Resource/B.jpg"];
    UIImage* imageA = [[UIImage alloc] initWithContentsOfFile:imageAPath];
    UIImage* imageB = [[UIImage alloc] initWithContentsOfFile:imageBPath];
    
    [_imageView setImage:imageA];
    
}


@end

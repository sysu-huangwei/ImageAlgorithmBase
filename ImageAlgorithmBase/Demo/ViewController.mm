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
#include "PSDarken.hpp"
#include "PSLighten.hpp"
#include "PSLinearBurn.hpp"
#include "PSLinearDodge.hpp"
#include "PSColorBurn.hpp"
#include "PSColorDodge.hpp"
#include "PSMultiply.hpp"
#include "PSScreen.hpp"
#include "PSOverlay.hpp"
#include "PSSoftLight.hpp"
#include "PSHardLight.hpp"
#include "PSVividLight.hpp"
#include "PSPinLight.hpp"
#include "PSLinearLight.hpp"
#include "PSHardMix.hpp"
#include "PSDarkerColor.hpp"
#include "PSLighterColor.hpp"
#include "PSDifference.hpp"
#include "PSExclusion.hpp"
#include "PSGray.hpp"

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
    
    unsigned char* darkenData = iab::PSDarken::Run(imageAData, imageBData, widthA, heightA);
    UIImage* darkenImage = [UIImage imageWithRGBAData:darkenData withWidth:widthA withHeight:heightA];
    
    unsigned char* lightenData = iab::PSLighten::Run(imageAData, imageBData, widthA, heightA);
    UIImage* lightenImage = [UIImage imageWithRGBAData:lightenData withWidth:widthA withHeight:heightA];
    
    unsigned char* linearBurnData = iab::PSLinearBurn::Run(imageAData, imageBData, widthA, heightA);
    UIImage* linearBurnImage = [UIImage imageWithRGBAData:linearBurnData withWidth:widthA withHeight:heightA];
    
    unsigned char* linearDodgeData = iab::PSLinearDodge::Run(imageAData, imageBData, widthA, heightA);
    UIImage* linearDodgeImage = [UIImage imageWithRGBAData:linearDodgeData withWidth:widthA withHeight:heightA];
    
    unsigned char* colorBurnData = iab::PSColorBurn::Run(imageAData, imageBData, widthA, heightA);
    UIImage* colorBurnImage = [UIImage imageWithRGBAData:colorBurnData withWidth:widthA withHeight:heightA];
    
    unsigned char* colorDodgeData = iab::PSColorDodge::Run(imageAData, imageBData, widthA, heightA);
    UIImage* colorDodgeImage = [UIImage imageWithRGBAData:colorDodgeData withWidth:widthA withHeight:heightA];
    
    unsigned char* multiplyData = iab::PSMultiply::Run(imageAData, imageBData, widthA, heightA);
    UIImage* multiplyImage = [UIImage imageWithRGBAData:multiplyData withWidth:widthA withHeight:heightA];
    
    unsigned char* screenData = iab::PSScreen::Run(imageAData, imageBData, widthA, heightA);
    UIImage* screenImage = [UIImage imageWithRGBAData:screenData withWidth:widthA withHeight:heightA];
    
    unsigned char* softLightData = iab::PSSoftLight::Run(imageAData, imageBData, widthA, heightA);
    UIImage* softLightImage = [UIImage imageWithRGBAData:softLightData withWidth:widthA withHeight:heightA];
    
    unsigned char* hardLightData = iab::PSHardLight::Run(imageAData, imageBData, widthA, heightA);
    UIImage* hardLightImage = [UIImage imageWithRGBAData:hardLightData withWidth:widthA withHeight:heightA];
    
    unsigned char* vividLightData = iab::PSVividLight::Run(imageAData, imageBData, widthA, heightA);
    UIImage* vividLightImage = [UIImage imageWithRGBAData:vividLightData withWidth:widthA withHeight:heightA];
    
    unsigned char* pinLightData = iab::PSPinLight::Run(imageAData, imageBData, widthA, heightA);
    UIImage* pinLightImage = [UIImage imageWithRGBAData:pinLightData withWidth:widthA withHeight:heightA];
    
    unsigned char* linearLightData = iab::PSLinearLight::Run(imageAData, imageBData, widthA, heightA);
    UIImage* linearLightImage = [UIImage imageWithRGBAData:linearLightData withWidth:widthA withHeight:heightA];
    
    unsigned char* hardMixData = iab::PSHardMix::Run(imageAData, imageBData, widthA, heightA);
    UIImage* hardMixImage = [UIImage imageWithRGBAData:hardMixData withWidth:widthA withHeight:heightA];
    
    unsigned char* darkerColorData = iab::PSDarkerColor::Run(imageAData, imageBData, widthA, heightA);
    UIImage* darkerColorImage = [UIImage imageWithRGBAData:darkerColorData withWidth:widthA withHeight:heightA];
    
    unsigned char* lighterColorData = iab::PSLighterColor::Run(imageAData, imageBData, widthA, heightA);
    UIImage* lighterColorImage = [UIImage imageWithRGBAData:lighterColorData withWidth:widthA withHeight:heightA];
    
    unsigned char* differenceData = iab::PSDifference::Run(imageAData, imageBData, widthA, heightA);
    UIImage* differenceImage = [UIImage imageWithRGBAData:differenceData withWidth:widthA withHeight:heightA];
    
    unsigned char* exclusionData = iab::PSExclusion::Run(imageAData, imageBData, widthA, heightA);
    UIImage* exclusionImage = [UIImage imageWithRGBAData:exclusionData withWidth:widthA withHeight:heightA];
    
    unsigned char* grayData = iab::PSGray::Run(imageAData, widthA, heightA);
    UIImage* grayImage = [UIImage imageWithGrayData:grayData withWidth:widthA withHeight:heightA];
    
    [_imageView setImage:grayImage];
    
}


@end

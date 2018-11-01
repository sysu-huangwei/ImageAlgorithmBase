//
//  ImagePublic.h


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#define MT_ALPHALOCATION kCGImageAlphaPremultipliedFirst//ARGB

@interface UIImage (ImageData)


/************************************
 *UIImage数据转换
 ***********************************/
//UIImage to ARGB
- (unsigned char*) ARGBData;//Alpha固定为255
- (unsigned char*) ARGBDataWithWhite;//固定填充白色底
- (unsigned char*) ARGBDataWithAlpha;//Alpha为原始图像的透明度

/**
 *  获取Gray的数据
 *
 *  @return Gray的内存地址，单通道
 */
- (unsigned char*) GrayData;

- (unsigned char*) RGBAData;//Alpha固定为255
- (unsigned char*) RGBADataWithWhite;//固定填充白色底
- (unsigned char*) RGBADataWithAlpha;//Alpha为原始图像的透明度

//ARGB to UIImage
+ (UIImage*) imageWithARGBData:(unsigned char*) data withSize:(CGSize) size;
+ (UIImage*) imageWithARGBData:(unsigned char*)data withWidth:(int) width withHeight:(int) height;

//RGBA to UIImage
+ (UIImage*) imageWithRGBAData:(unsigned char*) data withSize:(CGSize) size;
+ (UIImage*) imageWithRGBAData:(unsigned char*)data withWidth:(int) width withHeight:(int) height;

+ (UIImage*) imageWithGrayData:(unsigned char*) pGrayData width:(int)width height:(int) height;


/*
 *  裁剪
 *  rectCut为裁剪的区域
 */
- (UIImage*) processWithCut:(CGRect) rectCut;

//调整图片方向
- (UIImage *)fixOrientation;

@end

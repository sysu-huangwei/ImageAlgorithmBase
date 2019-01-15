//
//  ImagePublic.m
//  MeituXX
//
//  Created by fu songlin on 12-5-16.
//  Copyright (c) 2012年 Xiamen Meitu Technology Co., Ltd. All rights reserved.
//

#import "UIImage+ImageData.h"

#define BYTE unsigned char
#define MT_RED 0
#define MT_GREEN 0
#define MT_BLUE 0
#define MT_ALPHA 0


@implementation UIImage (ImageData)


- (unsigned char*) GrayData
{
    
    
    long width = CGImageGetWidth(self.CGImage);
    long height = CGImageGetHeight(self.CGImage);
    if(width == 0 || height == 0)
        return 0;
    unsigned char* imageData = (unsigned char *) malloc(width * height);
    
    CGColorSpaceRef cref = CGColorSpaceCreateDeviceGray();
    CGContextRef gc = CGBitmapContextCreate(imageData,
                                            width,height,
                                            8,width,
                                            cref,kCGImageAlphaNone);
    CGColorSpaceRelease(cref);
    UIGraphicsPushContext(gc);
    
    CGRect rect = {{ 0 , 0 }, {(CGFloat)width, (CGFloat)height }};
    CGContextDrawImage( gc, rect, self.CGImage );
    UIGraphicsPopContext();
    CGContextRelease(gc);
    
    
    return imageData;// CGBitmapContextGetData(gc);
}
#pragma mark
#pragma mark UIImage与ARGB数据的转换
- (unsigned char*) RGBAData
{
    long width = CGImageGetWidth(self.CGImage);
    long height = CGImageGetHeight(self.CGImage);
    if(width == 0 || height == 0)
        return 0;
    unsigned char* imageData = (unsigned char *) malloc(4 * width * height);
    
    CGColorSpaceRef cref = CGColorSpaceCreateDeviceRGB();
    CGContextRef gc = CGBitmapContextCreate(imageData,
                                            width,height,
                                            8,width*4,
                                            cref,kCGImageAlphaPremultipliedLast);
    CGColorSpaceRelease(cref);
    UIGraphicsPushContext(gc);
    
    CGRect rect = {{ 0 , 0 }, {(CGFloat)width, (CGFloat)height }};
    CGContextDrawImage( gc, rect, self.CGImage );
    UIGraphicsPopContext();
    CGContextRelease(gc);
    return imageData;
    
}

- (unsigned char*) RGBADataWithWhite
{
    
    
    long width = CGImageGetWidth(self.CGImage);
    long height = CGImageGetHeight(self.CGImage);
    if(width == 0 || height == 0)
        return 0;
    unsigned char* imageData = (unsigned char *) malloc(4 * width * height);
    
    CGColorSpaceRef cref = CGColorSpaceCreateDeviceRGB();
    CGContextRef gc = CGBitmapContextCreate(imageData,
                                            width,height,
                                            8,width*4,
                                            cref,kCGImageAlphaPremultipliedLast);
    CGColorSpaceRelease(cref);
    UIGraphicsPushContext(gc);
    CGContextSetRGBFillColor(gc, 1.0, 1.0, 1.0, 1.0);
    CGContextFillRect(gc, CGRectMake(0.0, 0.0, (CGFloat)width, (CGFloat)height));
    CGRect rect = {{ 0 , 0 }, {(CGFloat)width, (CGFloat)height }};
    CGContextDrawImage( gc, rect, self.CGImage );
    UIGraphicsPopContext();
    CGContextRelease(gc);
    
    
    return imageData;// CGBitmapContextGetData(gc);
}
- (unsigned char*) RGBADataWithAlpha
{
    CGImageAlphaInfo info = CGImageGetAlphaInfo(self.CGImage);
    BOOL hasAlpha = ((info == kCGImageAlphaPremultipliedLast) ||
                     (info == kCGImageAlphaPremultipliedFirst) ||
                     (info == kCGImageAlphaLast) ||
                     (info == kCGImageAlphaFirst) ? YES : NO);
    
    long width = CGImageGetWidth(self.CGImage);
    long height = CGImageGetHeight(self.CGImage);
    if(width == 0 || height == 0)
        return 0;
    unsigned char* imageData = (unsigned char *) malloc(4 * width * height);
    
    CGColorSpaceRef cref = CGColorSpaceCreateDeviceRGB();
    CGContextRef gc = CGBitmapContextCreate(imageData,
                                            width,height,
                                            8,width*4,
                                            cref,kCGImageAlphaPremultipliedLast);
    CGColorSpaceRelease(cref);
    UIGraphicsPushContext(gc);
    
    if (hasAlpha == YES)
    {
        CGContextSetRGBFillColor(gc, 1.0, 1.0, 1.0, 1.0);
        CGContextFillRect(gc, CGRectMake(0.0, 0.0, (CGFloat)width, (CGFloat)height));
    }
    CGRect rect = {{ 0 , 0 }, {(CGFloat)width, (CGFloat)height }};
    CGContextDrawImage( gc, rect, self.CGImage );
    UIGraphicsPopContext();
    CGContextRelease(gc);
    
    
    
    if (hasAlpha == YES)
    {
        BYTE array[256][256] = {0};
        for (int j=1; j<256; j++)
        {
            for (int i=0; i<256; i++)
            {
                array[j][i] = fmin(fmax(0.0f,(j+i-255)*255.0/i+0.5),255.0f);
            }
        }
        GLubyte* alphaData = (GLubyte*) calloc(width * height, sizeof(GLubyte));
        CGContextRef alphaContext = CGBitmapContextCreate(alphaData, width, height, 8, width, NULL, kCGImageAlphaOnly);
        CGContextDrawImage(alphaContext, CGRectMake(0.0, 0.0, (CGFloat)width, (CGFloat)height), self.CGImage);
        // Draw the image into the bitmap context
        CGContextRelease(alphaContext);
        GLubyte* pDest = imageData;
        GLubyte* alphaTemp = alphaData;
        for (int j=0; j<height; j++)
        {
            for (int i=0; i<width; i++)
            {
                
                //自己反计算回原来的alpha值
                pDest[MT_RED] = array[pDest[MT_RED]][alphaTemp[0]];
                pDest[MT_GREEN] = array[pDest[MT_GREEN]][alphaTemp[0]];
                pDest[MT_BLUE] = array[pDest[MT_BLUE]][alphaTemp[0]];
                
                pDest[MT_ALPHA] = alphaTemp[0];
                pDest += 4;
                alphaTemp++;
            }
        }
        free(alphaData);
    }
    
    
    return imageData;// CGBitmapContextGetData(gc);
}



// 返回一个基于c带有图片数据的的bitmap
- (unsigned char*) ARGBData
{
    
    
    long width = CGImageGetWidth(self.CGImage);
    long height = CGImageGetHeight(self.CGImage);
    if(width == 0 || height == 0)
        return 0;
    unsigned char* imageData = (unsigned char *) malloc(4 * width * height);
    
    CGColorSpaceRef cref = CGColorSpaceCreateDeviceRGB();
    CGContextRef gc = CGBitmapContextCreate(imageData,
                                            width,height,
                                            8,width*4,
                                            cref,kCGImageAlphaPremultipliedFirst);
    CGColorSpaceRelease(cref);
    UIGraphicsPushContext(gc);
    
    CGRect rect = {{ 0 , 0 }, {(CGFloat)width, (CGFloat)height }};
    CGContextDrawImage( gc, rect, self.CGImage );
    UIGraphicsPopContext();
    CGContextRelease(gc);
    
    
    return imageData;// CGBitmapContextGetData(gc);
}

- (unsigned char*) ARGBDataWithWhite
{


    long width = CGImageGetWidth(self.CGImage);
    long height = CGImageGetHeight(self.CGImage);
    if(width == 0 || height == 0)
        return 0;
    unsigned char* imageData = (unsigned char *) malloc(4 * width * height);

    CGColorSpaceRef cref = CGColorSpaceCreateDeviceRGB();
    CGContextRef gc = CGBitmapContextCreate(imageData,
                                            width,height,
                                            8,width*4,
                                            cref,kCGImageAlphaPremultipliedFirst);
    CGColorSpaceRelease(cref);
    UIGraphicsPushContext(gc);
    CGContextSetRGBFillColor(gc, 1.0, 1.0, 1.0, 1.0);
    CGContextFillRect(gc, CGRectMake(0.0, 0.0, (CGFloat)width, (CGFloat)height));
    CGRect rect = {{ 0 , 0 }, {(CGFloat)width, (CGFloat)height }};
    CGContextDrawImage( gc, rect, self.CGImage ); 
    UIGraphicsPopContext();
    CGContextRelease(gc);


    return imageData;// CGBitmapContextGetData(gc);
}
- (unsigned char*) ARGBDataWithAlpha
{
    CGImageAlphaInfo info = CGImageGetAlphaInfo(self.CGImage);
    BOOL hasAlpha = ((info == kCGImageAlphaPremultipliedLast) ||
                     (info == kCGImageAlphaPremultipliedFirst) ||
                     (info == kCGImageAlphaLast) ||
                     (info == kCGImageAlphaFirst) ? YES : NO);
    
    long width = CGImageGetWidth(self.CGImage);
    long height = CGImageGetHeight(self.CGImage);
    if(width == 0 || height == 0)
        return 0;
    unsigned char* imageData = (unsigned char *) malloc(4 * width * height);
    
    CGColorSpaceRef cref = CGColorSpaceCreateDeviceRGB();
    CGContextRef gc = CGBitmapContextCreate(imageData,
                                            width,height,
                                            8,width*4,
                                            cref,kCGImageAlphaPremultipliedFirst);
    CGColorSpaceRelease(cref);
    UIGraphicsPushContext(gc);
    
    if (hasAlpha == YES)
    {
        CGContextSetRGBFillColor(gc, 1.0, 1.0, 1.0, 1.0);
        CGContextFillRect(gc, CGRectMake(0.0, 0.0, (CGFloat)width, (CGFloat)height));
    }
    CGRect rect = {{ 0 , 0 }, {(CGFloat)width, (CGFloat)height }};
    CGContextDrawImage( gc, rect, self.CGImage );
    UIGraphicsPopContext();
    CGContextRelease(gc);
    
    
    
    if (hasAlpha == YES)
    {
        BYTE array[256][256] = {0};
        for (int j=1; j<256; j++)
        {
            for (int i=0; i<256; i++)
            {
                array[j][i] = fmin(fmax(0,(j+i-255)*255.0/i+0.5),255);
            }
        }
        GLubyte* alphaData = (GLubyte*) calloc(width * height, sizeof(GLubyte));
        CGContextRef alphaContext = CGBitmapContextCreate(alphaData, width, height, 8, width, NULL, kCGImageAlphaOnly);
        CGContextDrawImage(alphaContext, CGRectMake(0.0, 0.0, (CGFloat)width, (CGFloat)height), self.CGImage);
        // Draw the image into the bitmap context
        CGContextRelease(alphaContext);
        GLubyte* pDest = imageData;
        GLubyte* alphaTemp = alphaData;
        for (int j=0; j<height; j++)
        {
            for (int i=0; i<width; i++)
            {
                
                //自己反计算回原来的alpha值
                pDest[MT_RED] = array[pDest[MT_RED]][alphaTemp[0]];
                pDest[MT_GREEN] = array[pDest[MT_GREEN]][alphaTemp[0]];
                pDest[MT_BLUE] = array[pDest[MT_BLUE]][alphaTemp[0]];
                
                pDest[MT_ALPHA] = alphaTemp[0];
                pDest += 4;
                alphaTemp++;
            }
        }
        free(alphaData);
    }
    
    
    return imageData;// CGBitmapContextGetData(gc);
}

+ (UIImage*) imageWithRGBAData:(unsigned char*)data withWidth:(int) width withHeight:(int) height
{
    // Create a bitmap context with the image data
    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGContextRef context = CGBitmapContextCreate(data, width, height, 8, width*4, colorspace, kCGImageAlphaPremultipliedLast);
    CGImageRef cgImage = nil;
    if (context != nil) {
        cgImage = CGBitmapContextCreateImage (context);
        CGContextRelease(context);
    }
    CGColorSpaceRelease(colorspace);
    
    UIImage * image = nil;
    
    if(cgImage != nil)
        image = [[UIImage alloc] initWithCGImage:cgImage];
    
    // Release the cgImage when done
    CGImageRelease(cgImage);
    return image;
}

+ (UIImage*) imageWithRGBAData:(unsigned char*) data withSize:(CGSize) size
{
    return [self imageWithRGBAData:data withWidth:size.width withHeight:size.height];
}

+ (UIImage*) imageWithARGBData:(unsigned char*)data withWidth:(int) width withHeight:(int) height
{
    // Create a bitmap context with the image data
    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGContextRef context = CGBitmapContextCreate(data, width, height, 8, width*4, colorspace, kCGImageAlphaPremultipliedFirst);
    CGImageRef cgImage = nil;
    if (context != nil) {
        cgImage = CGBitmapContextCreateImage (context);
        CGContextRelease(context);
    }
    CGColorSpaceRelease(colorspace);
    
    UIImage * image = nil;
    
    if(cgImage != nil)
        image = [[UIImage alloc] initWithCGImage:cgImage];
    
    // Release the cgImage when done
    CGImageRelease(cgImage);
    return image;
}

+ (UIImage*) imageWithARGBData:(unsigned char*) data withSize:(CGSize) size
{
    return [self imageWithARGBData:data withWidth:size.width withHeight:size.height];
}

+ (UIImage*) imageWithGrayData:(unsigned char*) pGrayData withWidth:(int)width withHeight:(int) height
{
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceGray();
    CGContextRef context = CGBitmapContextCreate (pGrayData,width,height,8,width,colorSpace,kCGImageAlphaNone);
    CGColorSpaceRelease(colorSpace);
    if (context == NULL) {
        return nil;
    }
    CGImageRef cgImageRef = CGBitmapContextCreateImage(context);
    UIImage *grayImage = [[UIImage alloc] initWithCGImage:cgImageRef];
    CGImageRelease(cgImageRef);
    CGContextRelease(context);
    return grayImage;
}








//裁剪
- (UIImage*) processWithCut:(CGRect) rectCut
{
    CGImageRef imageRefCut = CGImageCreateWithImageInRect(self.CGImage, rectCut);
    //    UIImage*pRetnImage = [[UIImage alloc] initWithCGImage:cgImage];
    UIImage* pRetnImage = [[UIImage alloc] initWithCGImage:imageRefCut];
    CGImageRelease(imageRefCut);
    return pRetnImage;
}

//调整图片方向
- (UIImage *)fixOrientation {
    if (self.imageOrientation ==UIImageOrientationUp) return self;
    CGAffineTransform transform =CGAffineTransformIdentity;
    switch (self.imageOrientation) {
        case UIImageOrientationDown:
        case UIImageOrientationDownMirrored:
            transform = CGAffineTransformTranslate(transform, self.size.width, self.size.height);
            transform = CGAffineTransformRotate(transform,M_PI);
            break;
            
        case UIImageOrientationLeft:
        case UIImageOrientationLeftMirrored:
            transform = CGAffineTransformTranslate(transform, self.size.width,0);
            transform = CGAffineTransformRotate(transform,M_PI_2);
            break;
        case UIImageOrientationRight:
        case UIImageOrientationRightMirrored:
            transform = CGAffineTransformTranslate(transform,0, self.size.height);
            transform = CGAffineTransformRotate(transform, -M_PI_2);
            break;
        case UIImageOrientationUp:
        case UIImageOrientationUpMirrored:
            break;
    }
    switch (self.imageOrientation) {
        case UIImageOrientationUpMirrored:
        case UIImageOrientationDownMirrored:
            transform = CGAffineTransformTranslate(transform, self.size.width,0);
            transform = CGAffineTransformScale(transform, -1,1);
            break;
            
        case UIImageOrientationLeftMirrored:
        case UIImageOrientationRightMirrored:
            transform = CGAffineTransformTranslate(transform, self.size.height,0);
            transform = CGAffineTransformScale(transform, -1,1);
            break;
        case UIImageOrientationUp:
        case UIImageOrientationDown:
        case UIImageOrientationLeft:
        case UIImageOrientationRight:
            break;
    }
    
    CGContextRef ctx =CGBitmapContextCreate(NULL, self.size.width, self.size.height,
                                            CGImageGetBitsPerComponent(self.CGImage),0,
                                            CGImageGetColorSpace(self.CGImage),
                                            CGImageGetBitmapInfo(self.CGImage));
    CGContextConcatCTM(ctx, transform);
    switch (self.imageOrientation) {
        case UIImageOrientationLeft:
        case UIImageOrientationLeftMirrored:
        case UIImageOrientationRight:
        case UIImageOrientationRightMirrored:
            CGContextDrawImage(ctx,CGRectMake(0,0,self.size.height,self.size.width), self.CGImage);
            break;
            
        default:
            CGContextDrawImage(ctx,CGRectMake(0,0,self.size.width,self.size.height), self.CGImage);
            break;
    }
    
    CGImageRef cgimg =CGBitmapContextCreateImage(ctx);
    UIImage *img = [UIImage imageWithCGImage:cgimg];
    CGContextRelease(ctx);
    CGImageRelease(cgimg);
    return img;
}

@end

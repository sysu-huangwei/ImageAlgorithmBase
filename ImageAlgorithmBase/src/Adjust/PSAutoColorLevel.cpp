//
//  PSAutoColorLevel.cpp
//  ImageAlgorithmBase
//
//  Created by HW on 2019/1/17.
//  Copyright © 2019 meitu. All rights reserved.
//

#include "PSAutoColorLevel.hpp"
#include "PSDefine.hpp"

namespace iab {
    
    unsigned char* PSAutoColorLevel::Run(unsigned char* image, int width, int height, int channel, float lowCut, float highCut) {
        
        //结果数据
        unsigned char* result = nullptr;
        
        if (image != nullptr  &&  width > 0  &&  height > 0) {
            int pixelsCount = width * height;
            result = new unsigned char[pixelsCount * channel];
            
            unsigned char* pImage = image;
            unsigned char* pResult = result;
            
            int histRed[256] = {0};
            int histGreen[256] = {0};
            int histBlue[256] = {0};
            
            //统计直方图
            for (int i = 0; i < pixelsCount; i++) {
                if (channel == 4  ||  channel == 3) {
                    histRed[pImage[PS_RED]]++;
                    histGreen[pImage[PS_GREEN]]++;
                    histBlue[pImage[PS_BLUE]]++;
                }
                else if (channel == 1) {
                    histRed[pImage[PS_RED]]++;
                }
                
                pImage += channel;
                pResult += channel;
            }
            
            int minRed = 0, minGreen = 0, minBlue = 0;
            int maxRed = 0, maxGreen = 0, maxBlue = 0;
            //计算红色分量下限
            int sum = 0;
            for (int i = 0; i < 256; i++) {
                sum += histRed[i];
                if (sum >= pixelsCount * lowCut * 0.01) {
                    minRed = i;
                    break;
                }
            }
            //计算绿色分量下限
            sum = 0;
            for (int i = 0; i < 256; i++) {
                sum += histGreen[i];
                if (sum >= pixelsCount * lowCut * 0.01) {
                    minGreen = i;
                    break;
                }
            }
            //计算蓝色分量下限
            sum = 0;
            for (int i = 0; i < 256; i++) {
                sum += histBlue[i];
                if (sum >= pixelsCount * lowCut * 0.01) {
                    minBlue = i;
                    break;
                }
            }
            //计算红色分量上限
            sum = 0;
            for (int i = 255; i >= 0; i--) {
                sum += histRed[i];
                if (sum >= pixelsCount * highCut * 0.01) {
                    maxRed = i;
                    break;
                }
            }
            //计算绿色分量上限
            sum = 0;
            for (int i = 255; i >= 0; i--) {
                sum += histGreen[i];
                if (sum >= pixelsCount * highCut * 0.01) {
                    maxGreen = i;
                    break;
                }
            }
            //计算蓝色分量上限
            sum = 0;
            for (int i = 255; i >= 0; i--) {
                sum += histBlue[i];
                if (sum >= pixelsCount * highCut * 0.01) {
                    maxBlue = i;
                    break;
                }
            }
            
            //颜色映射表
            unsigned char redMap[256] = {0};
            unsigned char greenMap[256] = {0};
            unsigned char blueMap[256] = {0};
            for (int i = 0; i < 256; i++) {
                
                if (i <= minRed)
                    redMap[i] = 0;
                else if (i >= maxRed)
                    redMap[i] = 255;
                else
                    redMap[i] = maxRed - minRed == 0 ? i : 255.0 * (i - minRed) / (maxRed - minRed);
                
                if (i <= minGreen)
                    greenMap[i] = 0;
                else if (i >= maxGreen)
                    greenMap[i] = 255;
                else
                    greenMap[i] = maxGreen - minGreen == 0 ? i : 255.0 * (i - minGreen) / (maxGreen - minGreen);
                
                if (i <= minBlue)
                    blueMap[i] = 0;
                else if (i >= maxBlue)
                    blueMap[i] = 255;
                else
                    blueMap[i] = maxBlue - minBlue == 0 ? i : 255.0 * (i - minBlue) / (maxBlue - minBlue);
            }
            
            //对各通道数据进行映射
            pImage = image;
            pResult = result;
            for (int i = 0; i < pixelsCount; i++) {
                if (channel == 4) {
                    pResult[PS_RED] = redMap[pImage[PS_RED]];
                    pResult[PS_GREEN] = greenMap[pImage[PS_GREEN]];
                    pResult[PS_BLUE] = blueMap[pImage[PS_BLUE]];
                    pResult[PS_ALPHA] = pImage[PS_ALPHA];
                }
                else if (channel == 3) {
                    pResult[PS_RED] = redMap[pImage[PS_RED]];
                    pResult[PS_GREEN] = greenMap[pImage[PS_GREEN]];
                    pResult[PS_BLUE] = blueMap[pImage[PS_BLUE]];
                }
                else if (channel == 1) {
                    pResult[PS_RED] = redMap[pImage[PS_RED]];
                }
                
                pImage += channel;
                pResult += channel;
            }
        }
        
        return result;
    }
    
}

//
//  PSGray.cpp
//  ImageAlgorithmBase
//
//  Created by HW on 2019/1/15.
//  Copyright © 2019 meitu. All rights reserved.
//

#include "PSGray.hpp"
#include "PSDefine.hpp"

namespace iab {
    
    unsigned char* PSGray::Run(unsigned char* image, int width, int height, int channel) {
        
        //结果数据
        unsigned char* result = nullptr;
        
        if (image != nullptr  &&  width > 0  &&  height > 0) {
            int pixelsCount = width * height;
            result = new unsigned char[pixelsCount];
            
            unsigned char* pImage = image;
            unsigned char* pResult = result;
            
            //默认的单色及复色比率为
            const float Color_Ratio_Red = 0.4f;      //红色
            const float Color_Ratio_Green = 0.4f;    //绿色
            const float Color_Ratio_Blue = 0.2f;     //蓝色
            const float Color_Ratio_Yellow = 0.6f;   //黄色（红+绿）
            const float Color_Ratio_Cyan = 0.6f;     //青色（蓝+绿）
            const float Color_Ratio_Magenta = 0.8f;  //紫色（红+蓝）
            
            for (int i = 0; i < pixelsCount; i++) {
                if (channel == 4  ||  channel == 3) {
                    unsigned char max, min, mid;
                    if (pImage[PS_RED] > pImage[PS_GREEN]) {
                        if (pImage[PS_BLUE] > pImage[PS_RED]) {
                            max = pImage[PS_BLUE];
                            mid = pImage[PS_RED];
                            min = pImage[PS_GREEN];
                            pResult[PS_RED] = (max - mid) * Color_Ratio_Blue + (mid - min) * Color_Ratio_Magenta + min;
                        }
                        else if (pImage[PS_GREEN] > pImage[PS_BLUE]) {
                            max = pImage[PS_RED];
                            mid = pImage[PS_GREEN];
                            min = pImage[PS_BLUE];
                            pResult[PS_RED] = (max - mid) * Color_Ratio_Red + (mid - min) * Color_Ratio_Yellow + min;
                        }
                        else {
                            max = pImage[PS_RED];
                            mid = pImage[PS_BLUE];
                            min = pImage[PS_GREEN];
                            pResult[PS_RED] = (max - mid) * Color_Ratio_Red + (mid - min) * Color_Ratio_Magenta + min;
                        }
                    }
                    else {
                        if (pImage[PS_BLUE] > pImage[PS_GREEN]) {
                            max = pImage[PS_BLUE];
                            mid = pImage[PS_GREEN];
                            min = pImage[PS_RED];
                            pResult[PS_RED] = (max - mid) * Color_Ratio_Blue + (mid - min) * Color_Ratio_Cyan + min;
                        }
                        else if (pImage[PS_RED] > pImage[PS_BLUE]) {
                            max = pImage[PS_GREEN];
                            mid = pImage[PS_RED];
                            min = pImage[PS_BLUE];
                            pResult[PS_RED] = (max - mid) * Color_Ratio_Green + (mid - min) * Color_Ratio_Yellow + min;
                        }
                        else {
                            max = pImage[PS_GREEN];
                            mid = pImage[PS_BLUE];
                            min = pImage[PS_RED];
                            pResult[PS_RED] = (max - mid) * Color_Ratio_Green + (mid - min) * Color_Ratio_Cyan + min;
                        }
                    }
                    
                }
                else if (channel == 1) {
                    pResult[PS_RED] = pImage[PS_RED];
                }
                pImage += channel;
                pResult += 1;
            }
        }
        
        return result;
    }
    
}

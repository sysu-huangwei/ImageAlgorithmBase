//
//  PSDissolve.cpp
//  ImageAlgorithmBase
//
//  Created by HW on 2018/11/1.
//  Copyright © 2018 meitu. All rights reserved.
//

#include "PSDissolve.hpp"
#include "PSDefine.hpp"
#include <cstdlib>
#include <ctime>

namespace iab {
    
    unsigned char* PSDissolve::Run(unsigned char* imageA, unsigned char* imageB, int width, int height, int channel) {
        //重置随机数表
        srand((int)time(0));
        
        //结果数据
        unsigned char* result = nullptr;
        
        if (imageA != nullptr  &&  imageB != nullptr  &&  width > 0  &&  height > 0) {
            int pixelsCount = width * height;
            result = new unsigned char[pixelsCount * channel];
            
            unsigned char* pA = imageA;
            unsigned char* pB = imageB;
            unsigned char* pResult = result;
            
            //对每个像素取上层或取下层像素
            for (int i = 0; i < pixelsCount; i++) {
                int randomNumber = rand() % 2;
                if (channel == 4) {
                    pResult[PS_RED] = randomNumber ? pA[PS_RED] : pB[PS_RED];
                    pResult[PS_GREEN] = randomNumber ? pA[PS_GREEN] : pB[PS_GREEN];
                    pResult[PS_BLUE] = randomNumber ? pA[PS_BLUE] : pB[PS_BLUE];
                    pResult[PS_ALPHA] = randomNumber ? pA[PS_ALPHA] : pB[PS_ALPHA];
                }
                else if (channel == 3) {
                    pResult[PS_RED] = randomNumber ? pA[PS_RED] : pB[PS_RED];
                    pResult[PS_GREEN] = randomNumber ? pA[PS_GREEN] : pB[PS_GREEN];
                    pResult[PS_BLUE] = randomNumber ? pA[PS_BLUE] : pB[PS_BLUE];
                }
                else if (channel == 1) {
                    pResult[PS_RED] = randomNumber ? pA[PS_RED] : pB[PS_RED];
                }
                pA += channel;
                pB += channel;
                pResult += channel;
            }
        }
        
        return result;
    }
    
}

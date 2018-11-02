//
//  PSSoftLight.cpp
//  ImageAlgorithmBase
//
//  Created by HW on 2018/11/2.
//  Copyright © 2018 meitu. All rights reserved.
//

#include "PSSoftLight.hpp"
#include "PSDefine.hpp"
#include <cmath>

namespace iab {
    
    unsigned char* PSSoftLight::Run(unsigned char* imageA, unsigned char* imageB, int width, int height, int channel) {
        
        //结果数据
        unsigned char* result = nullptr;
        
        if (imageA != nullptr  &&  imageB != nullptr  &&  width > 0  &&  height > 0) {
            int pixelsCount = width * height;
            result = new unsigned char[pixelsCount * channel];
            
            unsigned char* pA = imageA;
            unsigned char* pB = imageB;
            unsigned char* pResult = result;
            
            for (int i = 0; i < pixelsCount; i++) {
                if (channel == 4  ||  channel == 3) {
                    pResult[PS_RED] = pB[PS_RED] <= 128 ? pA[PS_RED] / 128.0 * pB[PS_RED] + pA[PS_RED] / 255.0 * pA[PS_RED] / 255.0 * (255.0 - 2.0 * pB[PS_RED]) : pA[PS_RED] / 128.0 * (255.0 - pB[PS_RED]) + sqrt(pA[PS_RED]/255.0) * (2.0 * pB[PS_RED] - 255.0);
                    pResult[PS_GREEN] = pB[PS_GREEN] <= 128 ? pA[PS_GREEN] / 128.0 * pB[PS_GREEN] + pA[PS_GREEN] / 255.0 * pA[PS_GREEN] / 255.0 * (255.0 - 2.0 * pB[PS_GREEN]) : pA[PS_GREEN] / 128.0 * (255.0 - pB[PS_GREEN]) + sqrt(pA[PS_GREEN]/255.0) * (2.0 * pB[PS_GREEN] - 255.0);
                    pResult[PS_BLUE] = pB[PS_BLUE] <= 128 ? pA[PS_BLUE] / 128.0 * pB[PS_BLUE] + pA[PS_BLUE] / 255.0 * pA[PS_BLUE] / 255.0 * (255.0 - 2.0 * pB[PS_BLUE]) : pA[PS_BLUE] / 128.0 * (255.0 - pB[PS_BLUE]) + sqrt(pA[PS_BLUE]/255.0) * (2.0 * pB[PS_BLUE] - 255.0);
                    if (channel == 4) pResult[PS_ALPHA] = pA[PS_ALPHA];
                }
                else if (channel == 1) {
                    pResult[PS_RED] = pB[PS_RED] <= 128 ? pA[PS_RED] / 128.0 * pB[PS_RED] + pA[PS_RED] / 255.0 * pA[PS_RED] / 255.0 * (255.0 - 2.0 * pB[PS_RED]) : pA[PS_RED] / 128.0 * (255.0 - pB[PS_RED]) + sqrt(pA[PS_RED]/255.0) * (2.0 * pB[PS_RED] - 255.0);
                }
                pA += channel;
                pB += channel;
                pResult += channel;
            }
        }
        
        return result;
    }
    
}

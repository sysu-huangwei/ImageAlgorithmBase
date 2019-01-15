//
//  PSVividLight.cpp
//  ImageAlgorithmBase
//
//  Created by HW on 2018/11/2.
//  Copyright © 2018 meitu. All rights reserved.
//

#include "PSVividLight.hpp"
#include "PSDefine.hpp"

namespace iab {
    
    unsigned char* PSVividLight::Run(unsigned char* imageA, unsigned char* imageB, int width, int height, int channel) {
        
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
                    float resultR = pB[PS_RED] < 128 ? pA[PS_RED] - (255.0 - pA[PS_RED]) * (255.0 - 2.0 * pB[PS_RED]) / pB[PS_RED] / 2.0 : pA[PS_RED] + pA[PS_RED] * (2.0 * pB[PS_RED] - 255.0) / (255.0 - pB[PS_RED]) / 2.0;
                    float resultG = pB[PS_GREEN] < 128 ? pA[PS_GREEN] - (255.0 - pA[PS_GREEN]) * (255.0 - 2.0 * pB[PS_GREEN]) / pB[PS_GREEN] / 2.0 : pA[PS_GREEN] + pA[PS_GREEN] * (2.0 * pB[PS_GREEN] - 255.0) / (255.0 - pB[PS_GREEN]) / 2.0;
                    float resultB = pB[PS_BLUE] < 128 ? pA[PS_BLUE] - (255.0 - pA[PS_BLUE]) * (255.0 - 2.0 * pB[PS_BLUE]) / pB[PS_BLUE] / 2.0 : pA[PS_BLUE] + pA[PS_BLUE] * (2.0 * pB[PS_BLUE] - 255.0) / (255.0 - pB[PS_BLUE]) / 2.0;
                    pResult[PS_RED] = resultR < 0 ? 0 : resultR > 255.0 ? 255.0 : resultR;
                    pResult[PS_GREEN] = resultG < 0 ? 0 : resultG > 255.0 ? 255.0 : resultG;
                    pResult[PS_BLUE] = resultB < 0 ? 0 : resultB > 255.0 ? 255.0 : resultB;
                    if (channel == 4) pResult[PS_ALPHA] = pA[PS_ALPHA];
                }
                else if (channel == 1) {
                    float resultR = pB[PS_RED] < 128 ? pA[PS_RED] - (255.0 - pA[PS_RED]) * (255.0 - 2.0 * pB[PS_RED]) / pB[PS_RED] / 2.0 : pA[PS_RED] + pA[PS_RED] * (2.0 * pB[PS_RED] - 255.0) / (255.0 - pB[PS_RED]) / 2.0;
                    pResult[PS_RED] = resultR < 0 ? 0 : resultR > 255.0 ? 255.0 : resultR;
                }
                pA += channel;
                pB += channel;
                pResult += channel;
            }
        }
        
        return result;
    }
    
}

//
//  PSBlend.hpp
//  ImageAlgorithmBase
//
//  Created by HW on 2019/1/15.
//  Copyright © 2019 meitu. All rights reserved.
//

#ifndef PSBlend_hpp
#define PSBlend_hpp

#include "PSBlendType.hpp"

namespace iab {
    class PSBlend {
    public:
        
        /**
         PS混合
         
         @param imageA 上层图
         @param imageB 下层图
         @param width 宽
         @param height 高
         @param type 叠加类型
         @param channel 通道数，默认RGBA 4通道
         @return 结果图，通道数和输入的channel一致
         */
        static unsigned char* Run(unsigned char* imageA, unsigned char* imageB, int width, int height, PSBlendType type, int channel = 4);
        
        
        /**
         PS混合：  使用叠加蒙版，默认是256*256的蒙版图
         
         @param imageA 上层图
         @param imageB 下层图
         @param width 宽
         @param height 高
         @param blendData 256*256的蒙版图
         @param channel 通道数，默认RGBA 4通道
         @return 结果图，通道数和输入的channel一致
         */
        static unsigned char* Run_Fast(unsigned char* imageA, unsigned char* imageB, int width, int height, unsigned char* blendData, int channel = 4);
    };
}

#endif /* PSBlend_hpp */

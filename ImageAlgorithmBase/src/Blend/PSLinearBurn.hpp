//
//  PSLinearBurn.hpp
//  ImageAlgorithmBase
//
//  Created by HW on 2018/11/2.
//  Copyright © 2018 meitu. All rights reserved.
//

#ifndef PSLinearBurn_hpp
#define PSLinearBurn_hpp

namespace iab {
    class PSLinearBurn {
    public:
        
        /**
         PS混合：线性加深
         
         @param imageA 上层图
         @param imageB 下层图
         @param width 宽
         @param height 高
         @param channel 通道数，默认RGBA 4通道
         @return 结果图，通道数和输入的channel一致
         */
        static unsigned char* Run(unsigned char* imageA, unsigned char* imageB, int width, int height, int channel = 4);
    };
}

#endif /* PSLinearBurn_hpp */

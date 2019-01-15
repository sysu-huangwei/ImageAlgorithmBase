//
//  PSDissolve.hpp
//  ImageAlgorithmBase
//
//  Created by HW on 2018/11/1.
//  Copyright © 2018 meitu. All rights reserved.
//

#ifndef PSDissolve_hpp
#define PSDissolve_hpp

namespace iab {
    class PSDissolve {
    public:
        
        /**
         PS混合：溶解

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

#endif /* PSDissolve_hpp */

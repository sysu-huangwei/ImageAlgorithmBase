//
//  PSAutoColorLevel.hpp
//  ImageAlgorithmBase
//
//  Created by HW on 2019/1/17.
//  Copyright © 2019 meitu. All rights reserved.
//

#ifndef PSAutoColorLevel_hpp
#define PSAutoColorLevel_hpp

namespace iab {
    class PSAutoColorLevel {
    public:
        
        /**
         PS 自动色阶
         
         @param image 原始图像
         @param width 宽
         @param height 高
         @param channel 通道数，默认RGBA 4通道
         @param lowCut 阴影裁剪比例  单位: 百分比%  默认 0.1%
         @param highCut 高光裁剪比例  单位: 百分比%  默认 0.1%
         @return 结果图，单通道灰度图
         */
        static unsigned char* Run(unsigned char* image, int width, int height, int channel = 4, float lowCut = 0.1f, float highCut = 0.1f);
    };
}

#endif /* PSAutoColorLevel_hpp */

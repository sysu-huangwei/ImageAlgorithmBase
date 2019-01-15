//
//  PSGray.hpp
//  ImageAlgorithmBase
//
//  Created by HW on 2019/1/15.
//  Copyright © 2019 meitu. All rights reserved.
//

#ifndef PSGray_hpp
#define PSGray_hpp

namespace iab {
    class PSGray {
    public:
        
        /**
         PS图像黑白调整算法
         
         @param image 原始图像
         @param width 宽
         @param height 高
         @param channel 通道数，默认RGBA 4通道
         @return 结果图，单通道灰度图
         */
        static unsigned char* Run(unsigned char* image, int width, int height, int channel = 4);
    };
}

#endif /* PSGray_hpp */

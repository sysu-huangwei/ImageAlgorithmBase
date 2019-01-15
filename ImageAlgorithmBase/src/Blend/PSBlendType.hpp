//
//  PSBlendType.hpp
//  ImageAlgorithmBase
//
//  Created by HW on 2019/1/15.
//  Copyright © 2019 meitu. All rights reserved.
//

#ifndef PSBlendType_hpp
#define PSBlendType_hpp

typedef enum PSBlendType {
    PSBlendType_Unknow = 0,         //未定义
    PSBlendType_Multiply = 1,       //正片叠底
    PSBlendType_ColorBurn = 2,      //颜色加深
    PSBlendType_ColorDodge = 3,     //颜色减淡
    PSBlendType_LinearBurn = 4,     //线性加深
    PSBlendType_LinearDodge = 5,    //线性减淡
    PSBlendType_Lighten = 6,        //变亮
    PSBlendType_Darken = 7,         //变暗
    PSBlendType_Screen = 8,         //滤色
    PSBlendType_Overlay = 9,        //叠加
    PSBlendType_SoftLight = 10,     //柔光
    PSBlendType_HardLight = 11,     //强光
    PSBlendType_VividLight = 12,    //亮光
    PSBlendType_PinLight = 13,      //点光
    PSBlendType_LinearLight = 14,   //线性光
    PSBlendType_HardMix = 15,       //实色混合
    PSBlendType_DarkerColor = 16,   //深色
    PSBlendType_LighterColor = 17,  //浅色
    PSBlendType_Difference = 18,    //差值
    PSBlendType_Exclusion = 19,     //排除
    PSBlendType_Dissolve = 20,      //溶解
} PSBlendType;

#endif /* PSBlendType_hpp */

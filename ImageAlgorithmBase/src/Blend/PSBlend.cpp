//
//  PSBlend.cpp
//  ImageAlgorithmBase
//
//  Created by HW on 2019/1/15.
//  Copyright © 2019 meitu. All rights reserved.
//

#include "PSBlend.hpp"
#include "PSDefine.hpp"
#include "PSMultiply.hpp"
#include "PSColorBurn.hpp"
#include "PSColorDodge.hpp"
#include "PSLinearBurn.hpp"
#include "PSLinearDodge.hpp"
#include "PSLighten.hpp"
#include "PSDarken.hpp"
#include "PSScreen.hpp"
#include "PSOverlay.hpp"
#include "PSSoftLight.hpp"
#include "PSHardLight.hpp"
#include "PSVividLight.hpp"
#include "PSPinLight.hpp"
#include "PSLinearLight.hpp"
#include "PSHardMix.hpp"
#include "PSDarkerColor.hpp"
#include "PSLighterColor.hpp"
#include "PSDifference.hpp"
#include "PSExclusion.hpp"
#include "PSDissolve.hpp"

namespace iab {
    
    
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
    unsigned char* PSBlend::Run(unsigned char* imageA, unsigned char* imageB, int width, int height, PSBlendType type, int channel) {
        
        switch (type) {
            case PSBlendType_Multiply://正片叠底
                return PSMultiply::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_ColorBurn://颜色加深
                return PSColorBurn::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_ColorDodge://颜色减淡
                return PSColorDodge::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_LinearBurn://线性加深
                return PSLinearBurn::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_LinearDodge://线性减淡
                return PSLinearDodge::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_Lighten://变亮
                return PSLighten::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_Darken://变暗
                return PSDarken::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_Screen://滤色
                return PSScreen::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_Overlay://叠加
                return PSOverlay::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_SoftLight://柔光
                return PSSoftLight::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_HardLight://强光
                return PSHardLight::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_VividLight://亮光
                return PSVividLight::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_PinLight://点光
                return PSPinLight::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_LinearLight://线性光
                return PSLinearLight::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_HardMix://实色混合
                return PSHardMix::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_DarkerColor://深色
                return PSDarkerColor::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_LighterColor://浅色
                return PSLighterColor::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_Difference://差值
                return PSDifference::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_Exclusion://排除
                return PSExclusion::Run(imageA, imageB, width, height, channel);
                break;
            case PSBlendType_Dissolve://溶解
                return PSDissolve::Run(imageA, imageB, width, height, channel);
                break;
            default:
                return nullptr;
                break;
        }
        
    }
    
    
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
    unsigned char* PSBlend::Run_Fast(unsigned char* imageA, unsigned char* imageB, int width, int height, unsigned char* blendData, int channel) {
        
        //结果数据
        unsigned char* result = nullptr;
        
        if (imageA != nullptr  &&  imageB != nullptr  &&  width > 0  &&  height > 0  &&  blendData != nullptr) {
            int pixelsCount = width * height;
            result = new unsigned char[pixelsCount * channel];
            
            unsigned char* pA = imageA;
            unsigned char* pB = imageB;
            unsigned char* pResult = result;
            
            for (int i = 0; i < pixelsCount; i++) {
                switch (channel) {
                    case 4:
                        pResult[PS_RED] = blendData[(pA[PS_RED]<<10) + (pB[PS_RED]<<2) + PS_RED];
                        pResult[PS_GREEN] = blendData[(pA[PS_GREEN]<<10) + (pB[PS_GREEN]<<2) + PS_GREEN];
                        pResult[PS_BLUE] = blendData[(pA[PS_BLUE]<<10) + (pB[PS_BLUE]<<2) + PS_BLUE];
                        pResult[PS_ALPHA] = 255;
                        break;
                    case 3:
                        pResult[PS_RED] = blendData[(pA[PS_RED]<<10) + (pB[PS_RED]<<2) + PS_RED];
                        pResult[PS_GREEN] = blendData[(pA[PS_GREEN]<<10) + (pB[PS_GREEN]<<2) + PS_GREEN];
                        pResult[PS_BLUE] = blendData[(pA[PS_BLUE]<<10) + (pB[PS_BLUE]<<2) + PS_BLUE];
                    case 1:
                        pResult[PS_RED] = blendData[(pA[PS_RED]<<10) + (pB[PS_RED]<<2) + PS_RED];
                    default:
                        break;
                }
                pA += channel;
                pB += channel;
                pResult += channel;
            }
        }
        
        return result;
    }
    
}

//
//  ImageLoader.cpp
//  ImageAlgorithmBase
//
//  Created by HW on 2018/10/31.
//  Copyright © 2018 meitu. All rights reserved.
//

#include "ImageLoader.hpp"

#include "stb_image.h"

namespace iab {
    
    /**
     从文件中读取图片RGBA数据

     @param fileName 图片文件路径
     @param width 返回图片宽
     @param height 返回图片高
     @return 图片RGBA数据，失败返回NULL
     */
    unsigned char* loadImageFromFile(const char* fileName, int& width, int& height) {
        int length = 0;
        FILE* pFile = fopen(fileName, "rb");
        if (pFile == NULL){
            fclose(pFile);
            return NULL;
        }
        fseek(pFile, 0, SEEK_END);
        length = (int)ftell(pFile);
        if (length <= 0){
            fclose(pFile);
            return NULL;
        }
        unsigned char *pData = new unsigned char[length + 1];
        fseek(pFile, 0, SEEK_SET);
        fread(pData, length, 1, pFile);
        fclose(pFile);
        pData[length] = 0;
        unsigned char* resultData = loadImageFromMemory(pData, length, width, height);
        delete [] pData;
        pData = NULL;
        return resultData;
    }
    
    
    
    /**
     从内存数据中读取图片RGBA数据

     @param memoryData 内存数据
     @param length 数据长度
     @param width 返回图片宽
     @param height 返回图片高
     @return 图片RGBA数据，失败返回NULL
     */
    unsigned char* loadImageFromMemory(const unsigned char* memoryData, int length, int& width, int& height) {
        return stbi_load_from_memory((unsigned char*)memoryData, length, &width, &height, nullptr, STBI_rgb_alpha);
    }
    
}

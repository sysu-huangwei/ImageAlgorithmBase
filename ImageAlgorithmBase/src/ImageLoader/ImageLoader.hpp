//
//  ImageLoader.hpp
//  ImageAlgorithmBase
//
//  Created by HW on 2018/10/31.
//  Copyright © 2018 meitu. All rights reserved.
//

#ifndef ImageLoader_hpp
#define ImageLoader_hpp

namespace iab {
    
    /**
     从文件中读取图片RGBA数据
     
     @param fileName 图片文件路径，注意必须是绝对路径
     @param width 返回图片宽
     @param height 返回图片高
     @return 图片RGBA数据，失败返回NULL
     */
    unsigned char* loadImageFromFile(const char* fileName, int& width, int& height);
    
    
    
    /**
     从内存数据中读取图片RGBA数据
     
     @param memoryData 内存数据
     @param length 数据长度
     @param width 返回图片宽
     @param height 返回图片高
     @return 图片RGBA数据，失败返回NULL
     */
    unsigned char* loadImageFromMemory(const unsigned char* memoryData, int length, int& width, int& height);
    
}

#endif /* ImageLoader_hpp */

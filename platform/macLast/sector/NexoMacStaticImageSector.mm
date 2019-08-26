//
// NexoMacStaticImageSector.mm
// Created by Alejandro Castro García on 26 August 2019
/*
 MIT License
 
 Copyright (c) 2019 Faustic Inferno SL
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
*/



#include "NexoMacStaticImageSector.hpp"

#include "NexoWindowDelegate.h"

#include <iostream>

namespace nexo
{
    void StaticImageSector:: AddToWindow(Window& window)
    {
        Resource r("sampleImage", "png");
        ResourceData& rd = r.GetData();
        void* d = rd.Data();
        std:: cout << d << "\n";
        
        NexoWindowDelegate* delegate = (__bridge NexoWindowDelegate*)window.PlatformWindow();
        NSView* contentView = delegate.window.contentView;
        NSImage* img = [NSImage.alloc initWithData: [NSData dataWithBytes: rd.Data() length: rd.Length()]];
        NSImageView* imgView = [NSImageView.alloc initWithFrame: NexoFlippedRect(contentView, NSMakeRect(left, top, width, height))];
        imgView.image = img;
        [contentView addSubview: imgView];
        
        std:: cout << "contentView flipped: " << contentView.flipped << "\n";
        std:: cout << "imgView flipped: " << imgView.flipped << "\n";
    }
    
}


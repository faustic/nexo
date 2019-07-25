//
// NexoMacWindow.cpp
// Created by Alejandro Castro García on 24 July 2019
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



#include "NexoMacWindow.hpp"

#import <Cocoa/Cocoa.h>
#import "NexoWindowDelegate.h"


namespace nexo
{
    void Window:: Init()
    {
        NSWindowStyleMask styleMask = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable;
        NSWindow* window = [NSWindow.alloc initWithContentRect: NSMakeRect(335, 390, 480, 360) styleMask: styleMask backing: NSBackingStoreBuffered defer: YES];
        window.releasedWhenClosed = NO; // We already release it as many times as we retain it.
        window.title = [NSBundle.mainBundle.infoDictionary objectForKey: @"CFBundleName"];
        [window makeKeyAndOrderFront: nil];

        NexoWindowDelegate* delegate = [NexoWindowDelegate.alloc initWithWindow: window nexo: (void*)this];
        
        window.delegate = delegate;
        
        
        platformWindow = (__bridge_retained void*)delegate; //Careful here. If we retain the bridged reference, we need to release it when the window is no longer needed to avoid leaks. If we do not retain it, we may get crashes if the window keeps beeing accessed afer being closed.

        
    }
}

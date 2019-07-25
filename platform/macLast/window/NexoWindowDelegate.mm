//
// NexoWindowDelegate.mm
// Created by Alejandro Castro García on 25 July 2019
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



#import "NexoWindowDelegate.h"

#include "NexoMacWindow.hpp"

@interface NexoWindowDelegate ()

@property NSWindow* window;
@property void* nexoWindow;

@end

@implementation NexoWindowDelegate

- (instancetype)initWithWindow: (NSWindow*)window nexo: (void*)nexoWindow;
{
    self = [super init];
    _window = window;
    _nexoWindow = nexoWindow;
    return self;
}


- (void)windowWillClose: (NSNotification *)notification
{
    if (self.window)
    {
        nexo:: Window* nWindow = (nexo:: Window*) self.nexoWindow;
        nWindow->Closed();
        
        self.window.delegate = nil;
        self.nexoWindow = nullptr;
        self.window = nil;
        CFRelease((void*)self); // It was retained in nexo::Window::Init()
    }
}

@end

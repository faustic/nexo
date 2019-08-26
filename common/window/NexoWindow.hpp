//
// NexoWindow.hpp
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



#ifndef NexoWindow_hpp
#define NexoWindow_hpp

#include <string>
#include <vector>

namespace nexo
{
    class Sector;
    
    class Window
    {
// MARK: - Private fields
        void (*ListenerAtClose)(Window&);
        void* platformWindow;
        std:: vector<Sector*> sectors;
        bool closed;
        
    public:
// MARK: - Platorm-independent public functions
        Window();
        void Closed();
        
        void NotifyWhenClosed(void (*)(Window&));
        
        void* PlatformWindow()
        {
            return platformWindow;
        }

// MARK: - Platform-dependent public funtions
        void Init(const char* title, short width, short height, short left, short top);
        
        void SetTitle(const char* title);
    };
}

#endif /* NexoWindow_hpp */

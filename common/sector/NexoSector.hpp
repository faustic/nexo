//
// NexoSector.hpp
// Created by Alejandro Castro García on 14 August 2019
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



#ifndef NexoSector_hpp
#define NexoSector_hpp

#include "NexoWindow.hpp"

namespace nexo
{
    class Sector
    {
    protected:
        short width;
        short height;
        short left;
        short top;

    public:
        Sector(short width, short height, short left, short top) :
        width(width), height(height), left(left), top(top)
        {}
        virtual void AddToWindow(Window& window) = 0;
        virtual ~Sector() {}
        
    };
    
    template <class T>
    Sector* CopySector(T& sector)
    {
        T* copy = new T(sector);
        return copy;
    }
}

#endif /* NexoSector_hpp */

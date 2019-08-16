//
// NexoResource.cpp
// Created by Alejandro Castro García on 16 August 2019
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



#include "NexoResource.hpp"

#include <stdexcept>
#include <cstring>

namespace nexo
{
    class ResourceDataImpl
    {
        ResourceDataImpl(const ResourceDataImpl&)
#if __cplusplus >= 201103L
        = delete
#endif
        ;
    public:
        char* data;
        size_t length;
        bool owned;
        
        ResourceDataImpl() :
        data(0), length(0), owned(false)
        {}
        
        ResourceDataImpl(size_t length) :
        owned(true), length(length)
        {
            data = new char[length];
        }
        
        ResourceDataImpl(void* newData, size_t length, bool copy) :
        owned(false), length(length)
        {
            if (!copy)
                data = static_cast<char*>(newData);
            else
            {
                owned = true;
                data = new char[length];
                memcpy(data, newData, length);
            }
        }
        
        ~ResourceDataImpl()
        {
            if (data && owned)
                delete[] data;
        }
        
    };
    
    void* ResourceData:: Data()
    {
        if (impl)
            return impl->data;
        else
            return 0;
    }
    
    size_t ResourceData:: Length()
    {
        if (impl)
            return impl->length;
        else
            return 0;
    }
    
    void ResourceData:: SetData(void* newData, size_t newLength, bool copy)
    {
        if (!impl)
            impl = new ResourceDataImpl(newData, newLength, copy);
    }

    
    ResourceData& Resource:: GetData()
    {
        return cache;
    }

}

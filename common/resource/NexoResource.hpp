//
// NexoResource.hpp
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



#ifndef NexoResource_hpp
#define NexoResource_hpp

#include <string>

namespace nexo
{
    class ResourceDataImpl;
    
    class ResourceData
    {
        ResourceDataImpl* impl;
        
        ResourceData(const ResourceData&)
#if __cplusplus >= 201103L
        = delete
#endif
        ;

        void SetData(void* data, size_t length, bool copy);
    public:
        ResourceData(const std:: string& name, const std:: string& type, bool copy);
        void* Data();
        size_t Length();
    };
    
    class Resource
    {
        std:: string name;
        std:: string type;
        ResourceData cache;
    public:
        Resource(const std:: string& name, const std:: string& type) :
        name(name), type(type), cache(name, type, true)
        {}
        
        ResourceData& GetData();
    };
}

#endif /* NexoResource_hpp */

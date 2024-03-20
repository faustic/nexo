// dtext.cpp
// Drawable text
// Created by Alejandro Castro García on 23 October 2023
/*
Licensed under the MIT License.
 
Copyright (c) Faustic Inferno SL
 
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


#include <nexo/gui/dtext.hpp>
#include <CoreFoundation/CoreFoundation.h>
#include <new>
#include <vector>

struct nexo::Dstring::Impl
{
    CFStringRef ref;
};

nexo::Dstring::Dstring(const U8string& u)
{
    impl = std::make_unique<Impl>();
    *this = u;
}

nexo::Dstring::~Dstring()
{
    CFRelease(impl->ref);
}

auto nexo::Dstring::operator=(const U8string& u) -> nexo::Dstring&
{
    const char* p = u.c_str();
    impl->ref = CFStringCreateWithCString(nullptr, p, kCFStringEncodingUTF8);
    if (!impl->ref)
        throw std::bad_alloc();
    return *this;
}

nexo::Dstring::operator U8string()
{
    const char* p = CFStringGetCStringPtr(impl->ref, kCFStringEncodingUTF8);
    if (p)
        return U8string(p);
    
    auto size = 4 * CFStringGetLength(impl->ref);
    std::vector<char> up(size);
    if (!CFStringGetCString(impl->ref, up.data(), size, kCFStringEncodingUTF8))
        throw Text_conversion_error();
    return U8string(up.data());
}

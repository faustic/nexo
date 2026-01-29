// Human-oriented text for display and edition
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


#include <nexo/gui/htext.hpp>
#include <CoreFoundation/CoreFoundation.h>
#include <new>
#include <vector>

struct nexo::Hstring::Impl
{
    CFStringRef ref;
};

nexo::Hstring::Hstring(const U8string& u)
{
    impl = std::make_unique<Impl>();
    *this = u;
}

nexo::Hstring::Hstring(const Hstring& s)
{
    impl = std::make_unique<Impl>();
    impl->ref = CFStringCreateCopy(nullptr, s.impl->ref);
}

nexo::Hstring::Hstring(Hstring&& s)
{
    impl = std::move(s.impl);
}

nexo::Hstring::~Hstring()
{
    if (impl && impl->ref)
        CFRelease(impl->ref);
}

auto nexo::Hstring::operator=(const U8string& u) -> nexo::Hstring&
{
    if (!impl)
        impl = std::make_unique<Impl>();
    const char* p = u.c_str();
    impl->ref = CFStringCreateWithCString(nullptr, p, kCFStringEncodingUTF8);
    if (!impl->ref)
        throw std::bad_alloc();
    return *this;
}

nexo::Hstring::operator U8string() const
{
    if (!impl)
        return U8string();
    const char* p = CFStringGetCStringPtr(impl->ref, kCFStringEncodingUTF8);
    if (p)
        return U8string(p);
    
    auto size = 4 * CFStringGetLength(impl->ref);
    std::vector<char> up(size);
    if (!CFStringGetCString(impl->ref, up.data(), size, kCFStringEncodingUTF8))
        throw Text_conversion_error();
    return U8string(up.data());
}


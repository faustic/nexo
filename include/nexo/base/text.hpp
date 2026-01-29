// Basic text-related types
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


#ifndef nexo_text_hpp
#define nexo_text_hpp

#include <string>

namespace nexo
{

class Text_conversion_error: public std::runtime_error
{
public:
    explicit Text_conversion_error():
    std::runtime_error("Text conversion error")
    {
    }
};

class U8string
{
// Similar to std::u8string, but uses char instead of char8_t and
// not every function is implemented.
// Attempting to avoid std::u8string weirdness while still
// being explicit about its intended encoding.
public:
    U8string() {}
    explicit U8string(const std::string& str) : priv_str(str)
    {
    }
    explicit U8string(const char* c) :priv_str(c)
    {
    }

    constexpr const char* c_str() const noexcept
    {
        return priv_str.c_str();
    }

    constexpr char& at(std::string::size_type pos)
    {
        return priv_str.at(pos);
    }

    constexpr const char& at(std::string::size_type pos) const
    {
        return priv_str.at(pos);
    }

    constexpr char& operator[](std::string::size_type pos)
    {
        return priv_str[pos];
    }

    constexpr const char& operator[](std::string::size_type pos) const
    {
        return priv_str[pos];
    }
    
    U8string& operator+=(const U8string& str)
    {
        priv_str += str.c_str();
        return *this;
    }
    
    U8string operator+(const U8string& str) const
    {
        U8string sum = *this;
        sum += str;
        return sum;
    }
    
    U8string& operator+=(unsigned long long n)
    {
        char c[] = {0x30, '\0'};
        U8string str;
        if (!n)
            str = U8string(c);
        else while (n)
        {
            c[0] = 0x30 | (n % 10);
            str = U8string(c) + str;
            n /= 10;
        }
        *this += str;
        return *this;
    }

    U8string& operator+=(long long n)
    {
        unsigned long long u = n;
        if (n >= 0)
            return *this += u;
        priv_str.push_back(0x2d);
        u = ~u + 1;
        return *this += u;
    }

private:
    std::string priv_str;
};

class Estring
{
public:
    virtual Estring& operator=(const U8string&) = 0;
    explicit virtual operator U8string() const = 0;
};

}

#endif /* nexo_text_hpp */

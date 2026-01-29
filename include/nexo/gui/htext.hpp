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


#ifndef nexo_dtext_hpp
#define nexo_dtext_hpp

#include <nexo/base/text.hpp>
#include <memory>

namespace nexo
{

class Hstring: public Estring
{
public:
    Hstring(const U8string& u);
    Hstring() : Hstring(U8string(""))
    {
    }
    Hstring(const Hstring&);
    Hstring(Hstring&&);
    ~Hstring();
    Hstring& operator=(const U8string&) override;
    explicit operator U8string() const override;
    class Impl;
private:
    std::unique_ptr<Impl> impl;
};

}

#endif /* nexo_dtext_hpp */

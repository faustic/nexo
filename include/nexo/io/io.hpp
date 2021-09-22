// io.hpp
// Input/output: interface
// Intended compatibility: c++20
//
// Created by Alejandro Castro García on 1 September 2021
/*
Licensed under the MIT License.
 
Copyright (c) 2021 Faustic Inferno SL
 
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


#ifndef nexo_io_hpp
#define nexo_io_hpp

#include <vector>
#include <memory>
#include <stdexcept>

namespace nexo
{

using std::vector;
using std::unique_ptr;
using std::runtime_error;

class Error_io_read: public runtime_error
{
public:
    Error_io_read(): runtime_error("Nexo Error_io_read")
    {}
};

class Error_io_write: public runtime_error
{
public:
    Error_io_write(): runtime_error("Nexo Error_io_write")
    {}
};

class Error_io_open: public runtime_error
{
public:
    Error_io_open(): runtime_error("Nexo Error_io_open")
    {}
};

using Byte = unsigned char;

class Io_handler
{
public:
    vector<Byte> read(size_t size);
    class Impl;

protected:
    unique_ptr<Impl> impl;
    Io_handler();
};


} // namespace nexo

#endif /* nexo_io_hpp */

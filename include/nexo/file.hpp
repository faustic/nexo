//
// file.hpp
// Created by Alejandro Castro Garcia on 11 November 2020
/*
 MIT License
 
 Copyright (c) 2020 Faustic Inferno SL
 
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



#ifndef nexo_file_hpp
#define nexo_file_hpp

#include <string>
#include <memory>

namespace nexo
{

class File_info
{
public:
private:
}; // class File_info

class File_locator
{
public:
    File_locator(std::string ref);
private:
    class Impl;
    std::unique_ptr<Impl> impl;
}; // class File_locator

class File_pass
{
public:
private:
}; // class File_pass

} // namespace nexo

#endif /* nexo_file_hpp */

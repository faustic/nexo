//
// platform.cpp
// Created by Alejandro Castro Garcia on 16 October 2020
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



#include <nexo/platform.hpp>

namespace nexo
{

int Platform::event_loop(int argc, char** argv)
{
// The default event loop just returns
    return 0;
}

int Platform::run(int argc, char** argv)
{
    try
    {
        event_loop(argc, argv);
    }
    catch(Normal_termination)
    {
        // Normal termination just unwinds the stack and returns to the caller
    }
    return 0;
}

void Platform::terminate()
{
    throw Normal_termination();
}

} // namespace nexo
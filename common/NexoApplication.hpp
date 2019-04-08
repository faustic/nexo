//
// NexoApplication.hpp
// Created by Alejandro Castro García on 8 April 2019
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



#ifndef NexoApplication_hpp
#define NexoApplication_hpp

namespace nexo
{
    class Application
    {
    protected:
        char** argv;
        int argc;

    public:
        int result;

        static void Start(int argc, char** argv);
        static Application& ThisApp();

        Application(int argc, char**argv);
        
        int Argc();
        const char** Argv();

    };
}

#endif /* NexoApplication_hpp */

//
//  NexoUWPPlatform.cpp
//  Project
//
//  Created by Alejandro Castro García on 27 September 2019.
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

#include "pch.h"

#include "NexoUWPPlatform.hpp"

#include "NexoApplication.hpp"

#include <stdexcept>

void oldMain(); // Provisional

using winrt::implements;
using winrt::Windows::ApplicationModel::Core::IFrameworkViewSource;
using winrt::Windows::ApplicationModel::Core::IFrameworkView;
using winrt::hstring;
using winrt::Windows::UI::Core::CoreWindow;
using winrt::Windows::ApplicationModel::Core::CoreApplicationView;


namespace nexo
{
	struct App : implements <App, IFrameworkViewSource, IFrameworkView>
	{
		IFrameworkView CreateView() const
		{
			return *this;
		}

		void Initialize(CoreApplicationView ) const
		{
		}

		void Load(hstring) const
		{
		}

		void Uninitialize() const
		{
		}

		void Run() const
		{
			nexo::Application::ThisApp().Loaded();
		}

		void SetWindow(CoreWindow) const
		{
		}
	};

	static UWPPlatform thisPlatform;

	Platform& Platform::ThisPlatform()
	{
		return thisPlatform;
	}

	void UWPPlatform::EventLoop()
	{
		oldMain(); // Call dummy main while we do not implement a custom one.
	}
}

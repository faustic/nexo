# Nexo

*Copyright © Faustic Inferno SL*

*Licensed under the MIT License*

## Platform `mac`

We use the name `mac` to refer to the platform represented by the operating system **macOS Monterey**  as of 27 April 2022. Being a current platform, the name `mac` will automatically refer to future versions as they are released.

### Guidelines

* When possible, we should try to write code compatible with at least the three last major versions of the operating system.
* We prefer not to make a big effort to support versions older than the three last major versions, but we should try to choose the most compatible alternative when it is neither too difficult nor deprecated.
* When possible, we prefer C++ to Objective-C++.
* When possible, we prefer Objective-C++ to C.
* When possible, we prefer C to Objective-C.
* When possible, we prefer Objective-C to Swift.

### Related platforms

* iPhone, iPad, iWatch... While their systems have much in common with macOS, we think it is better not to include code for them within our `mac` directories; we should define one or more new platforms instead.
* Old Mac OS X versions. Sometimes it may be difficult to keep a common code base for current macOS and older Mac OS X versions. For retrocomputing purposes, we may define one or more platforms to support old Mac OS X versions.
* Classic Mac OS. It will be a rare occurrence that the same piece of platform-dependent code can work on classic Mac OS and current macOS. For retrocomputing purposes, we may define one or more platforms to support classic Mac OS versions.
* NeXTSTEP. The ultimate ancestor of current macOS. It may be interesting for retrocomputing purposes.
* GNUstep. Since we have adopted a user's view rather than a programmer's view of what we consider a platform, we do not see GNUstep as a platform. However, code we write for the `mac` platform is expected to be often compatible with GNUstep.

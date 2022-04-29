# Nexo

*Copyright © Faustic Inferno SL*

*Licensed under the MIT License*

## Platform `windows`

We use the name `windows` to refer to the platform represented by the operating system **Windows 11**  as of 29 April 2022. Being a current platform, the name `windows` will automatically refer to future versions as they are released.

We are still not decided whether we are going to favour UWP or Win32. We had considered to define two separate platforms `uwp` and `win32`, but that goes against our stated policy of naming platforms according to the user's view, not the programmer's view. Hopefully, Project Reunion will make this issue irrelevant in a not too distant future.

### Guidelines

* When possible, we should try to write code compatible with at least the last major version of the operating system.
* We prefer not to make a big effort to support older versions, but we should try to choose the most compatible alternative when it is neither too difficult nor deprecated.

### Related platforms

* Old Windows versions. Sometimes it may be difficult to keep a common code base for current Windows and older Windows versions. For retrocomputing purposes, we may define one or more platforms to support old Windows versions.
* MS-DOS. For retrocomputing purposes, we may define one or more platforms to support standalone MS-DOS versions. However, code written for Windows running on top of MS-DOS will still be considered code for Windows (for an old Windows platform if it cannot be made compatible with the current `windows` platform).
* ReactOS. A free operating system meant to be compatible with Windows applications and drivers. Since most developers do not specifically target ReactOS instead of Windows, Nexo will not probably need to separately support ReactOS.
* Wine. A compatibility layer meant to be compatible with Windows applications. Since most developers do not specifically target Wine instead of Windows, Nexo will not probably need to separately support Wine.

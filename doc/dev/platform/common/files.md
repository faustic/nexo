# Nexo

*Copyright © Faustic Inferno SL*

*Licensed under the MIT License*

## Platform mac_last

### Files

#### File_locator

`File_locator` may be internally represented as a path or something more platform-specific (`FSSpec`, `FSRef`, `NSURL`...).

It is not guaranteed to be robust, i.e. it is not guaranteed that it will keep referring to the same object when such object is being moved around. Therefore, we must create a new `File_locator` object every time we want to operate on the file if we need to ensure it points to its current location.

#### File_pass

`File_pass` may be internally represented as a standard C `FILE` pointer or something more platform-specific (POSIX file descriptor, Win32 HFILE...).

#### File_info

A `File_info` instance represents a dictionary of keys and values that can be get and set. Different keys may sometimes partly represent the same file attribute; for example, the classic Mac creator might be set with the key `mac:creator` or with the key `attr:com.apple.FinderInfo`. The same key may sometimes be associated with different kinds of value; for example, the file creator might be set as an integer or as a string.


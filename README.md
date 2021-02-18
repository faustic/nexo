# Nexo

*Copyright © Faustic Inferno SL*

*Licensed under the MIT License*

A library for cross-platform application development.

## Purpose

Nexo is a multipurpose library for cross-platform development in C++. Eventually, it will also likely include a set of multiples tools to help with software development. It is expected to address features that are not part of the C++ standard and that cannot be fully implemented in a platform-independent way, such as:

* User interface.
* Graphics.
* Networking.

## Design principles

Nexo is designed according to the following principles:

* Self-containment:
    * avoiding dependencies other than what is essential for each supported platform.
* Modularity:
    * allowing applications to use just the parts wanted,
    * allowing selected modules to be quickly ported to rare platforms as needed.
* Friendliness:
    * making it easy for applications to use other libraries and frameworks as their main cross-platform solution and use Nexo for certain tasks only.


## Documentation

Nexo is still in a very early stage of development. As the project advances, there will be more documentation, organised into two main topics:

* How to use the library.
* How to modify the library.

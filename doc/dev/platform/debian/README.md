# Nexo

*Copyright © Faustic Inferno SL*

*Licensed under the MIT License*

## Platform `debian`

We use the name `debian` to refer to the platform represented by the operating system **Debian 11**  as of 29 April 2022. Being a current platform, the name `debian` will automatically refer to future versions as they are released.

Because the system is made of multiple packages from multiple authors and installation options are very variable, defining the platform accurately would require to clearly state the packages we depend on. However, we are currently just tasting the waters, so we postpone this issue until we have a clearer idea about what our requirements will be.

When naming platforms, we have discarded some names we considered before:

* `posix`. In the past we labelled code as `posix` that now we will include in the `debian` platform. The label `posix` represented a programmer's point of view, and now we are naming platforms from a user's point of view.
* `gnu`. It is likely that much of our code will depend on GNU libraries. However, it is also likely that it will also depend on libraries that are not part of the GNU project. Moreover, from the user's point of view, it is easier to require an "up-to-date version of Debian" than an "up-to-date version of this list of GNU packages"
* `linux`. From the user's point of view, "Linux" is a popular term for a whole system that includes the Linux kernel and other multiple software packages. However, the term used in that sense is too vague to be useful to refer to a specific environment. Properly speaking, Linux is just the kernel. It is unlikely that our code will directly depend on the Linux kernel.
* `ubuntu`, `fedora`... Other GNU/Linux distributions were considered. We ended choosing Debian because it seemed to support more architectures. We can still define for example an `ubuntu` platform in addition to `debian`, but our activity on either system is still too low for this division to be practical.

### Guidelines

* When possible, we should try to write code compatible with at least the last major version of the operating system.
* We prefer not to make a big effort to support older versions of Debian or current versions of other GNU/Linux distributions, but we should try to choose the most compatible alternative when it is neither too difficult nor deprecated.

### Related platforms

* Other current GNU/Linux distributions. Most code we write for `debian` is expected to work on other up-to-date GNU/Linux distributions, but at this moment we are not in a position to test thoroughly.
* Older GNU/Linux distributions. Older systems may be interesting for retrocomputing purposes.
* Other Unix and Unix-like systems. For some of them we may define a specific platform (e.g. `mac`). For others, we may occasionally find that they are compatible with code we write for `debian`.

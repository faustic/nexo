# Nexo

*Copyright © Faustic Inferno SL*

*Licensed under the MIT License*

## Platforms

### What do we call a platform?

A platform is an environment where an application can run. An application is written and built for a certain platform or platforms.

From a user's point of view, knowing the platform an application is written for helps answering the question: "can this application run on my machine?"

From a programmer's point of view, being asked to write an application for a certain platform means trying to answer the questions: "what tools and information do I need to do the job?"

We usually adopt the user's view for matters of global organisation, such as naming the platforms. We adopt the programmer's view when going into the detail of each platform.

### Current platforms

When we say a platform is current, we mean that it is still actively developed and maintained. For such a platform, we try to adhere to the following guidelines:

* We use a simple designator to refer to a current platform, such as `windows` or `mac`, which will be used to name directories related to the platform, and also as our informal name for the platform. We are abandoning our old habit of appending the suffix `_last` to the name to refer to the current version: when we do not add qualifiers, we mean to be compatible with the most current version.
* The code we write for a current platform may be compatible or not with older versions of that platform. The effort we make to achieve such compatibility depends on a number of factors, such as viability, difficulty and user demand.
* Being compatible with the current version is an aim, but we may be unable to keep pace with changes to the platform. If that is the case, we should consider the incompatible code as targeted to a different platform and treat it accordingly.

### Retrocomputing platforms

Retrocomputing platforms are those that are no longer developed or maintained, including old versions of current platforms when too many incompatibilities have arisen. Our guidelines for such platforms are:

* For a platform we target rarely and with no current version, we use a simple designator for it, such as `msdos`. Compatibility with different versions may be different for each piece of code.
* For a platform we target often or if it is an old version of a current platform, we add qualifiers that hint about expected compatibility, such as `windows3`, `windows95`, `windowsxp`. We generally prefer a version specifier related to the commercial name rather than the internal version number.

### Decentralised platform support

For Nexo development, we have considered two possible strategies:

1. Option A. Define a reference platform. Every platform-dependent piece of code that we need must first be written for the reference platform, and only then rewritten for other platforms.
2. Option B. There is no reference platform. A piece of code is written first for the platform most convenient at the moment.

Our choice is **option B**. In practice, it may work as option A if we tend to start always with the same platform, but with no obligation.


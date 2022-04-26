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

### Platform isolation

When writing code that is not platform-independent but is compatible with more than one platform, there is the possibility of sharing code between platforms. For example, when writing POSIX-compatible code, it is tempting to share the same code between all platforms that are POSIX-compatible or compatible enough. We have done so before, but we have now decided against it.

The current policy is **not to share implementation files** between different platforms, no matter how similar they are. Even if the files are identical, each platform must have its own separate copy. The following two examples illustrate an advantage and a disadvantage of such a decision.

#### Example 1. Problem with duplicated code

For a certain task, the same code is used for popular platform A and obscure platform B, but it is written in separate files, one for each platform. Eventually, a bug is discovered while testing platform A, and is corrected, but only on that platform. Nobody remembers that the same bug must also be present on the copy for platform B, where it remains uncorrected for years. This is an example of how our decision of isolating platforms may be disadvantageous.

#### Example 2. Problem with shared code

For a certain task, the same code is used for popular platform A and obscure platform B, both getting the code from the same exact file. Eventually, someone makes an improvement and tests it on platform A, where it works perfectly. However, the improvement makes the code incompatible with platform B, but this goes unnoticed for years. This is an example of how our decision of isolating platforms may be advantageous.

#### Weighing of problems

* Platform isolation means that if all Nexo developers stop working on a platform, the code will neither improve nor get worse for that platform.
* Shared code means that even if all Nexo developers stop working on a platform, the code might still improve or get worse for that platform.

For now, we will apply the principle of least surprise and persist with the policy of platform isolation. Future experience will tell if the choice was adequate.

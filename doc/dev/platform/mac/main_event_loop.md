# Nexo

*Copyright © Faustic Inferno SL*

*Licensed under the MIT License*

## Platform mac

### Main event loop

The main event loop is started by calling `[NSApp run]`. Normally, this method is not called directly, but indirectly through a call to `NSApplicationMain()`, which first initialises `NSApp` if needed and loads the application's main nib file.

`[NSApp run]` returns to its caller if the loop is finished by calling `[NSApp stop]` from an event handler running in the main event loop. However, it does not return when the event loop is finished with a call to `[NSApp terminate]` (the way generally used by regular quit events). And `NSApplicationMain()` never returns, not even when using `[NSApp stop]`.

Therefore, for objects created before calling `NSApplicationMain()` or `[NSApp run]`, it is not guaranteed that they will be cleanly destroyed. The recommended practice from Apple is to create such objects in `[NSApplicationDelegate applicationDidFinishLaunching:]` and destroy them in `[NSApplicationDelegate applicationWillTerminate:]`, but it is unsatisfactory that the platform puts such a constraint on our platform-independent objects.

One workaround would be to throw an exception from within `[NSApplicationDelegate applicationWillTerminate:]` and catch it after the call to `NSApplicationMain()`. Objective-C and C++ exceptions are mostly interoperable in 64-bit processes, so this should cleanly destroy all objects created with ARC or RAII philosophy. We cannot be sure, though, that we are not missing some of the cleanup done after a normal return from `[NSApplicationDelegate applicationWillTerminate:]`.


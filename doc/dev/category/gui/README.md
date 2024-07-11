# Nexo

*Copyright © Faustic Inferno SL*

*Licensed under the MIT License*

## Graphical user interface

Our graphical user interface will be basically made of events, views and view containers.

### View

A view is something that can be seen. It is not actually seen until is added to a view container, which usually represents a screen area or a printer page area. From the point of view of the application, a view is defined by an enclosing rectangle and some properties; exactly which properties is dependant on the kind of view. We plan to develop our view classes according to the following ideas:

* An abstract class called `View` will be the ultimate base class of every view class. It lacks properties. It has a default virtual destructor.
* Classes derived from `View` must either be abstract as well or have an enclosing rectangle with defined width and height. The origin of the rectangle is not defined, as it is managed by the view container that contains the view.
* An abstract class called `Platform_view` is derived from `View` with no overrides or new members. `Platform_view` is intended to be used by `Mediating_view` to hide  platform-dependent implementation details.
* A concrete class called `Mediating_view` is derived from `View`. While it is concrete, it is only intended to be further derived. Its constructor and destructor must be defined in a platform-dependent implementation file. Its only property is a pointer to an object of class `Platform_view`. Virtual functions coming from `View` must be overriden by forwarding them to the corresponding functions in `Platform_view`. It is expected that for every class derived from `Mediating_view` there will be a corresponding class derived from `Platform_view`.
* The `View` class lacks functions to draw or print. The only way for an application to draw or print is to add views to a view container, before or after changing the view properties as desired.
* Classes derived from `Platform_view` may have functions to draw and print, but that is an implementation detail that may be true or not depending on the platform.

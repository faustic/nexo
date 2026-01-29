# Nexo

*Copyright © Faustic Inferno SL*

*Licensed under the MIT License*

## Base

### Error handling

Nexo reports errors mostly by throwing exceptions. As is often recommended, the thrown object is of a custom class that inherits from a standard exception. We name this custom class with the pattern `Error_<sublibrary>_<identifier>`, where `<sublibrary>` represents the part of the Nexo library where the error is relevant. Both `<sublibrary>` and `<identifier>` can be further divided into parts separated with `_`. For example:

    class Error_io_serial_baudrate: public runtime_error
    {
    public:
        Error_io_serial_baudrate(): runtime_error("Nexo Error_io_serial_baudrate")
        {}
    };


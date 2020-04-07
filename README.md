# datastructures

## Purpose

I made this project to help me learn c++ by implementing a few very basic data structures in c++ and writing tests for them in Catch2

## Usage

If you would like to use or just play around with this repo simply clone it into a known location, then ensure the headers in the `/include` directory are in the include path of you project. This is a header only library so after that is done the structures can be accessed using `#include <datastructures>` all datastructures are in a namespace `dts`.

## Testing

To run the tests, first clone the repository. Then in the root directory execute the following commands:

```
mkdir build
cd build
cmake ..
ctest
```

# PhanesEngine

Yet another Game Engine written in C++.

## Build

For building the engine premake5 is required. Execute `premake5 gmake` to generate the Makefile.

### PhanesCore

The Core Runtime library is build with:

    make PhanesCore

## Status

Phanes is and will be developed, though progress will be slow.

### Currenty under development

- PhanesCore
  - <span style="color:green; font-weight:800">Math</span>

## Testing

Testing PhanesEngine happens via the gtest framework. To run the tests for PhanesEngine one needs to
build the test applications (currently only MathTestFPU) as well as gtet.

    make MathTestFPU

They depend on the gtest library so it should not be required to build it manually. If for some reason this doesn't
work gtest can be build via:

    make gtest

## Sample Project

The repository contains a sample game project using PhanesEngine. It can be build by executing:

    make DevPlayground

## Copyright

PhanesEngine was developed by Thorben Höhne and is licensed under the Apache License Version 2.0. See
[LICENSE](LICENSE) for more information.

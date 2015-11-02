#General
This project of mine should provide a pricing mechanism for
path-independent financial derivatives.
Parts of it are inspired by Joshi's "The Concepts and Practice of
Mathematical Finance" and "C++ Design Patterns and Derivatives
Pricing".

I provide two pricing mechanisms. One via the analytical formulas and
a Monte-Carlo pricing scheme which is used for validation.


#Code organization
In src/ we have the sources, in include/ the headers. The tests are
located in the folder `test`. Each unittest is named `test_<classname>`.

"make all" compiles everything and runs the tests.
"make tests" runs the tests.
"make doc" builds the documentation.

#Dependencies
libboost-test, for running the tests.
doxygen, for creating the documentation

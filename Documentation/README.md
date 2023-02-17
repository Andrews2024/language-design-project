# Summary
# Syntax
# Spirit
For this project, we use Boost's Spirit X3 library to create a parser. This parser is a recursive-descent parser that uses syntax similar to EBNF. We chose this library because of its comprehensive documentation and integration with C++. Spirit X3 also presents a reduced learning curve versus tools like Bison and ANTLR. More information about Spirit X3 is available [here](https://www.boost.org/doc/libs/1_76_0/libs/spirit/doc/x3/html/spirit_x3/introduction.html).

## Set Up
To use the library, we installed it on an Ubuntu VM. To install it, we used the command `sudo apt-get install libboost-all-dev` in the terminal, which installs all development libraries from Boost, including Spirit X3. After installation, we included the Spirit X3 library in our C++ source code with the statement `#include <boost/spirit/home/x3.hpp>`.

## Getting started
To learn how to use the Spirit X3 library, follow the [tutorial pages](https://www.boost.org/doc/libs/1_76_0/libs/spirit/doc/x3/html/spirit_x3/tutorials.html) provided by Boost.
To see what built-in parsers come with Spirit X3, look at the various [quick reference pages](https://www.boost.org/doc/libs/1_76_0/libs/spirit/doc/x3/html/spirit_x3/quick_reference.html) or at slides 40 to 48 of these [PowerPoint slides](https://ciere.com/cppnow15/using_x3.pdf) from Ciere Consulting. The presentation which uses this slide deck can be viewed at this [YouTube video](https://www.youtube.com/watch?v=xSBWklPLRvw).
# GapVector
[![Build Status](https://travis-ci.org/Catminusminus/gapvector.svg?branch=master)](https://travis-ci.org/Catminusminus/gapvector)

A simple implementation of gap buffer with STL-like interface.
## How To Use
Include the header "gapvector.hpp", then you can use my::GapVector in the same way as you use std::vector.

Here is the sample code.
```cpp
#include <iostream>
#include "gapvector.hpp"

int main()
{
    using namespace std::literals::string_literals;

    my::GapVector<std::string> gap_vector;
    gap_vector.push_back("Hello"s);
    gap_vector.push_back("world!"s);
    auto itr = gap_vector.insert(gap_vector.cbegin() + 1, ", "s);

    auto str = ""s;
    for (auto &&e : gap_vector)
    {
        str += e;
    }

    std::cout << str << std::endl;
    return 0;
}
```

## Requirements
- Boost C++ Libraries 
- g++-7
## License
Unlicense (https://github.com/Catminusminus/gapvector/blob/master/LICENSE)
## Auther
Catminusminus (https://github.com/Catminusminus)
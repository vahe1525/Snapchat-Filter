
// Project libraries
#include "Pixel.hpp"

// Standard libraries

Pixel::Pixel()
    : R(255)
    , G(255)
    , B(255)
    , IsIncluded(false)
{
}

Pixel::Pixel(char r, char g, char b)
    : R(r)
    , G(g)
    , B(b)
{
}

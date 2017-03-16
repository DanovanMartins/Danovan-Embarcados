// reciprocal.cpp
#include <cassert>
#include "reciprocal.hpp"

double reciprocal (int i)
{
    // I should be nonzero.
    assert (i != 0);
    return 1.0/i;
}

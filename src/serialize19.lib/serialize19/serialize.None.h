#pragma once
#include "serialize.h"
#include "variant19/None.h" // requires variant19

namespace serialize19 {

template<Archive A> void serialize(A&, valiant19::None&) {}

} // namespace serialize19

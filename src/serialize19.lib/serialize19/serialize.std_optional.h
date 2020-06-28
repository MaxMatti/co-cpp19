#pragma once
#include "serialize.h"

#include <optional>

namespace serialize19 {

template<Archive A, class T> void serialize(A& a, std::optional<T>& optional) {
    auto hasValue = optional.has_value();
    serialize(a, hasValue);
    if (a.mode == ArchiveMode::Read) {
        if (hasValue) {
            auto value = T{};
            serialize(a, value);
            optional = std::move(value);
        }
        else {
            optional = {};
        }
    }
    else {
        if (hasValue) {
            serialize(a, *optional);
        }
    }
}

} // namespace serialize19

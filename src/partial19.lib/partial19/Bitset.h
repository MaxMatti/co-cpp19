#pragma once
#include <stddef.h> // size_t

namespace partial19 {

/// Minimal constexpr enabled implemenation of std::bitset
/// Only the mandatory methods are implemented
template<size_t Count> struct Bitset {
    using T = unsigned;
    constexpr static auto Len = (Count + (sizeof(T) - 1)) / sizeof(T);
    constexpr static auto count = Count;

    T m[Len] = {};

    constexpr bool operator==(const Bitset& o) const = default;

    [[nodiscard]] constexpr bool operator[](size_t index) const noexcept {
        return 0 != (m[index / sizeof(T)] & (1u << (index % sizeof(T))));
    }

    constexpr void reset() noexcept {
        for (auto& v : m) v = {};
    }

    constexpr void setAt(size_t index) noexcept { m[index / sizeof(T)] |= (1u << (index % sizeof(T))); }
    constexpr void resetAt(size_t index) noexcept {
        m[index / sizeof(T)] &= ~static_cast<T>(1u << (index % sizeof(T)));
    }
};

} // namespace partial19

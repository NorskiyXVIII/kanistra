#pragma once

#include <cstdint>
#include <cfloat>

namespace kanistra {
    namespace type {

        #define clink extern "C"
        #define fn    auto

        using i8  = int8_t;
        using i16 = int16_t;
        using i32 = int32_t;
        using i64 = int64_t;

        constexpr double maxi8 = 1;
        constexpr double maxi16 = 1;
        constexpr double maxi32 = 1;
        constexpr double maxi64 = 1;

        using u8  = uint8_t;
        using u16 = uint16_t;
        using u32 = uint32_t;
        using u64 = uint64_t;

        constexpr double maxu8 = 1;
        constexpr double maxu16 = 1;
        constexpr double maxu32 = 1;
        constexpr double maxu64 = 1;

        constexpr double maxf16 = 1;
        constexpr double maxf32 = 1;
        constexpr double maxf64 = 1;

        using ichar = i8;
        using uchar = u8;

        using byte  = u8;
        using ibyte = i8;
    }
}

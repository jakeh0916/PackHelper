#ifndef PACKHELPER_PACK_H
#define PACKHELPER_PACK_H

// ===============================
// | PackHelper - Pack [Header]  |
// | Copyright 2023 Jake Huseman |
// ===============================

// The packhelp::Pack structure holds a list of types using recursive inheritance. This can
// be visualized as a chain of related Pack<...> types as shown below. (For more detail on
// recursive inheritance, see the implementation of std::tuple.)
// 
// ===========================       ======================       ==================       ===========
// | Pack<short, int, long>  |       | Pack<int, long>    |       | Pack<long>     |       | Pack<>  |
// |-------------------------|       |--------------------|       |----------------|       |---------|
// | Type = short            |       | Type = int         |       | Type = long    |       |         |
// | Base = Pack<int, long>  |  -|>  | Base = Pack<long>  |  -|>  | Base = Pack<>  |  -|>  |         |
// ===========================       ======================       ==================       ===========

namespace packhelp
{
    // @brief The "Pack" type is a compile-time container for 0..n types.
    // @tparam Types... - The types to be stored in this pack.
    template<typename... Types>
    struct Pack;

    template<> // (base case)
    struct Pack<>
    {
    };

    template<typename Head, typename... Tail> // (recursive case)
    struct Pack<Head, Tail...> : Pack<Tail...>
    {
        using Type = Head;
        using Base = Pack<Tail...>;
    };
};

#endif // PACKHELPER_PACK_H

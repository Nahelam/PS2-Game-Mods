#pragma once

#include "types.h"

inline void PATCH_8(u32 addr, u8 value)
{
    *(u8 *)(addr) = value;
}

inline void PATCH_16(u32 addr, u16 value)
{
    *(u16 *)(addr) = value;
}

inline void PATCH_32(u32 addr, u32 value)
{
    *(u32 *)(addr) = value;
}

inline void PATCH_64(u32 addr, u64 value)
{
    *(u64 *)(addr) = value;
}

inline void PATCH_128(u32 addr, u128 value)
{
    *(u128 *)(addr) = value;
}

inline void PATCH_F32(u32 addr, float value)
{
    *(float *)(addr) = value;
}

inline void PATCH_F64(u32 addr, double value)
{
    *(double *)(addr) = value;
}

inline void MAKE_NOP(u32 addr)
{
    PATCH_32(addr, 0);
}

inline void MAKE_JAL(u32 at, u32 dest)
{
    PATCH_32(at, (0x0C000000 | (dest >> 2)));
}

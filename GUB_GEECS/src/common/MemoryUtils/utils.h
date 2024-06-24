#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

/** for malloc */
#include <stdlib.h>

/** for uint8_t, uint16_t, uint32_t, uint64_t */
#include <stdint.h>

/**
 * @brief Sanitize a value to ensure it fits within a byte.
 *
 * @param value The value to sanitize.
 * @return uint8_t The sanitized byte value.
 */
#define SanitizeByte(value) ((uint8_t)(value & 0xFF))

/** for memory function macro templates */
#include "memory_function_macro_templates.h"

// Generate specific implementations for Byte, Word, Dword, and Qword
DEFINE_WRITE_MEMORY_REGION_FUNC(uint8_t, Byte)
DEFINE_WRITE_MEMORY_REGION_FUNC(uint16_t, Word)
DEFINE_WRITE_MEMORY_REGION_FUNC(uint32_t, Dword)
DEFINE_WRITE_MEMORY_REGION_FUNC(uint64_t, Qword)

DEFINE_COPY_MEMORY_REGION_FUNC(uint8_t, Byte)
DEFINE_COPY_MEMORY_REGION_FUNC(uint16_t, Word)
DEFINE_COPY_MEMORY_REGION_FUNC(uint32_t, Dword)
DEFINE_COPY_MEMORY_REGION_FUNC(uint64_t, Qword)

DEFINE_COMPARE_MEMORY_REGION_FUNC(uint8_t, Byte)
DEFINE_COMPARE_MEMORY_REGION_FUNC(uint16_t, Word)
DEFINE_COMPARE_MEMORY_REGION_FUNC(uint32_t, Dword)
DEFINE_COMPARE_MEMORY_REGION_FUNC(uint64_t, Qword)

DEFINE_ZERO_MEMORY_REGION_FUNC(uint8_t, Byte)
DEFINE_ZERO_MEMORY_REGION_FUNC(uint16_t, Word)
DEFINE_ZERO_MEMORY_REGION_FUNC(uint32_t, Dword)
DEFINE_ZERO_MEMORY_REGION_FUNC(uint64_t, Qword)

DEFINE_SET_MEMORY_REGION_FUNC(uint8_t, Byte)
DEFINE_SET_MEMORY_REGION_FUNC(uint16_t, Word)
DEFINE_SET_MEMORY_REGION_FUNC(uint32_t, Dword)
DEFINE_SET_MEMORY_REGION_FUNC(uint64_t, Qword)

DEFINE_REVERSE_MEMORY_REGION_FUNC(uint8_t, Byte)
DEFINE_REVERSE_MEMORY_REGION_FUNC(uint16_t, Word)
DEFINE_REVERSE_MEMORY_REGION_FUNC(uint32_t, Dword)
DEFINE_REVERSE_MEMORY_REGION_FUNC(uint64_t, Qword)

DEFINE_SWAP_MEMORY_REGIONS_FUNC(uint8_t, Byte)
DEFINE_SWAP_MEMORY_REGIONS_FUNC(uint16_t, Word)
DEFINE_SWAP_MEMORY_REGIONS_FUNC(uint32_t, Dword)
DEFINE_SWAP_MEMORY_REGIONS_FUNC(uint64_t, Qword)

#endif // MEMORY_UTILS_H
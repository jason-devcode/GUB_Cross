/** 
 * @file memory_function_macro_templates.h
 * @brief This file defines macro templates for memory manipulation functions.
 *
 * This header file provides macro templates to generate functions that perform
 * various operations on memory regions of different data types (e.g., uint8_t, uint16_t,
 * uint32_t, uint64_t). The macros allow for the creation of functions to write values,
 * copy memory, compare memory regions, fill memory regions with zeros or a specific value,
 * reverse the bytes in a memory region, and swap the contents of two memory regions.
 *
 * Each macro accepts a type (e.g., uint8_t) and a corresponding type name (e.g., Byte),
 * and generates a function with a specific name pattern (e.g., WriteMemoryRegionByte,
 * CopyMemoryRegionWord). These functions operate on memory regions provided as void pointers,
 * allowing for flexible use across different data types.
 */

#ifndef MEMORY_FUNCTION_MACRO_TEMPLATES
#define MEMORY_FUNCTION_MACRO_TEMPLATES

/**
 * @brief Define a function to write a value of a specified type to a memory region.
 *
 * @param TYPE The type of the value to write (e.g., uint8_t, uint16_t, uint32_t, uint64_t).
 * @param TYPE_NAME The name of the type (e.g., Byte, Word, Dword, Qword).
 *
 * This macro generates a function that writes the specified value to the entire memory region.
 */
#define DEFINE_WRITE_MEMORY_REGION_FUNC(TYPE, TYPE_NAME)                                  \
    /**                                                                                   \
     * @brief Write a TYPE_NAME value to a memory region.                                 \
     *                                                                                    \
     * @param memoryRegion The starting address of the memory region.                     \
     * @param value The TYPE_NAME value to write.                                         \
     * @param sizeInBytes The size of the memory region in bytes.                         \
     *                                                                                    \
     * This function writes the specified value to the entire memory region.              \
     */                                                                                   \
    void WriteMemoryRegion##TYPE_NAME(void *memoryRegion, TYPE value, size_t sizeInBytes) \
    {                                                                                     \
        if (memoryRegion == NULL)                                                         \
            return;                                                                       \
                                                                                          \
        register TYPE *memoryIterator = (TYPE *)memoryRegion;                             \
        register TYPE *endMemoryRegion = (TYPE *)((uint8_t *)memoryRegion + sizeInBytes); \
                                                                                          \
        if (memoryIterator == endMemoryRegion)                                            \
            return;                                                                       \
                                                                                          \
        do                                                                                \
        {                                                                                 \
            *memoryIterator = value;                                                      \
            ++memoryIterator;                                                             \
        } while (memoryIterator < endMemoryRegion);                                       \
    }

/**
 * @brief Define a function to copy a memory region to another memory region.
 *
 * @param TYPE The type of the memory region (e.g., uint8_t, uint16_t, uint32_t, uint64_t).
 * @param TYPE_NAME The name of the type (e.g., Byte, Word, Dword, Qword).
 *
 * This macro generates a function that copies the contents of one memory region to another.
 */
#define DEFINE_COPY_MEMORY_REGION_FUNC(TYPE, TYPE_NAME)                               \
    /**                                                                               \
     * @brief Copy a TYPE_NAME memory region to another TYPE_NAME memory region.      \
     *                                                                                \
     * @param dest The destination memory region.                                     \
     * @param src The source memory region.                                           \
     * @param sizeInBytes The size of the memory region in bytes.                     \
     */                                                                               \
    void CopyMemoryRegion##TYPE_NAME(void *dest, const void *src, size_t sizeInBytes) \
    {                                                                                 \
        if (dest == NULL || src == NULL)                                              \
            return;                                                                   \
                                                                                      \
        register TYPE *d = (TYPE *)dest;                                              \
        register const TYPE *s = (const TYPE *)src;                                   \
        register const TYPE *end = (const TYPE *)((uint8_t *)src + sizeInBytes);      \
                                                                                      \
        while (s < end)                                                               \
        {                                                                             \
            *d++ = *s++;                                                              \
        }                                                                             \
    }

/**
 * @brief Define a function to compare two memory regions.
 *
 * @param TYPE The type of the memory region (e.g., uint8_t, uint16_t, uint32_t, uint64_t).
 * @param TYPE_NAME The name of the type (e.g., Byte, Word, Dword, Qword).
 *
 * This macro generates a function that compares two memory regions.
 */
#define DEFINE_COMPARE_MEMORY_REGION_FUNC(TYPE, TYPE_NAME)                                           \
    /**                                                                                              \
     * @brief Compare two TYPE_NAME memory regions.                                                  \
     *                                                                                               \
     * @param region1 The first memory region.                                                       \
     * @param region2 The second memory region.                                                      \
     * @param sizeInBytes The size of the memory regions in bytes.                                   \
     * @return int 0 if the regions are equal, a negative value if region1 < region2,                \
     * or a positive value if region1 > region2.                                                     \
     */                                                                                              \
    int CompareMemoryRegion##TYPE_NAME(const void *region1, const void *region2, size_t sizeInBytes) \
    {                                                                                                \
        if (region1 == NULL || region2 == NULL)                                                      \
            return -1;                                                                               \
                                                                                                     \
        register const TYPE *r1 = (const TYPE *)region1;                                             \
        register const TYPE *r2 = (const TYPE *)region2;                                             \
        register const TYPE *end = (const TYPE *)((uint8_t *)region1 + sizeInBytes);                 \
                                                                                                     \
        while (r1 < end)                                                                             \
        {                                                                                            \
            if (*r1 != *r2)                                                                          \
                return *r1 - *r2;                                                                    \
            ++r1;                                                                                    \
            ++r2;                                                                                    \
        }                                                                                            \
        return 0;                                                                                    \
    }

/**
 * @brief Define a function to fill a memory region with zeros.
 *
 * @param TYPE The type of the memory region (e.g., uint8_t, uint16_t, uint32_t, uint64_t).
 * @param TYPE_NAME The name of the type (e.g., Byte, Word, Dword, Qword).
 *
 * This macro generates a function that fills a memory region with zeros.
 */
#define DEFINE_ZERO_MEMORY_REGION_FUNC(TYPE, TYPE_NAME)                                   \
    /**                                                                                   \
     * @brief Fill a TYPE_NAME memory region with zeros.                                  \
     *                                                                                    \
     * @param memoryRegion The memory region to fill.                                     \
     * @param sizeInBytes The size of the memory region in bytes.                         \
     */                                                                                   \
    void ZeroMemoryRegion##TYPE_NAME(void *memoryRegion, size_t sizeInBytes)              \
    {                                                                                     \
        if (memoryRegion == NULL)                                                         \
            return;                                                                       \
                                                                                          \
        register TYPE *memoryIterator = (TYPE *)memoryRegion;                             \
        register TYPE *endMemoryRegion = (TYPE *)((uint8_t *)memoryRegion + sizeInBytes); \
                                                                                          \
        while (memoryIterator < endMemoryRegion)                                          \
        {                                                                                 \
            *memoryIterator++ = 0;                                                        \
        }                                                                                 \
    }

/**
 * @brief Define a function to fill a memory region with a specific value.
 *
 * @param TYPE The type of the memory region (e.g., uint8_t, uint16_t, uint32_t, uint64_t).
 * @param TYPE_NAME The name of the type (e.g., Byte, Word, Dword, Qword).
 *
 * This macro generates a function that fills a memory region with a specific value.
 */
#define DEFINE_SET_MEMORY_REGION_FUNC(TYPE, TYPE_NAME)                                    \
    /**                                                                                   \
     * @brief Fill a TYPE_NAME memory region with a specific value.                       \
     *                                                                                    \
     * @param memoryRegion The memory region to fill.                                     \
     * @param value The value to fill the memory region with.                             \
     * @param sizeInBytes The size of the memory region in bytes.                         \
     */                                                                                   \
    void SetMemoryRegion##TYPE_NAME(void *memoryRegion, TYPE value, size_t sizeInBytes)   \
    {                                                                                     \
        if (memoryRegion == NULL)                                                         \
            return;                                                                       \
                                                                                          \
        register TYPE *memoryIterator = (TYPE *)memoryRegion;                             \
        register TYPE *endMemoryRegion = (TYPE *)((uint8_t *)memoryRegion + sizeInBytes); \
                                                                                          \
        while (memoryIterator < endMemoryRegion)                                          \
        {                                                                                 \
            *memoryIterator++ = value;                                                    \
        }                                                                                 \
    }

/**
 * @brief Define a function to reverse the bytes in a memory region.
 *
 * @param TYPE The type of the memory region (e.g., uint8_t, uint16_t, uint32_t, uint64_t).
 * @param TYPE_NAME The name of the type (e.g., Byte, Word, Dword, Qword).
 *
 * This macro generates a function that reverses the bytes in a memory region.
 */
#define DEFINE_REVERSE_MEMORY_REGION_FUNC(TYPE, TYPE_NAME)                        \
    /**                                                                           \
     * @brief Reverse the TYPE_NAME values in a memory region.                    \
     *                                                                            \
     * @param memoryRegion The memory region to reverse.                          \
     * @param sizeInBytes The size of the memory region in bytes.                 \
     */                                                                           \
    void ReverseMemoryRegion##TYPE_NAME(void *memoryRegion, size_t sizeInBytes)   \
    {                                                                             \
        if (memoryRegion == NULL)                                                 \
            return;                                                               \
                                                                                  \
        register TYPE *start = (TYPE *)memoryRegion;                              \
        register TYPE *end = (TYPE *)((uint8_t *)memoryRegion + sizeInBytes) - 1; \
                                                                                  \
        while (start < end)                                                       \
        {                                                                         \
            TYPE temp = *start;                                                   \
            *start = *end;                                                        \
            *end = temp;                                                          \
            start++;                                                              \
            end--;                                                                \
        }                                                                         \
    }

/**
 * @brief Define a function to swap the contents of two memory regions.
 *
 * @param TYPE The type of the memory region (e.g., uint8_t, uint16_t, uint32_t, uint64_t).
 * @param TYPE_NAME The name of the type (e.g., Byte, Word, Dword, Qword).
 *
 * This macro generates a function that swaps the contents of two memory regions.
 */
#define DEFINE_SWAP_MEMORY_REGIONS_FUNC(TYPE, TYPE_NAME)                                \
    /**                                                                                 \
     * @brief Swap the contents of two TYPE_NAME memory regions.                        \
     *                                                                                  \
     * @param region1 The first memory region.                                          \
     * @param region2 The second memory region.                                         \
     * @param sizeInBytes The size of the memory regions in bytes.                      \
     */                                                                                 \
    void SwapMemoryRegions##TYPE_NAME(void *region1, void *region2, size_t sizeInBytes) \
    {                                                                                   \
        if (region1 == NULL || region2 == NULL)                                         \
            return;                                                                     \
                                                                                        \
        register TYPE *r1 = (TYPE *)region1;                                            \
        register TYPE *r2 = (TYPE *)region2;                                            \
        register TYPE temp;                                                             \
                                                                                        \
        for (size_t i = 0; i < sizeInBytes / sizeof(TYPE); i++)                         \
        {                                                                               \
            temp = r1[i];                                                               \
            r1[i] = r2[i];                                                              \
            r2[i] = temp;                                                               \
        }                                                                               \
    }

#endif

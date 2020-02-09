#ifndef CGGML_NUMERICAL_TYPEDEFS_H
#define CGGML_NUMERICAL_TYPEDEFS_H

#include <float.h>
#include <limits.h>

/**
 * This is currently a very naive stdint.h replacement for C90.
 * Will enhance in the future with more definitions for different platforms.
 */

#define INT8_T_MAX CHAR_MAX
typedef signed char int8_t;

#define INT16_T_MAX SHRT_MAX
typedef signed short int16_t;

#define INT32_T_MAX INT_MAX
#define INT32_T_MIN INT_MIN
typedef signed int int32_t;

#define UINT8_T_MAX UCHAR_MAX
typedef unsigned char uint8_t;

#define UINT16_T_MAX USHRT_MAX
typedef unsigned short uint16_t;

#define UINT32_T_MAX UINT_MAX
typedef unsigned int uint32_t;

#define FLOAT32_T_MAX FLT_MAX
typedef float float32_t;

#define FLOAT64_T_MAX DBL_MAX
#define FLOAT64_T_MIN DBL_MIN
typedef double float64_t;

#endif /* CGGML_NUMERICAL_TYPEDEFS_H */

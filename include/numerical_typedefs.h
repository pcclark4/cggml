#ifndef CGGML_NUMERICAL_TYPEDEFS_H
#define CGGML_NUMERICAL_TYPEDEFS_H

#include <float.h>
#include <limits.h>

#define INT8_MAX CHAR_MAX
typedef signed char int8_t;

#define INT16_MAX SHRT_MAX
typedef signed short int16_t;

#define INT32_MAX INT_MAX
typedef signed int int32_t;

#define UINT8_MAX UCHAR_MAX
typedef unsigned char uint8_t;

#define UINT16_MAX USHRT_MAX
typedef unsigned short uint16_t;

#define UINT32_MAX UINT_MAX
typedef unsigned int uint32_t;

#define FLOAT32_MAX FLT_MAX
typedef float float32_t;

#define FLOAT64_MAX DBL_MAX
typedef double float64_t;

#endif // CGGML_NUMERICAL_TYPEDEFS_H

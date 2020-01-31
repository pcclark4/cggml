#ifndef CGGML_SEGMENT_2_H
#define CGGML_SEGMENT_2_H

#include "point_2.h"

struct segment_2
{
    const struct point_2 p1;
    const struct point_2 p2;
};

float64_t segment_2_length(const struct segment_2 *segment);

#endif /* CGGML_SEGMENT_2_H */

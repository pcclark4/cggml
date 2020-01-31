#include "segment_2.h"

float64_t segment_2_length(const struct segment_2 *segment)
{
    return point_2_distance(&segment->p1, &segment->p2);
}

#ifndef NEAREST_NEIGHBOR_EXACT_H
#define NEAREST_NEIGHBOR_EXACT_H

#include <stddef.h>

const void *nearest_neighbor_exact(const void *query, const void *searchSet,
    int searchSetSize, size_t elementSize,
    double (*distanceFunc)(const void *, const void *));

#endif

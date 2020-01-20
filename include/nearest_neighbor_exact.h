#ifndef NEAREST_NEIGHBOR_EXACT_H
#define NEAREST_NEIGHBOR_EXACT_H

const void *nearest_neighbor_exact(const void *query, const void *searchSet,
    int searchSetSize, double (*dissimilarityFunc)(const void *, const void *));

#endif

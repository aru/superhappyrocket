#ifndef MEMORY_H
#define MEMORY_H

// Standard memory management.
#define new0 new

// For 1D arrays:  data[bound0]
template <typename T>
T* new1 (const int bound0);

// For 2D arrays:  data[bound1][bound0]
template <typename T>
T** new2 (const int bound0, const int bound1);

// For 3D arrays:  data[bound2][bound1][bound0]
template <typename T>
T*** new3 (const int bound0, const int bound1, const int bound2);

// For 4D arrays:  data[bound3][bound2][bound1][bound0]
template <typename T>
T**** new4 (const int bound0, const int bound1, const int bound2,
    const int bound3);

// For singletons.
template <typename T>
void delete0 (T*& data);

// For 1D arrays:  data[bound0]
template <typename T>
void delete1 (T*& data);

// For 2D arrays:  data[bound1][bound0]
template <typename T>
void delete2 (T**& data);

// For 3D arrays:  data[bound2][bound1][bound0]
template <typename T>
void delete3 (T***& data);

// For 4D arrays:  data[bound3][bound2][bound1][bound0]
template <typename T>
void delete4 (T****& data);

#include "Memory.inl"

#endif
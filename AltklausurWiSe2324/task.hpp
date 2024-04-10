#ifndef TASK_HPP
#define TASK_HPP
#include <algorithm>
#include <stdexcept>
float get_maximum(float *data, int size);
void initialize_increase(float **data, int size1, int size2, bool increase);
void invert(float **data, int size1, int size2);
void count_pairs(float **data, int size1, int size2, unsigned int numPairs[]);
float *down_sampling(float *data, int size, int M);
#endif // TASK_HPP

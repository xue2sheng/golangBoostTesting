#include "example.h"
#include <numeric>
#include <vector>
#include <iostream>

double mean(int* list, size_t list_size)
{
	if(list == nullptr) { return 0; }
	if(list_size == 0) { return 0; }

	return std::accumulate(list, list + list_size, 0.0) / list_size;
}

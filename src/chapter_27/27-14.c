/*
	chapter 27 exercise 14
	page 1034
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Results {
	int    smallest;
	int    largest;
	double median;
	double mean;
}Results;

int comparator(const void* elem1, const void* elem2)
{
	return (*(int*)elem2) < (*(int*)elem1);
}

Results find_results(int* array, size_t size)
{
	int i;
	Results result = {0,0,0.0,0.0};

	qsort(array,size,sizeof(*array),&comparator);

	result.smallest = *array;
	result.largest  = *(array+size-1);

	for (i = 0; i < size; ++i)
		result.mean += *(array+i);
	result.mean /= size;
	
	if (size % 2)
		result.median = *(array+(size/2));
	else
		result.median = (*(array+(size/2)) + *(array+(size/2-1))) / 2;

	return result;
}

int main(void)
{
	int arr[] = {2,6,10,11,64,45,1,0,51,20,15,65};

	Results result = find_results(arr,sizeof(arr)/sizeof(*arr));

	printf("The smallest element is: %d\n", result.smallest);
	printf("The largest element is: %d\n", result.largest);
	printf("The median is: %g\n", result.median);
	printf("The mean is: %g\n", result.mean);

	return 0;
}

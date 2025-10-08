/*
#include <stdio.h>
*/
#include <stdlib.h>
void *calloc(size_t nmemb, size_t size);
void *callocc(size_t nmemb, size_t size)
{
	int *array;
	long unsigned int cnt;

	if (nmemb ==0 || size == 0)
		return ((void*)malloc(1 * sizeof(int)));
	cnt = 0;
	array = malloc(nmemb * size);
	while(nmemb > cnt)
	{
		array[cnt] = 0;
		cnt++;
	}
	return ((void*)array);
}
/*
int main(void)
{
	int size = 0;
	int *rtnarray;
	int i = 0;

	rtnarray = callocc(size, sizeof(int));
	printf("result =");
	while (size > i)
	{
		printf(" %d", rtnarray[i]);
		i++;
	}
	free(rtnarray);
	rtnarray = NULL;
	return (0);
}
*/

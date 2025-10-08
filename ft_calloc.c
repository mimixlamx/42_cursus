/*
#include <stdio.h>
*/
#include <stdlib.h>
void *calloc(size_t n, size_t size);
void *calloc(size_t n, size_t size)
{
	int *array;
	long unsigned int cnt;

	cnt = 0;
	array = malloc(n * size);
	while(n > cnt)
	{
		array[cnt] = 0;
		cnt++;
	}
	return ((void*)array);
}
/*
int main(void)
{
	int size = 10;
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

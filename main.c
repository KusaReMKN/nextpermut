#include <stdio.h>
#include "permut.h"

static int
compar(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int
main(void)
{
	int v[] = { 1, 2, 2, 3 };
	do {
		for (int i = 0; i < sizeof(v)/sizeof(v[0]); i++)
			printf("%d ", v[i]);
		printf("\n");
	} while (nextpermut(v, sizeof(v)/sizeof(v[0]), sizeof(v[0]), compar));

	return 0;
}

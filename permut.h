#ifndef PERMUT_H
#define PERMUT_H	1

#include <stddef.h>

int
nextpermut(void *base, size_t nmemb, size_t size,
		int (*compar)(const void *, const void *));

#endif	/* !PERMUT_H */

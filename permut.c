#include <stddef.h>

static inline void
swap(char *restrict a, char *restrict b, size_t s)
{
	char t;

	while (s-- > 0) {
		t = *a;
		*a++ = *b;
		*b++ = t;
	}
}

int
nextpermut(void *base, size_t nmemb, size_t size,
		int (*compar)(const void *, const void *))
{
	size_t i, j;

	if (nmemb < 2)
		return 0;

	for (i = nmemb-1; i-- > 0; )
		if ((*compar)(base + size*(i+0), base + size*(i+1)) < 0)
			goto foundi;
	return 0;
foundi:
	for (j = nmemb; j-- > i; )
		if ((*compar)(base + size*i, base + size*j) < 0)
			goto foundj;
	return 0;
foundj:
	swap(base + size*i, base + size*j, size);
	for (i = i+1, j = nmemb-1; i < j; i++, j--)
		swap(base + size*i, base + size*j, size);

	return 1;
}

#ifndef QUICK_H
# define QUICK_H
	
#include <stdlib.h>
#include <stdio.h>

int	quick_sort(void **items, int size, int (*cmp)(void *, void *));

#endif

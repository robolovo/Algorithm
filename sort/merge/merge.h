#ifndef MERGE_H
# define MERGE_H

#include <stdio.h>
#include <stdlib.h>

int	merge_sort(void **items, int size, int (*cmp)(void *, void *));

#endif

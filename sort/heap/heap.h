#ifndef HEAP_H
# define HEAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct		s_heap
{
	unsigned int	max_size;
	unsigned int	size;
	int				(*cmp)(void *, void *);
	void			**data;
}					t_heap;

int		heap_sort(
				void **items,
				int size,
				int (*cmp)(void *, void *));

#endif

#ifndef HEAP_H
# define HEAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct	s_heap
{
 	unsigned int	max_size;
 	unsigned int	size;
 	int				(*cmp)(void *, void *);
 	void			**data;
}					t_heap;

t_heap *heap_init(unsigned int max_size, int (*cmp)(void *, void *));
int heap_push(t_heap *heap, void *data);
void *heap_peek(t_heap *heap);
void *heap_pop(t_heap *heap);
void free_heap(t_heap *heap, void (*free_data)(void *));

#endif

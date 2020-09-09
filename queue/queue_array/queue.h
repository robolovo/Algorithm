#ifndef QUEUE_H
# define QUEUE_H
# include <stdlib.h>

typedef struct		s_queue
{
	unsigned int	max_size;
	int				last_index;
	void			**data;
}					t_queue;

#endif

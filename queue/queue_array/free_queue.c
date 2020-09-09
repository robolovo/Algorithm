#include "list.h"

void	free_queue(t_queue *queue, void(free_data *)(void *))
{	
	if (queue == 0 || free_data == 0)
		return ;
	queue_clear(queue, free_data);	
	free(queue->data);
	free(queue);
}

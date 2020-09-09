#include "queue.h"

void	queue_clear(t_queue *queue, void(free_data *)(void *))
{
	int	i;

	if (!queue || !free_data)
		return ;
	i = 0;
	while (i <= last_index)
	{
		free_data(queue->data[i]);
		i++;
	}
}

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				top_index;
	char			*data;
}					t_stack;

t_stack	*stack_init()
{
	t_stack *stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	stack->top_index = -1;
	stack->data = malloc(sizeof(char) * 101);
	return (stack);
}

int	stack_pop(t_stack *stack, char c)
{
    if((c == ')' && stack->data[stack->top_index] == '(') ||
       (c == ']' && stack->data[stack->top_index] == '['))
    {
		stack->top_index--;
		return (1);
    }
	else
		return (0);
}

void	stack_push(t_stack *stack, char c)
{
	stack->top_index++;
	stack->data[stack->top_index] = c;
}

int main(void)
{
	t_stack *stack;
	size_t 	n;
	char 	*str;
	int		i;
	int		ret;

	str = malloc(sizeof(char) * 101);
	while (1)
	{
		stack = stack_init();
		i = 0;
		ret = 1;
		getline(&str, &n, stdin);
		if(str[0] == '.')
			break;
		while (str[i] != '.') 
		{
			if(str[i]=='(' || str[i] == '[')
				stack_push(stack, str[i]);
			if(str[i]==')' || str[i] == ']')
			{ 
				ret = stack_pop(stack, str[i]);
				if (ret == 0)
					break;	
			}
			i++;
		}
		if (stack->top_index == -1 && ret)
			printf("YES\n");
		else
			printf("NO\n");
		free(stack);
	}
	free(str);
	return (0);
}

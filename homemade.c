#include "push_swap.h"

void	easyway(t_stack *stacka, t_stack *stackb)
{
	while (sorted(stacka))
	{
		if (stack_peek(stacka) > stacka->array[stacka->top - 1])
			pw_swap(stacka, stackb, 'a');
		if (stacka->array[1] > stacka->array[0])
			pw_revers_rotate(stacka, stackb, 'a');
	}
}

static void	small_spread(t_stack *stacka, t_stack *stackb, int find)
{
	int	i;
	int	j;

	i = stacka->top;
	j = 0;
	while (stacka->array[i] != find)
		i--;
	while (stacka->array[j] != find)
		j++;
	if (stacka->top - i > ++j)
		while (j--)
			pw_revers_rotate(stacka, stackb, 'a');
	else
		while (i++ < stacka->top)
			pw_rotate(stacka, stackb, 'a');
	if (stack_peek(stacka) == find)
		pw_push(stacka, stackb, 'b');
}

void	homemade(t_stack *stacka, t_stack *stackb)
{
	int	i;

	i = 0;
	while (stackb->top != (int)stackb->capacity - 4)
		small_spread(stacka, stackb, i++);
	easyway(stacka, stackb);
	while (!stack_empty(stackb))
		pw_push(stacka, stackb, 'a');
}

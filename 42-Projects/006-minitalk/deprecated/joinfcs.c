static void blem(t_msg *node, int sig)
{
	if (!node->msg)
	{
		if (!node->len)
			node->msg = &node->msg_size[0];
		else
			node->msg = ft_calloc(node->len + 1, sizeof(char));
		node->bit = 7;    
	}
	if (sig == SIGUSR1)
		node->c |= (1 << node->bit);
	node->bit--;
	if (node->bit < 0 && node->c)
	{
		*node->msg = node->c;
		node->msg++;
		node->c = 0;
		node->bit = 7;
	}
	else if (node->bit < 0 && !node->c)
	{
		if (!node->len)
		{
			node->len = ft_atoi(node->msg_size);
			node->msg = NULL;
			node->bit = 0;
		}
		else
		{
			node->msg -= node->len;
			ft_printf("%s\n", node->msg);
			free(node->msg);
			*node = (t_msg){0};
		}
	}
}


static void	find_len(t_msg *node, int sig)
{
	if (!node->msg)
	{
		node->msg = &node->msg_size[0];
		node->bit = 7;
	}
	if (sig == SIGUSR1)
		node->c |= (1 << node->bit);
	node->bit--;
	if (node->bit < 0 && node->c)
	{
		*node->msg = node->c;
		node->msg++;
		node->c = 0;
		node->bit = 7;
	}
	else if (node->bit < 0 && !node->c)
	{
		node->len = ft_atoi(node->msg_size);
		node->msg = NULL;
		node->bit = 0;
	}
}

static void	decode_msg(t_msg *node, int sig)
{
	if (!node->msg)
	{
		node->msg = ft_calloc(node->len + 1, sizeof(char));
		node->bit = 7;
	}
	if (sig == SIGUSR1)
		node->c |= (1 << node->bit);
	node->bit--;
	if (node->bit < 0 && node->c)
	{
		*node->msg = node->c;
		node->msg++;
		node->c = 0;
		node->bit = 7;
	}
	else if (node->bit < 0 && !node->c)
	{
		node->msg -= node->len;
		ft_printf("%s\n", node->msg);
		free(node->msg);
		*node = (t_msg){0};
	}
}
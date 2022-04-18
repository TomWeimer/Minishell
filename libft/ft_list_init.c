t_list *ft_list_init (void)
{
	t_list *list;
	t_node *node;

	list = malloc(sizeof(t_list));
	node = malloc(sizeof(t_node));
	if (!list || !node)
		return(NULL);
	node->data = 0;
	node->next = NULL;
	list->first = node;
	return (list); 
}

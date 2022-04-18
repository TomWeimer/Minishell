void ft_add_new_node_back(t_list *list, char new_data)
{
	t_node *new;
	t_node *actual;
	
	new = malloc (sizeof(t_node));
	if (!list || !new)
	{
		printf("erreur");
		return ;
	}
	actual = list->first;
	while(actual->next != NULL)
		actual = actual->next;
	actual->next = new;
	new->data = new_data;
	new->next = NULL;
}

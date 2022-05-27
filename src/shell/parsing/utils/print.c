/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:49:00 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/27 13:49:01 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"
//#include "../../../includes/binary_tree.h"

//# define COUNT 10
/*
int ft_lstlen(t_group *list)
{
	t_token *actual;
	int	lenght;

	lenght = 0;
	actual = list->first;
	while (actual != NULL)
	{
		lenght++;
		actual = actual->next;
	}
	return (lenght);
}

// It does reverse inorder traversal

void print2DUtil(t_tree *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
	if (root != NULL && root->token != NULL)
	{
		if (root->token->type == AND_IF)
			printf("&&");
		else if (root->token->type == OR_IF)
			printf("||");
		else if (root->token->type == PIPE)
			printf("|");
	}


    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(t_tree *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

void printlst_all_cmd(t_command **all_command)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (all_command[i] != NULL)
	{
		printf("command[%i]\n", i);
		printf("cmd_name: %s\n", all_command[i]->cmd);
		while(all_command[i]->args[j] != NULL)
		{
			printf("	args[%d]: %s\n", j,	all_command[i]->args[j]);
			j++;
		}
		j = 0;

		t_redirection *actual;
		printf("	input:\n");
		if (all_command[i]->input != NULL)
		{
			actual = all_command[i]->input;
			while(actual != NULL)
			{
				if (actual->type == LESS)
					printf("		< %s", actual->file_name);
				else if (actual->type == DLESS)
					printf("		<< %s", actual->file_name);
				actual = actual->next;
			}
		}
		else
			printf("NONE\n");
			printf("	output:\n");
		if (all_command[i]->output != NULL)
		{
			actual = all_command[i]->output;
			while(actual != NULL)
			{
				if (actual->type == MORE)
					printf("		> %s\n", actual->file_name);
				else if (actual->type == DGREAT)
					printf("		>> %s\n", actual->file_name);
				actual = actual->next;
			}
		}
		else
			printf("NONE\n");
		printf("END INFO CMD\n\n");
		i++;
	}
}

void printlst_token(t_group *list)
{
	t_token *actual;
	actual = list->first;
	int i = 0;

	actual = list->first;
	printf("\033[32mSTART \033[0m\n");
	printf("\n\033[33mToken type:\033[0m\n	");
	while (actual != NULL)
	{
		if (actual->type == AND_IF)
			printf("&&");
		else if (actual->type == OR_IF)
			printf("||");
		else if (actual->type == PIPE)
			printf("|");
		else if (actual->type == WORD)
			printf("WORD");
		else if (actual->type == DLESS)
			printf("<<");
		else if (actual->type == LESS)
			printf("<");
		else if (actual->type == DGREAT)
			printf(">>");
		else if (actual->type == MORE)
			printf(">");
		else if (actual->type == INFILE)
			printf("INFILE");
		else if (actual->type == OUTFILE)
			printf("OUTFILE");
		else if (actual->type == CMD)
			printf("CMD");
		else if (actual->type == PARAM)
			printf("PARAM");
		else
			printf("%d", actual->type);
		printf(" ");
		actual = actual->next;
	}
	printf("-> NULL\n");
	actual = list->first;
	printf("\n\033[33mWord contents:\033[0m\n");
	while (actual != NULL)
	{
		if (actual->type == AND_IF)
			printf("	actual->words[%d]: && \n", i);
		else if (actual->type == OR_IF)
			printf("	actual->words[%d]: || \n", i);
		else if (actual->type == PIPE)
			printf(" 	actual->words[%d]: | \n", i);
		else if (actual->type == DLESS)
			printf(" 	actual->words[%d]: << \n", i);
		else if (actual->type == LESS)
			printf("	actual->words[%d]: < \n", i);
		else if (actual->type == DGREAT)
			printf("	actual->words[%d]: >> \n", i);
		else if (actual->type == MORE)
			printf("	actual->words[%d]: > \n", i);
		else
			printf("	actual->words[%d]: ]%s[\n",i, actual->word);
		actual = actual->next;
		i++;
	}
	//printf("actual->words[%d]: ",i);
	printf("\033[31mEND \033[0m \n");
	
}

void printlst(t_group *list)
{
	t_token *actual;
	if (!list)
	{
		printf("list: (null)\n");
		return ;
	}
	actual = list->first;
	while (actual != NULL)
	{
		if (actual->type == AND_IF)
			printf("&&");
		else if (actual->type == OR_IF)
			printf("||");
		else if (actual->type == PIPE)
			printf("|");
		else if (actual->type == WORD)
			printf("WORD");
		else if (actual->type == DLESS)
			printf("<<");
		else if (actual->type == LESS)
			printf("<");
		else if (actual->type == DGREAT)
			printf(">>");
		else if (actual->type == MORE)
			printf(">");
		else if (actual->type == INFILE)
			printf("INFILE");
		else if (actual->type == OUTFILE)
			printf("OUTFILE");
		else if (actual->type == CMD)
			printf("CMD");
		else if (actual->type == PARAM)
			printf("PARAM");
		else
			printf("%d", actual->type);
		printf(" ");
		actual = actual->next;
	}
	printf("-> NULL\n");
}
*/
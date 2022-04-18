/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:05:10 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/25 18:13:14 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_signal(t_signal *sa, void *ptr_function)
{
	sa->sa_handler = ptr_function;
	sa->sa_flags = SA_RESTART;
	return ;
}

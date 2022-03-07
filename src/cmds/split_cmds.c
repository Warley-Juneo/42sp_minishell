/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:04:07 by glima-de          #+#    #+#             */
/*   Updated: 2022/03/05 17:02:06 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"

static void setup_cmd(t_cmds *cmds, char *str)
{
	char **aux;
	char *str_nominnor;
	int i_minus;
	int args;

	args = 0;
	i_minus = has_minnor_signal(str);
	if (i_minus > -1)
	{
		if (cmds->file_in)
			free(cmds->file_in);
		cmds->file_in = ft_strtrim(&str[i_minus + 1], " ");
		if (i_minus == 0)
		{
			return;
		}
		else
		{
			str_nominnor = ft_calloc(sizeof(char), i_minus + 1);
			ft_strlcpy(str_nominnor, str, i_minus);

			aux = ft_split(str_nominnor, ' ');
			free(str_nominnor);
		}
	}
	else
	{
		aux = ft_split(str, ' ');
	}
	t_cmd *cmd;
	cmd = malloc(sizeof(t_cmd));
	cmd->bin = ft_strdup(aux[0]);
	while (aux[args])
		args++;
	cmd->parans = malloc((args + 1) * sizeof(char *));
	args = 1;
	while (aux[args])
	{
		cmd->parans[args] = ft_strdup(aux[args]);
		free(aux[args]);
		args++;
	}
	free(aux[0]);
	cmd->parans[args] = NULL;
	cmd->parans[0] = "";
	free(aux);
	if (cmds->qty == 0)
		cmds->first_cmd = cmd;
	else
		cmds->last_cmd->next = cmd;
	cmds->last_cmd = cmd;
	cmds->qty++;
}

void split_cmds(t_cmds *cmds, char *str)
{
	char **aux;
	int i;

	i = 0;
	aux = ft_split(str, '|');

	while (aux[i])
	{
		setup_cmd(cmds, aux[i]);
		free(aux[i]);
		i++;
	}
	free(aux);
}
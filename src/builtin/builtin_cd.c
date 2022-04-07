/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:29:38 by glima-de          #+#    #+#             */
/*   Updated: 2022/04/06 20:33:30 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cmds/cmds.h"

// sempre que atualizarmos o cd atual, também atualizar o OLDPWD.
void	builtin_cd(t_cmd *btin)
{
	int		chreturn;
	char	oldpdw[255];

	getcwd(oldpdw, 255);
	if ((btin->parans[1] == NULL || strncmp(btin->parans[1], "~", 1) == 0))
		chreturn = chdir(getenv("HOME"));
	else if (strncmp(btin->parans[1], "-", 1) == 0)
		chreturn = chdir(getenv("OLDPWD"));
	else if (strncmp(btin->parans[1], "..", 2) == 0)
		chreturn = chdir("..");
	else if (strncmp(btin->parans[1], ".", 1) == 0)
		chreturn = chdir(".");
	else
		chreturn = chdir(btin->parans[1]);
	if (chreturn == -1)
	{
		fprintf(stderr, "cd: %s: No such file or directory\n", btin->parans[1]);
	}

	// setenv OLDPWD
}

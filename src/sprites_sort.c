/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:08:01 by yoguchi           #+#    #+#             */
/*   Updated: 2021/01/03 23:23:54 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void			quick_sort(t_sprite **spr_tab, int start, int end)
{
	t_sprite	*tmp;
	float		piv;
	int			left;
	int			right;

	piv = spr_tab[(int)((start + end) / 2)]->dist;
	left = start;
	right = end;
	while (1)
	{
		while (spr_tab[left]->dist > piv)
			left++;
		while (piv > spr_tab[right]->dist)
			right--;
		if (right <= left)
			break ;
		tmp = spr_tab[left];
		spr_tab[left++] = spr_tab[right];
		spr_tab[right--] = tmp;
	}
	if (start < left - 1)
		quick_sort(spr_tab, start, left - 1);
	if (right + 1 < end)
		quick_sort(spr_tab, right + 1, end);
}

static bool		optimize_sprites_list(t_game *game,
										t_sprite **spr_tab, int spr_nm)
{
	int i;

	game->sprites.sprite = spr_tab[0];
	i = 0;
	while (++i < spr_nm)
	{
		spr_tab[i - 1]->next = spr_tab[i];
		spr_tab[i]->prev = spr_tab[i - 1];
		spr_tab[i]->next = (i < spr_nm - 1) ? spr_tab[i + 1] : NULL;
	}
	return (true);
}

bool			sprites_sort(t_game *game)
{
	t_sprite	**spr_tab;
	t_sprite	*tmp;
	int			spr_nm;
	int			i;

	spr_nm = 0;
	tmp = game->sprites.sprite;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		spr_nm++;
	}
	if ((spr_tab = (t_sprite **)ft_calloc(spr_nm, sizeof(t_sprite *))) == NULL)
		return (put_errors(ERR_MALLOC_FAILED, "sprites_sort"));
	tmp = game->sprites.sprite;
	i = 0;
	while (tmp != NULL)
	{
		spr_tab[i++] = tmp;
		tmp = tmp->next;
	}
	quick_sort(spr_tab, 0, spr_nm - 1);
	optimize_sprites_list(game, spr_tab, spr_nm);
	ft_free_and_set_null(spr_tab);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:54:10 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/23 04:55:00 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_img		*get_projection_tex(bool down, 
						bool right, bool hit_vert, t_texture *tex)
{
	if (down == true && right == true && hit_vert == false)
		return (&(tex->wall_ea));
	else if (down == true && right == true && hit_vert == false)
		return (&(tex->wall_so));
	else if (down == true && right == false && hit_vert == true)
		return (&(tex->wall_we));
	else if (down == true && right == false && hit_vert == false)
		return (&(tex->wall_so));
	else if (down == false && right == true && hit_vert == true)
		return (&(tex->wall_ea));
	else if (down == false && right == true && hit_vert == false)
		return (&(tex->wall_no));
	else if (down == false && right == false && hit_vert == true)
		return (&(tex->wall_we));
	return ((&tex->wall_no));
}

static void			get_texture_pixsel_color(t_game *game, int x,
													t_projection *prj)
{
	t_ray			*ray;
	float			propotion;

	ray = game->rays.ray[x];
	if (ray->wall_hit_vertical)
		propotion = ((int)ray->wall_intercept_y % TILE_SIZE) / TILE_SIZE;
	else
		propotion = ((int)ray->wall_intercept_x % TILE_SIZE) / TILE_SIZE;
	prj->tex_offset_x = floor(prj->tex->width * propotion);
}

static void			set_projection_variables(t_game *game, int x,
													t_projection *prj)
{
	t_mlx_window	*window;
	t_player		*player;
	t_ray			*ray;
	float			dist_prj_plane;

	window = &(game->mlx.window);
	player = &(game->player);
	ray = game->rays.ray[x];
	dist_prj_plane =  ((window->width / 2) / tan(FOV_ANGLE / 2));
	prj->perp_dist = ray->dist * cos(ray->angle - player->rotation_angle);
	prj->wall_height = (TILE_SIZE / prj->perp_dist) * dist_prj_plane;
	prj->wall_strip_height = (int)prj->wall_height;
	prj->wall_top_px = (window->height / 2) - (prj->wall_strip_height / 2);
	prj->wall_top_px = (prj->wall_top_px < 0) ? 0 : prj->wall_top_px;
	prj->wall_bottom_px = (window->height / 2) + (prj->wall_strip_height / 2);
	if (prj->wall_bottom_px > window->height)
		prj->wall_bottom_px = window->height;
	prj->tex = get_projection_tex(ray->is_facing_down,
		ray->is_facing_right, ray->wall_hit_vertical, &(game->texture));
	get_texture_pixsel_color(game, x, prj);

	// window = &(game->mlx.window);
	// player = &(game->player);
	// ray = game->rays.ray[x];
	// dist_prj_plane =  ((window->width / 2) / tan(FOV_ANGLE / 2));
	// // 	perpDistance = rays[x].distance * cos(rays[x].rayAngle - player.rotationAngle); /* 壁のゆがみを補正するため、画面平面と垂直な直線の長さに直す */
	// prj->perp_dist = ray->dist * cos(ray->angle - player->rotation_angle);
	// // 	projectedWallHeight = (TILE_SIZE / perpDistance) * DIST_PROJ_PLANE; /* 描画する壁の高さ */
	// prj->wall_height = (TILE_SIZE / prj->perp_dist) * dist_prj_plane;
	// // 	wallStripHeight = (int)projectedWallHeight;
	// prj->wall_strip_height = (int)prj->wall_height;
	// // 	wallTopPixel = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2); /* 画面の高さの中心から、描画する壁の高さの半分だけ上にずらすと、壁の一番上の位置のピクセルがわかる */
	// prj->wall_top_px = (window->height / 2) - (prj->wall_strip_height / 2);
	// // 	wallTopPixel = (wallTopPixel < 0) ? 0 : wallTopPixel; /* 画面領域からはみ出す場合は0に直す */
	// prj->wall_top_px = (prj->wall_top_px < 0) ? 0 : prj->wall_top_px;
	// // 	wallBottomPixel = (WINDOW_HEIGHT / 2) + (wallStripHeight / 2);
	// prj->wall_bottom_px = (window->height / 2) + (prj->wall_strip_height / 2);
	// // 	wallBottomPixel = (wallBottomPixel > WINDOW_HEIGHT) ? WINDOW_HEIGHT : wallBottomPixel; /* 画面領域からはみ出す場合は0に直す */
	// if (prj->wall_bottom_px > window->height)
	// 	prj->wall_bottom_px = window->height;
	
	// // 	/* ぶつかった壁のインデックスの値を見て、参照するテクスチャを決定する */
	// // 	texNum = rays[x].wallHitContent - 1;
    // //     texture_width = wallTextures[texNum].width;
    // //     texture_height = wallTextures[texNum].height;
	// prj->tex_data = get_projection_tex_data(ray->is_facing_down,
	// 	ray->is_facing_right, ray->wall_hit_vertical, &(game->texture));

	// // 	/* 今回のrayにおけるテクスチャの参照位置を、壁との交点座標から得る */
	// // 	if (rays[x].wasHitVertical)
	// // 		textureOffsetX = (int)rays[x].wallHitY % TILE_SIZE; /* TILE_SIZEとTEXTURE_HEIGHTは同じ値で設定しているので、余りを取るとテクスチャ1枚分の座標位置がわかる */
	// if (ray->wall_hit_vertical)
	// 	prj->texture_offset_x = (int)ray->wall_intercept_y % TILE_SIZE;
	// // 	else
	// // 		textureOffsetX = (int)rays[x].wallHitX % TILE_SIZE;
	// else
	// 	prj->texture_offset_x = (int)ray->wall_intercept_x % TILE_SIZE;

}

static void			set_tex_color(t_game *game, t_projection *prj,
														int x, int y)
{
	t_img			*frame;

	frame = game->frame;
	if (y < prj->wall_top_px)
		image_put_pixel_color(frame, x, y, game->map.ceil_color);
	else if (prj->wall_top_px <= y && y < prj->wall_bottom_px)
	{
		prj->distance_from_top = y - ((game->mlx.window.height / 2)
										- (prj->wall_strip_height / 2));
		prj->tex_offset_y = (int)(prj->distance_from_top
				* ((float)prj->tex->height / prj->wall_strip_height));
		prj->texture_px_color = prj->tex->data[
			(prj->tex->width * prj->tex_offset_y) * prj->tex_offset_x];
		if (game->rays.ray[x]->wall_hit_vertical)
			color_change_intensity(&(prj->texture_px_color), 0.65);
		image_put_pixel_color(frame, x, y, prj->texture_px_color);
	}
	else
		image_put_pixel_color(frame, x, y, game->map.floor_color);
}

void				render_fov(t_game *game)
{
	int				x;
	int				y;
	t_projection	prj;

	x = 0;
	while (x < game->rays.num)
	{
		set_projection_variables(game, x, &prj);
		y = 0;
		while (y < game->mlx.window.height)
		{
			set_tex_color(game, &prj,  x, y);
			y++;
		}
		x++;
	}
	return ;

	// 	// int x;
	// int				x;
	// // int y;
	// int			y;
	// t_projection	prj;

	// // x = 0;
	// x = 0;
	// // while(x < NUM_RAYS)
	// // {
	// while (x < game->rays.num)
	// {
	// 	set_projection_variables(game, x, &prj);

	// // 	/* 画面の上端から壁の下端まで、colorBufferの値を変更する */
	// // 	y = 0;
	// 	y = 0;
	// // 	while(y < WINDOW_HEIGHT)
	// // 	{
	// 	while (y < game->mlx.window.height)
	// 	{
	// // 		if (y < wallTopPixel)
	// // 			drawPixel(x, y, 0xff333333);
	// // 			// colorBuffer[(WINDOW_WIDTH * y) + x] = 0xff333333;
	// 		if (y < prj.wall_top_px)
	// 			image_put_pixel_color(game->frame, x, y, game->map.ceil_color);
	// // 		else if (wallTopPixel <= y && y < wallBottomPixel)
	// // 		{
	// 		else if (prj.wall_top_px <= y && y < prj.wall_bottom_px)
	// 		{
	// // 			/* 描画する壁の高さが画面の高さを超えている(画面からはみ出す)場合、テクスチャ上の参照すべきy座標ははみ出す分だけ下にずれていなければならない */
	// // 			/* distanceFromTopに、はみ出し部分を考慮したy座標を保持する */
	// // 			/* distanceFromTop = (今回描画するピクセルのy座標) - ( 壁の描画開始位置(調整していないのでマイナスの値になる場合あり) ) */
	// // 			distanceFromTop = y - ( (WINDOW_HEIGHT / 2) - (wallStripHeight / 2) );
	// 			prj.distance_from_top = y - ((game->mlx.window.height / 2)
	// 											- (prj.wall_strip_height / 2));

	// // 			/* wallStripHeightは、壁との交点の位置の距離によって伸縮する */
	// // 			/* wallStripHeight(描画する壁の高さ)でtexture_heightを割った比率をかけてやることで、テクスチャ上のピクセルの位置がわかる */
	// // 			textureOffsetY = (int)((distanceFromTop) * ( (float)texture_height / wallStripHeight ));
	// 			prj.tex_offset_y = (int)(prj.distance_from_top
	// 					* ((float)prj.tex->height / prj.wall_strip_height));

	// // 			texture_pixel_color = wallTextures[texNum].texture_buffer[(texture_width * textureOffsetY) + textureOffsetX];
	// 			prj.texture_px_color = prj.tex->data[
	// 				(prj.tex->width * prj.tex_offset_y) * prj.tex_offset_x];

	// // 			/* rayが縦軸方向のグリッドに当たった場合、描画色を暗くする */
	// // 			if (rays[x].wasHitVertical)
	// // 				changeColorIntensity(&texture_pixel_color, 0.65);
	// 			if (game->rays.ray[x]->wall_hit_vertical)
	// 				color_change_intensity(&(prj.texture_px_color), 0.65);
	// // 			drawPixel(x, y, texture_pixel_color);
	// 			image_put_pixel_color(game->frame, x, y, prj.texture_px_color);
	// // 			// colorBuffer[(WINDOW_WIDTH * y) + x] = texture_pixel_color;
	// 		}
	// // 		}
	// // 		else
	// // 			drawPixel(x, y, 0xff777777);
	// 		else
	// 			image_put_pixel_color(game->frame, x, y, game->map.floor_color);
	// // 			// colorBuffer[(WINDOW_WIDTH * y) + x] = 0xff777777;
	// // 		y++;
	// 		y++;
	// // 	}
	// 	}
	// // 	x++;
	// 	x++;
	// // }
	// }

	// return ;
}
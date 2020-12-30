/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_has_horz_wall_interception.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 05:05:43 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/29 23:19:16 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_horz_wall_interseption(t_ray *ray, t_map map,
				float intercept[2], float step[2])
{
	float	next[2];
	float	check[2];

	next[TABINDEX_X] = intercept[TABINDEX_X];
	next[TABINDEX_Y] = intercept[TABINDEX_Y];
	while (map_contain_the_coordinate(next[TABINDEX_X], next[TABINDEX_Y], map))
	{
		check[TABINDEX_X] = next[TABINDEX_X];
		check[TABINDEX_Y] = next[TABINDEX_Y] + ((ray->is_facing_down) ? 0 : -1);
		if (map_has_wall_at(check[TABINDEX_X], check[TABINDEX_Y], &map))
		{
			ray->has_horz_interception = true;
			ray->horz_wall_intercept_x = next[TABINDEX_X];
			ray->horz_wall_intercept_y = next[TABINDEX_Y];
			break ;
		}
		else
		{
			next[TABINDEX_X] += step[TABINDEX_X];
			next[TABINDEX_Y] += step[TABINDEX_Y];
		}
	}
}

void		ray_has_horz_wall_interception(t_ray *ray, t_player player,
									t_map map, float ray_angle)
{
	float	intercept[2];
	float	step[2];

	intercept[TABINDEX_Y] = floor(player.y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_down)
		intercept[TABINDEX_Y] += TILE_SIZE;
	intercept[TABINDEX_X] = player.x + ((intercept[TABINDEX_Y] - player.y)
															/ tan(ray_angle));
	step[TABINDEX_Y] = ray->is_facing_down ? TILE_SIZE : -TILE_SIZE;
	step[TABINDEX_X] = TILE_SIZE / tan(ray_angle);
	if (ray->is_facing_right && step[TABINDEX_X] < 0)
		step[TABINDEX_X] = -step[TABINDEX_X];
	else if (!(ray->is_facing_right) && step[TABINDEX_X] > 0)
		step[TABINDEX_X] = -step[TABINDEX_X];
	ray->has_horz_interception = false;
	set_horz_wall_interseption(ray, map, intercept, step);
	if (ray->has_horz_interception == true)
		ray->horz_wall_dist = distance_between_points(
			player.x,
			player.y,
			ray->horz_wall_intercept_x,
			ray->horz_wall_intercept_y);
	else
		ray->horz_wall_dist = FLT_MAX;
}






// {
// 	float	intercept[2];
// 	float	next[2];
// 	float	step[2];
// 	float	check[2];

// 	// /* ----- 1. グリッドの横罫線とrayの交点での、壁との距離を計算する ----- */
// 	printf("[%d]has_horz_interception: %d\n", strip_id, ray[strip_id].has_horz_interception);
// 	printf("[%d]horz_wall_content: %d\n", strip_id, ray[strip_id].horz_wall_content);
// 	printf("[%d]horz_wall_intercept_x: %c\n", strip_id, ray[strip_id].horz_wall_intercept_x);
// 	printf("[%d]horz_wall_intercept_y: %c\n", strip_id, ray[strip_id].horz_wall_intercept_y);
// 	printf("\n");
// 	// bool foundHorzWallHit = false;
// 	// int horzWallContent = 0;
// 	// float horzWallHitX = 0;
// 	// float horzWallHitY = 0;

// 	// /* プレイヤーの座標と向きから、最も近い横罫線との交点のy座標を取得する */
// 	// yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE; /* TILE_SIZEで除算して、何本目の罫線と交点を持つかがわかる。floorで整数に直してから、タイルの大きさを乗じてグリッドとの交点を求める */
// 	intercept[TABINDEX_Y] = floor(player.y / TILE_SIZE) * TILE_SIZE;
// 	// if (isRayFacingDown){ /* rayが下方向に伸びてている時、プレイヤーの座標よりも下にある罫線との交点のy座標を取らなければならないので… TILE_SIZEを加算して、yinterseptを一つ下のグリッドの座標にする */
// 	// 	yintercept += TILE_SIZE;
// 	// }
// 	if (ray[strip_id].is_facing_down)
// 		intercept[TABINDEX_Y] += TILE_SIZE;

// 	// /* 同じく、最も近い横罫線との交点のx座標を取得する */
// 	// xintercept = player.x + ((yintercept - player.y) / tan(rayAngle));
// 	intercept[TABINDEX_X] = player.x + ((intercept[TABINDEX_Y] - player.y)
// 															 / tan(ray_angle));

// 	// /* 次の交点を取得するために、x座標とy座標のそれぞれの増加分(xstep, ystep)を保持する */
// 	// ystep = (isRayFacingDown) ? TILE_SIZE : -TILE_SIZE; /* rayが下方向のとき、TILE_SIZEを加算し、上方向のときはTILE_SIZEを減算する */
//     // xstep = TILE_SIZE / tan(rayAngle);
// 	step[TABINDEX_Y] = ray[strip_id].is_facing_down ? TILE_SIZE : -TILE_SIZE;
// 	step[TABINDEX_X] = TILE_SIZE / tan(ray_angle);

//     // if (isRayFacingRight && xstep < 0){ /* rayが右向きの場合は、xstepは正の数でなければならない(繰り返し処理で右の座標へ動く必要がある)ので、xstepが負の数の場合は符号を反転して正の数にする */
//     //   xstep = -xstep;
//     // }else if (!(isRayFacingRight) && xstep > 0){ /* rayが左向きの場合は、xstepは負の数でなければならない(繰り返し処理で左の座標へ動く必要がある)ので、xstepが正の数の場合は符号を反転して負の数にする */
//     //   xstep = -xstep;
//     // }
// 	if (ray[strip_id].is_facing_right && step[TABINDEX_X] < 0)
// 		step[TABINDEX_X] = -step[TABINDEX_X];
// 	else if (!(ray[strip_id].is_facing_right) && step[TABINDEX_X] < 0)
// 		step[TABINDEX_X] = -step[TABINDEX_X];

// 	// float nextHorzTouchX = xintercept;
// 	// float nextHorzTouchY = yintercept;
// 	next[TABINDEX_X] = intercept[TABINDEX_X];
// 	next[TABINDEX_Y] = intercept[TABINDEX_Y];

// 	// /* 壁と衝突するまで、交点を検査する */
// 	// while (isInsideMap(nextHorzTouchX, nextHorzTouchY))
// 	// {

// 	while (map_contain_the_coordinate(next[TABINDEX_X], next[TABINDEX_Y], map))
// 	{
// 	// 	x_toCheck = nextHorzTouchX;
// 		check[TABINDEX_X] = next[TABINDEX_X];
// 	// 	y_toCheck = nextHorzTouchY + ((isRayFacingDown) ? 0 : -1);
// 		if (ray[strip_id].is_facing_down)
// 			check[TABINDEX_Y] = next[TABINDEX_Y];
// 		else
// 			check[TABINDEX_Y] = next[TABINDEX_Y] - 1;
// 	// 	if (is_wall(x_toCheck, y_toCheck)){ /* 壁と衝突する交点が見つかったら、x, yの座標を保持してループを抜ける */
// 		if (map_has_wall_at(check[TABINDEX_X], check[TABINDEX_Y], &map))
// 		{
// 	// 		foundHorzWallHit = true;
// 			ray->has_horz_interception = true;
// 	// 		horzWallHitX = nextHorzTouchX;
// 			ray->horz_wall_intercept_x = next[TABINDEX_X];
// 	// 		horzWallHitY = nextHorzTouchY;
// 			ray->horz_wall_intercept_y = next[TABINDEX_Y];
// 	// 		horzWallContent = getMapAt((int)floor(y_toCheck / TILE_SIZE), (int)floor(nextHorzTouchX / TILE_SIZE));
// 			ray->horz_wall_content = '1';
// 	// 		break;
// 			break ;
// 		}
// 	// 	}else{ /* 交点の座標で壁と衝突していない場合、次の交点の座標へ移る */
// 		else
// 		{
// 	// 		nextHorzTouchX += xstep;
// 			next[TABINDEX_X] += step[TABINDEX_X];
// 	// 		nextHorzTouchY += ystep;
// 			next[TABINDEX_Y] += step[TABINDEX_Y];
// 		}
// 	//   }
		
// 	}
// // }
// }
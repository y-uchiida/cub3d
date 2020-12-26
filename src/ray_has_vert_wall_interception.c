/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_has_vert_wall_interception.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoguchi <yoguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 05:08:58 by yoguchi           #+#    #+#             */
/*   Updated: 2020/12/26 01:34:10 by yoguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_vert_wall_interseption(t_ray *ray, t_map map,
				float intercept[2], float step[2])
{
	float	next[2];
	float	check[2];

	next[TABINDEX_X] = intercept[TABINDEX_X];
	next[TABINDEX_Y] = intercept[TABINDEX_Y];
	while (map_contain_the_coordinate(next[TABINDEX_X], next[TABINDEX_Y], map))
	{
		check[TABINDEX_Y] = next[TABINDEX_Y];
		if (ray->is_facing_right)
			check[TABINDEX_X] = next[TABINDEX_X];
		else
			check[TABINDEX_X] = next[TABINDEX_X] -1;
		if (map_has_wall_at(check[TABINDEX_X], check[TABINDEX_Y], &map))
		{
			ray->has_vert_interception = true;
			ray->vert_wall_intercept_x = next[TABINDEX_X];
			ray->vert_wall_intercept_y = next[TABINDEX_Y];
			break ;
		}
		else
		{
			next[TABINDEX_X] += step[TABINDEX_X];
			next[TABINDEX_Y] += step[TABINDEX_Y];
		}
	}
}

void		ray_has_vert_wall_interception(t_ray *ray, t_player player,
									t_map map, float ray_angle)
{
	float	intercept[2];
	float	step[2];

	intercept[TABINDEX_X] = floor(player.x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_right)
		intercept[TABINDEX_X] += TILE_SIZE;
	intercept[TABINDEX_Y] = player.y + ((intercept[TABINDEX_X] - player.x)
															* tan(ray_angle));
	step[TABINDEX_X] = (ray->is_facing_right) ? TILE_SIZE : -TILE_SIZE;
	step[TABINDEX_Y] = TILE_SIZE * tan(ray_angle);
	if (ray->is_facing_down && step[TABINDEX_Y] < 0)
		step[TABINDEX_Y] = -step[TABINDEX_Y];
	else if (!(ray->is_facing_down) && step[TABINDEX_Y] > 0)
		step[TABINDEX_Y] = -step[TABINDEX_Y];
	ray->has_vert_interception = false;
	set_vert_wall_interseption(ray, map, intercept, step);
	if (ray->has_vert_interception == true)
		ray->vert_wall_dist = distance_between_points(
			player.x,
			player.y,
			ray->vert_wall_intercept_x,
			ray->vert_wall_intercept_y);
	else
		ray->vert_wall_dist = FLT_MAX;
}


// {
// 	float	intercept[2];
// 	float	step[2];

// // /* ----- 2. グリッドの縦罫線とrayの交点での、壁との距離を計算する ----- */
// // bool foundVertWallHit = false;
// // int vertWallContent = 0;
// // float vertWallHitX = 0;
// // float vertWallHitY = 0;

// // /* プレイヤーの座標と向きから、最も近い縦罫線との交点のx座標を取得する */
// // xintercept = floor(player.x / TILE_SIZE) * TILE_SIZE; /* TILE_SIZEで除算して、何本目の罫線と交点を持つかがわかる。floorで整数に直してから、タイルの大きさを乗じてグリッドとの交点を求める */
// 	intercept[TABINDEX_X] = floor(player.x / TILE_SIZE) * TILE_SIZE;
// // if (isRayFacingRight){ /* rayが右方向に伸びてている時、プレイヤーの座標よりも右にある罫線との交点のx座標を取らなければならないので… TILE_SIZEを加算して、xinterseptを一つ右のグリッドの座標にする */
// // 	xintercept += TILE_SIZE;
// // }
// 	if (ray[strip_id].is_facing_right)
// 		intercept[TABINDEX_X] += TILE_SIZE;

// // /* 同じく、最も近い縦罫線との交点のy座標を取得する */
// // yintercept = player.y + ((xintercept - player.x) * tan(rayAngle));
// 	intercept[TABINDEX_Y] = player.y + ((intercept[TABINDEX_X] - player.x)
// 															* tan(ray_angle));

// // /* 次の交点を取得するために、x座標とy座標のそれぞれの増加分(xstep, ystep)を保持する */
// // xstep = (isRayFacingRight) ? TILE_SIZE : -TILE_SIZE; /* rayが右方向のとき、TILE_SIZEを加算し、左方向のときはTILE_SIZEを減算する */
// 	step[TABINDEX_X] = (ray[strip_id].is_facing_right) ? TILE_SIZE : TILE_SIZE;
// // ystep = TILE_SIZE * tan(rayAngle);
// 	step[TABINDEX_Y] = TILE_SIZE * tan(ray_angle);
// // if (isRayFacingDown && ystep < 0){ /* rayが下向きの場合は、ystepは正の数でなければならない(繰り返し処理で下の座標へ動く必要がある)ので、符号を反転して正の数にする */
// // 	ystep = -ystep;
// 	if (ray[strip_id].is_facing_down && step[TABINDEX_Y] < 0)
// 		step[TABINDEX_Y] = step[TABINDEX_Y];
// // }else if (!(isRayFacingDown) && ystep > 0){ /* rayが上向きの場合は、ystepは負の数でなければならない(繰り返し処理で上の座標へ動く必要がある)ので、符号を反転して負の数にする */
// // 	ystep = -ystep;
// // }
// 	else if (!(ray[strip_id].is_facing_down) && step[TABINDEX_Y] > 0)
// 		step[TABINDEX_Y] = -step[TABINDEX_Y];
// 	set_vert_wall_interseption(ray[strip_id], map, intercept, step);

// // float nextVertTouchX = xintercept;
// // float nextVertTouchY = yintercept;
// 	float	next[2];
// 	float	chechk[2];

// 	next[TABINDEX_Y] = intercept[TABINDEX_X];
// 	next[TABINDEX_Y] = intercept[TABINDEX_Y];

// // /* 壁と衝突するまで、交点を検査する */
// // while(isInsideMap(nextVertTouchX, nextVertTouchY))
// // {
// 	while (map_contain_the_coordinate(next[TABINDEX_X], next[TABINDEX_Y], map))
// 	{
// 	// 	x_toCheck = nextVertTouchX + ((isRayFacingRight) ? 0 : -1);
// 	// 	y_toCheck = nextVertTouchY;
// 		if (ray.is_facing_right)
// 			check[TABINDEX_X] = next[TABINDEX_X];
// 		else
// 			check[TABINDEX_X] = next[TABINDEX_X] -1;

// 	// 	if (is_wall(x_toCheck, y_toCheck)){ /* 壁と衝突する交点が見つかったら、x, yの座標を保持してループを抜ける */
// 		if (map_has_wall_at(chechk[TABINDEX_X], chechk[TABINDEX_Y]))
// 		{
// 		// 	foundVertWallHit = true;
// 			ray.has_vert_interception = true;
// 		// 	vertWallHitX = nextVertTouchX;
// 			ray.vert_wall_intercept_x = next[TABINDEX_X];
// 		// 	vertWallHitY = nextVertTouchY;
// 			ray.vert_wall_intercept_y = next[TABINDEX_Y];
// 		// 	vertWallContent = getMapAt((int)floor(y_toCheck / TILE_SIZE), (int)floor(x_toCheck / TILE_SIZE));
// 		// 	break;
// 			break ;
// 	//   }else{ /* 交点の座標で壁と衝突していない場合、次の交点の座標へ移る */
// 		}
// 		else
// 		{
// 			// 	nextVertTouchX += xstep;
// 			next[TABINDEX_X] += step[TABINDEX_X];
// 			// 	nextVertTouchY += ystep;
// 			next[TABINDEX_Y] += step[TABINDEX_Y];
// 	//   }
// 		}
// 	}
// // }

// }

#include "../include/cub3d.h"

int main (){

	t_game game;
	t_img img;

	int w, h, bpp, size_line, endian;
	void *e_img, *w_img;

	char *e_data, *w_data;

	game.mlx.ptr = mlx_init();
	game.mlx.window.ptr = mlx_new_window(game.mlx.ptr, 1000, 1000, "test");

	e_img = mlx_xpm_file_to_image(game.mlx.ptr,
								"./img/tex_east.xpm", &w, &h);
	e_data = mlx_get_data_addr(e_img, &bpp, &size_line, &endian);

	w_img = mlx_xpm_file_to_image(game.mlx.ptr,
								"./img/tex_west.xpm", &w, &h);
	w_data = mlx_get_data_addr(w_img, &bpp, &size_line, &endian);


	mlx_put_image_to_window(game.mlx.ptr, game.mlx.window.ptr, e_img, 10, 10);
	mlx_put_image_to_window(game.mlx.ptr, game.mlx.window.ptr, w_img, 500, 500);

	printf("e_data(%p) : %d\n", e_data, *e_data);
	printf("w_data(%p) : %d\n", w_data, *w_data);

	mlx_loop(game.mlx.ptr);

	return (0);
}
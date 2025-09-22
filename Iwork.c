#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>

int main(void)
{
    mlx_t *mlx = mlx_init(640, 480, "PNG Test", true);
    if (!mlx) return 1;

    // Load PNG
    mlx_texture_t *png_tex = mlx_load_png("texture/wall.png");
    if (!png_tex)
    {
        fprintf(stderr, "Failed to load PNG!\n");
        mlx_terminate(mlx);
        return 1;
    }

    // Create image to draw PNG
    mlx_image_t *img = mlx_new_image(mlx, png_tex->width, png_tex->height);
    if (!img) return 1;

    // Copy pixels
    for (uint32_t y = 0; y < png_tex->height; y++)
    {
        for (uint32_t x = 0; x < png_tex->width; x++)
        {
            uint32_t idx = (y * png_tex->width + x) * 4;
            uint8_t r = png_tex->pixels[idx + 0];
            uint8_t g = png_tex->pixels[idx + 1];
            uint8_t b = png_tex->pixels[idx + 2];
            uint8_t a = png_tex->pixels[idx + 3];

            mlx_put_pixel(img, x, y, (r << 24) | (g << 16) | (b << 8) | a);
        }
    }

    mlx_image_to_window(mlx, img, 0, 0);
    mlx_loop(mlx);

    mlx_delete_image(mlx, img);
    mlx_delete_texture(png_tex);
    mlx_terminate(mlx);
    return 0;
}



#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data {
    void *mlx;
    void *win;
} t_data;

int key_press(int keycode, t_data *data) {
    printf("Key pressed: %d\n", keycode);
    return (0);
}

int key_release(int keycode, t_data *data) {
    printf("Key released: %d\n", keycode);
    return (0);
}

int mouse_press(int button, int x, int y, t_data *data) {
    printf("Mouse button %d pressed at (%d, %d)\n", button, x, y);
    return (0);
}

int mouse_move(int x, int y, t_data *data) {
    //printf("Mouse moved to (%d, %d)\n", x, y);
    return (0);
}

int close_program(t_data *data) {
    printf("Window closed. Exiting program.\n");
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

int main() {
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Hook Example");
    mlx_hook(data.win, 2, 1L << 0, key_press, &data);
    mlx_hook(data.win, 3, 1L << 0, key_release, &data);
    mlx_hook(data.win, 4, 1L << 2, mouse_press, &data);
    mlx_hook(data.win, 6, 1L << 6, mouse_move, &data);
    mlx_hook(data.win, 17, 0, close_program, &data);
    mlx_loop(data.mlx);
    return (0);
}

/* cc test01_our.c -I../minilibx-linux -L../minilibx-linux -lmlx -lX11 -lXext -lm */
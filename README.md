#### This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.

--------------------------------------

![Screenshot from 2024-12-24 02-07-44](https://github.com/user-attachments/assets/6d3099d6-b26d-4de5-b07a-4a77749bdcc4)


--------------------------------------

### Kраткое описание функций MLX:

1. **`void *mlx_init();`**  
   Инициализирует MLX и возвращает указатель на структуру соединения с X-сервером.

2. **`int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);`**  
   Связывает событие (`x_event`) с функцией-обработчиком (`funct`) для заданного окна (`win_ptr`). Параметр `param` передается в обработчик.

3. **`void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);`**  
   Создает новое окно размером `size_x` x `size_y` с заголовком `title`. Возвращает указатель на окно.

4. **`int mlx_get_color_value(t_xvar *xvar, int color);`**  
   Преобразует цвет в формат, подходящий для X-сервера.

5. **`int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);`**  
   Рисует строку `string` в окне `win_ptr` на позиции `(x, y)` с заданным цветом `color`.

6. **`int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);`**  
   Отображает изображение (`img_ptr`) в окне (`win_ptr`) на позиции `(x, y)`.

7. **`void *mlx_new_image(void *mlx_ptr, int width, int height);`**  
   Создает новое изображение размером `width` x `height`. Возвращает указатель на изображение.

8. **`int mlx_loop_hook(t_xvar *xvar, int (*funct)(), void *param);`**  
   Устанавливает функцию (`funct`), которая будет вызываться на каждой итерации основного цикла. Параметр `param` передается в функцию.

9. **`int mlx_loop(t_xvar *xvar);`**  
   Запускает основной цикл обработки событий.

10. **`int mlx_do_key_autorepeaton(void *mlx_ptr);`**  
   Включает авто-повторение нажатий клавиш.

11. **`int mlx_destroy_window(void *mlx_ptr, void *win_ptr);`**  
   Закрывает и освобождает ресурсы, связанные с окном (`win_ptr`).

12. **`int mlx_destroy_image(void *mlx_ptr, void *img_ptr);`**  
   Освобождает память, выделенную для изображения (`img_ptr`).

13. **`int mlx_destroy_display(void *mlx_ptr);`**  
   Закрывает соединение с X-сервером. Используется при завершении работы программы.



https://github.com/jgigault/42MapGenerator

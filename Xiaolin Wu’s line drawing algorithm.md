Pеализация алгоритма Ву для рисования линий на языке C:

```c
#include <stdio.h>
#include <math.h>

// Функция для рисования точки с координатами (x, y) и яркостью c
void plot(int x, int y, float c) {
    printf("Plotting at (%d, %d) with brightness %.2f\n", x, y, c);
}

// Целая часть числа
int ipart(float x) {
    return (int)floor(x);
}

// Округление до ближайшего целого
int round_float(float x) {
    return ipart(x + 0.5);
}

// Дробная часть числа
float fpart(float x) {
    return x - floor(x);
}

// 1 - дробная часть числа
float rfpart(float x) {
    return 1.0 - fpart(x);
}

// Функция для рисования линии с использованием алгоритма Ву
void draw_line(float x1, float y1, float x2, float y2) {
    int steep = fabs(y2 - y1) > fabs(x2 - x1);

    if (steep) {
        // Меняем местами x и y
        float tmp;
        tmp = x1; x1 = y1; y1 = tmp;
        tmp = x2; x2 = y2; y2 = tmp;
    }

    if (x1 > x2) {
        // Меняем начальные и конечные точки
        float tmp;
        tmp = x1; x1 = x2; x2 = tmp;
        tmp = y1; y1 = y2; y2 = tmp;
    }

    float dx = x2 - x1;
    float dy = y2 - y1;
    float gradient = dy / dx;

    // Обработка начальной точки
    int xend = round(x1);
    float yend = y1 + gradient * (xend - x1);
    float xgap = rfpart(x1 + 0.5);
    int xpxl1 = xend;
    int ypxl1 = ipart(yend);
    if (steep) {
        plot(ypxl1, xpxl1, rfpart(yend) * xgap);
        plot(ypxl1 + 1, xpxl1, fpart(yend) * xgap);
    } else {
        plot(xpxl1, ypxl1, rfpart(yend) * xgap);
        plot(xpxl1, ypxl1 + 1, fpart(yend) * xgap);
    }
    float intery = yend + gradient;

    // Обработка конечной точки
    xend = round_float(x2);
    yend = y2 + gradient * (xend - x2);
    xgap = fpart(x2 + 0.5);
    int xpxl2 = xend;
    int ypxl2 = ipart(yend);
    if (steep) {
        plot(ypxl2, xpxl2, rfpart(yend) * xgap);
        plot(ypxl2 + 1, xpxl2, fpart(yend) * xgap);
    } else {
        plot(xpxl2, ypxl2, rfpart(yend) * xgap);
        plot(xpxl2, ypxl2 + 1, fpart(yend) * xgap);
    }

    // Основной цикл
    if (steep) {
        for (int x = xpxl1 + 1; x < xpxl2; x++) {
            plot(ipart(intery), x, rfpart(intery));
            plot(ipart(intery) + 1, x, fpart(intery));
            intery += gradient;
        }
    } else {
        for (int x = xpxl1 + 1; x < xpxl2; x++) {
            plot(x, ipart(intery), rfpart(intery));
            plot(x, ipart(intery) + 1, fpart(intery));
            intery += gradient;
        }
    }
}

// Пример использования
int main() {
    //draw_line(10.5f, 20.5f, 30.5f, 40.5f);
    printf("\nPlotting at (1, 1) -> (8, 3) with brightness\n");
    draw_line(1.0f, 1.0f, 8.0f, 3.0f);
    
    printf("\nPlotting at (1, 1) -> (3, 8) with brightness\n");
    draw_line(1.0f, 1.0f, 3.0f, 8.0f);
    
    printf("\nPlotting at (-1, -1) -> (-8, -3) with brightness\n");
    draw_line(-1.0f, -1.0f, -8.0f, -3.0f);
    
    printf("\nPlotting at (-1, -1) -> (-3, -8) with brightness\n");
    draw_line(-1.0f, -1.0f, -3.0f, -8.0f);
    
    printf("\nPlotting at (-1, -1) -> (8, 3) with brightness\n");
    draw_line(-1.0f, -1.0f, 8.0f, 3.0f);
    
    printf("\nPlotting at (-1, -1) -> (3, 8) with brightness\n");
    draw_line(-1.0f, -1.0f, 3.0f, 8.0f);
    
    printf("\nPlotting at (1, 1) -> (-8, -3) with brightness\n");
    draw_line(1.0f, 1.0f, -8.0f, -3.0f);
    
    printf("\nPlotting at (1, 1) -> (-3, -8) with brightness\n");
    draw_line(1.0f, 1.0f, -3.0f, -8.0f);
    
    return 0;
}

// cc plot.c -o plot -lm

```

### Объяснение
1. **plot**: Функция для рисования точки с заданной яркостью. В этой реализации она просто выводит координаты и яркость точки на консоль.
2. **ipart, round, fpart**: Вспомогательные функции для получения целой части числа, округления до ближайшего целого и получения дробной части числа соответственно.
3. **draw_line**: Основная функция для рисования линии с использованием алгоритма Ву. Она обрабатывает начальную и конечную точки линии, а затем рисует основной отрезок, учитывая яркость для сглаживания (anti-aliasing).

Этот код демонстрирует основные шаги алгоритма Ву. Функция `plot` в реальной программе должна быть заменена на настоящую функцию рисования, которая будет взаимодействовать с графической библиотекой, например, MiniLibX или SDL.

Pеализация алгоритма Ву для рисования линий на языке C:

```c
#include <stdio.h>
#include <math.h>

// Определяем функцию для рисования точки
void plot(int x, int y, float c) {
    // Эта функция должна рисовать точку с координатами (x, y) и яркостью c
    // Пример вывода для демонстрации
    printf("Plotting at (%d, %d) with brightness %.2f\n", x, y, c);
}

// Определяем вспомогательные функции
int ipart(float x) {
    return (int)floor(x);
}

int round_float(float x) {
    return ipart(x + 0.5f);
}

float fpart(float x) {
    return x - floor(x);
}

// Функция для рисования линии
void draw_line(float x1, float y1, float x2, float y2) {
    if (x2 < x1) {
        // Swap points if x1 > x2
        float temp = x1;
        x1 = x2;
        x2 = temp;
        
        temp = y1;
        y1 = y2;
        y2 = temp;
    }
    
    float dx = x2 - x1;
    float dy = y2 - y1;
    float gradient = dy / dx;
    
    // Handle the first endpoint
    int xend = round_float(x1);
    float yend = y1 + gradient * (xend - x1);
    float xgap = 1 - fpart(x1 + 0.5f);
    int xpxl1 = xend;  // will be used in the main loop
    int ypxl1 = ipart(yend);
    plot(xpxl1, ypxl1, (1 - fpart(yend)) * xgap);
    plot(xpxl1, ypxl1 + 1, fpart(yend) * xgap);
    float intery = yend + gradient; // first y-intersection for the main loop
    
    // Handle the second endpoint
    int xend2 = round_float(x2);
    yend = y2 + gradient * (xend2 - x2);
    xgap = fpart(x2 + 0.5f);
    int xpxl2 = xend2;  // will be used in the main loop
    int ypxl2 = ipart(yend);
    plot(xpxl2, ypxl2, (1 - fpart(yend)) * xgap);
    plot(xpxl2, ypxl2 + 1, fpart(yend) * xgap);
    
    // Main loop
    for (int x = xpxl1 + 1; x <= xpxl2 - 1; x++) {
        plot(x, ipart(intery), 1 - fpart(intery));
        plot(x, ipart(intery) + 1, fpart(intery));
        intery = intery + gradient;
    }
}

// Пример использования
int main() {
    draw_line(10.5f, 20.5f, 30.5f, 40.5f);
    return 0;
}
```

### Объяснение
1. **plot**: Функция для рисования точки с заданной яркостью. В этой реализации она просто выводит координаты и яркость точки на консоль.
2. **ipart, round, fpart**: Вспомогательные функции для получения целой части числа, округления до ближайшего целого и получения дробной части числа соответственно.
3. **draw_line**: Основная функция для рисования линии с использованием алгоритма Ву. Она обрабатывает начальную и конечную точки линии, а затем рисует основной отрезок, учитывая яркость для сглаживания (anti-aliasing).

Этот код демонстрирует основные шаги алгоритма Ву. Функция `plot` в реальной программе должна быть заменена на настоящую функцию рисования, которая будет взаимодействовать с графической библиотекой, например, MiniLibX или SDL.

// lab5.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<locale.h>

int main()
{
    setlocale(LC_ALL, "");
    srand(time(0));
    int m = 5;
    int** g;
    int* deg;
    int gsize=0;

    printf("Задание 1\n");

    deg = (int*)malloc(m * sizeof(int));

    g = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i > m; i++) {
        g[i] = (int*)malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        g[i] = (int*)malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            if (i == j) {
                g[i][j] = 0;
            }
            else {
                g[i][j] = rand() % 2;
                g[j][i] = g[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", g[i][j]);
        }
        printf("\n");
    }

    printf("Задание 2\n");

    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            if (g[i][j] == 1) {
                gsize++;
            }
        }
    }
    printf("Размер графа: %d\n", gsize/2);

    printf("Задание 3\n");

    for (int i = 0; i < m; i++) {
        deg[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 1) {
                deg[i]++;
            }
        }
        printf("Степень вершины %d =%d\n", i, deg[i]);
    }

    for (int i = 0; i < m; i++) {
        if (deg[i] == 0) printf("Вершина %d изолированая\n", i);
        if (deg[i] == 1) printf("Вершина %d концевая\n", i);
        if (deg[i] == m - 1)printf("Вершина %d доминирующая\n", i);
    }

    return 0;
}


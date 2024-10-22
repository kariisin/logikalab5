#include <iostream>
#include <locale.h>

int main() {
    srand(time(0));
    setlocale(LC_ALL, "");

    int m = 5, gsize = 0, rebro = 0;
    int** g, * deg, ** inc;

    deg = (int*)malloc(m * sizeof(int));
    g = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        g[i] = (int*)malloc(m * sizeof(int));
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                g[i][j] = 0;
            }
            else {
                g[i][j] = rand() % 2;
                g[j][i] = g[i][j];
            }
        }
    }

    printf("Задание 1\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d", g[i][j]);
        }
        printf("\n");
    }

    printf("\nЗадание 2\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 1) {
                gsize++;
            }
        }
    }
    printf("Размер графа = %d\n", gsize / 2);

    printf("\nЗадание 3\n");
    for (int i = 0; i < m; i++) {
        deg[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 1) {
                deg[i]++;
            }
        }
        printf("Степень вершины %d = %d\n", i, deg[i]);
    }

    for (int i = 0; i < m; i++) {
        if (deg[i] == 0) printf("Вершина %d изолированная\n", i);
        if (deg[i] == 1) printf("Вершина %d концевая\n", i);
        if (deg[i] == m - 1) printf("Вершина %d доминирующая\n", i);
    }

    printf("\nЗадание 4\n");
    
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (g[i][j] == 1) {
                rebro++;
            }
        }
    }

    inc = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        inc[i] = (int*)malloc(rebro * sizeof(int));
        for (int j = 0; j < rebro; j++) {
            inc[i][j] = 0;
        }
    }

    int tec_rebro = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (g[i][j] == 1) {
                inc[i][tec_rebro] = 1;
                inc[j][tec_rebro] = 1;
                tec_rebro++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < rebro; j++) {
            printf("%d ", inc[i][j]);
        }
        printf("\n");
    }

    printf("Задание 5\n");

    int gsize_inc = 0;
    for (int j = 0; j < rebro; j++) {
        int rebro_count = 0;
        for (int i = 0; i < m; i++) {
            if (inc[i][j] == 1) {
                rebro_count++;
            }
        }
        if (rebro_count == 2) {
            gsize_inc++;
        }
    }
    printf("Размер графа  = %d\n", gsize_inc);

    printf("\nЗадание 6\n");
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < rebro; j++) {
            if (inc[i][j] == 1) {
                count++;
            }
        }

        if (count == 0) printf("Вершина %d изолированная\n", i);
        if (count == 1) printf("Вершина %d концевая\n", i);
        if (count == m - 1) printf("Вершина %d доминирующая\n", i);
    }
    return 0;
}
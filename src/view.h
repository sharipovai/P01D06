#include <stdio.h>

void wall(int width);

void view_board(int x_ball, int y_ball, int x_l_rack, int y_l_rack, int x_r_rack, int y_r_rack) {
    int width = 80;
    int height = 25;
    for (int line = 0; line <= 25; line++) {
        if (line == 0 || line == height)
            wall(width);
        else {
            for (int col = 0; col < width; col++) {
                if ((col == x_l_rack && line == y_l_rack) || (col == x_r_rack && line == y_r_rack))
                    printf("|");
                else if (col == x_ball && line == y_ball)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }
}

void wall(int width) {
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}



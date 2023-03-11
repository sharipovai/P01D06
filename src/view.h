#include <stdio.h>

void wall(int width);
int isRack(int line, int col, int x_l_rack, int y_l_rack, int x_r_rack, int y_r_rack);

void view_board(int x_ball, int y_ball, int x_l_rack, int y_l_rack, int x_r_rack, int y_r_rack, int score_l, int score_r) {
    int width = 80;
    int height = 25;
    printf("\n");
    printf("Score %d:%d\n\n", score_l, score_r);
    for (int line = 0; line <= 25; line++) {
        if (line == 0 || line == height)
            wall(width);
        else {
            for (int col = 0; col < width; col++) {
                if (isRack(line, col, x_l_rack, y_l_rack, x_r_rack, y_r_rack))
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

int isRack(int line, int col, int x_l_rack, int y_l_rack, int x_r_rack, int y_r_rack) {
    int res = 0;   
    if (col == x_l_rack)
        if (line <= y_l_rack + 2 && line >= y_l_rack)
            res = 1;
    if (col == x_r_rack)
        if (line <= y_r_rack + 2 && line >= y_r_rack)
            res = 1;
    return res;
}

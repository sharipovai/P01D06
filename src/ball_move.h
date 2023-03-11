#include <stdio.h>

void move(int *x_ball, int *y_ball, int bstep_x, int bstep_y) {
    *x_ball = *x_ball + bstep_x;
    *y_ball = *y_ball + bstep_y;
}

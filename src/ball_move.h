#include "add_func.h"

void move_ball(int *x_ball, int *y_ball, int *bstep_x, int *bstep_y, int x_l_rack, int y_l_rack, int x_r_rack,
               int y_r_rack, int height) {
    int new_x_ball = *x_ball + *bstep_x;
    int new_y_ball = *y_ball + *bstep_y;
    if (new_y_ball == 0 || new_y_ball == height) {
        *bstep_y = -*bstep_y;
        new_y_ball = *y_ball + *bstep_y;
    }
    if (isRack(new_y_ball, new_x_ball, x_l_rack, y_l_rack, x_r_rack, y_r_rack)) {
        *bstep_x = -*bstep_x;
        if (new_y_ball == y_l_rack || new_y_ball == y_r_rack) *bstep_y = -1;
        if (new_y_ball == (y_l_rack + 2) || new_y_ball == (y_r_rack + 2)) *bstep_y = 1;
    }
    *x_ball = *x_ball + *bstep_x;
    *y_ball = *y_ball + *bstep_y;
}

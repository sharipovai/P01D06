#include <stdio.h>

#include "view.h"
#include "ball_move.h"

int main() {
    int x_ball = 39;
    int y_ball = 14;
    int bstep_x = 10;
    int bstep_y = 10;

    int x_l_rack = 9;
    int x_r_rack = 70;
    int y_l_rack = 13;
    int y_r_rack = 13;

    int score_l = 0;
    int score_r = 0;

    view_board(x_ball, y_ball, x_l_rack, y_l_rack, x_r_rack, y_r_rack, score_l, score_r);
    move(&x_ball, &y_ball, bstep_x, bstep_y);
    view_board(x_ball, y_ball, x_l_rack, y_l_rack, x_r_rack, y_r_rack, score_l, score_r);
    return 0;
}

#include <stdio.h>

#include "view.h"

int main() {
    int x_ball, y_ball;
    int x_l_rack = 9;
    int x_r_rack = 70;
    int y_l_rack = 13;
    int y_r_rack = 13;
    scanf("%d %d", &x_ball, &y_ball);
    view_board(x_ball, y_ball, x_l_rack, y_l_rack, x_r_rack, y_r_rack);
    return 0;
}

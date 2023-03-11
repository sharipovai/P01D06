#include <stdio.h>

#include "ball_move.h"
#include "view.h"

void win_mes(int score_l, int score_r);

int main() {
    int x_ball = 39;
    int y_ball = 14;
    int bstep_x = -1;
    int bstep_y = 0;

    int x_l_rack = 9;
    int x_r_rack = 70;
    int y_l_rack = 13;
    int y_r_rack = 13;
    int rRstep_y = 0;
    int rLstep_y = 0;

    int new_y_l_rack;
    int new_y_r_rack;

    int score_l = 20;
    int score_r = 0;

    int width = 80;
    int height = 25;

    char command = ' ';

    int flag;
    while (flag != 2 && score_l < 21 && score_r < 21) {
        flag = 1;
        view_board(width, height, x_ball, y_ball, x_l_rack, y_l_rack, x_r_rack, y_r_rack, score_l, score_r);
        scanf("%c", &command);
        switch (command) {
            case 32:
                break;
            case 'a':
                rLstep_y = -1;
                break;
            case 'z':
                rLstep_y = 1;
                break;
            case 'k':
                rRstep_y = -1;
                break;
            case 'm':
                rRstep_y = 1;
                break;
            case 'q':
                flag = 2;
                break;
            default:
                flag = 0;
                break;
        }
        if (flag == 1) {
            new_y_l_rack = y_l_rack + rLstep_y;
            new_y_r_rack = y_r_rack + rRstep_y;
            if (new_y_l_rack > 0 && new_y_l_rack + 2 < height) y_l_rack = new_y_l_rack;
            if (new_y_r_rack > 0 && new_y_r_rack + 2 < height) y_r_rack = new_y_r_rack;
            rLstep_y = 0;
            rRstep_y = 0;
            move(&x_ball, &y_ball, &bstep_x, &bstep_y, x_l_rack, y_l_rack, x_r_rack, y_r_rack);
            if (x_ball == 0) {
                x_ball = 39;
                y_ball = 14;
                score_r += 1;
            }
            if (x_ball == width) {
                x_ball = 39;
                y_ball = 14;
                score_l += 1;
            }
        }
        win_mes(score_l, score_r);
    }
    return 0;
}

void win_mes(int score_l, int score_r) {
    printf("\n");
    if (score_l == 21) printf("Congratulations!!! Left player is win!!!\n");
    if (score_r == 21) printf("Congratulations!!! Rigth player is win!!!\n");
}

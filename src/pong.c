#include <stdio.h>

#include "view.h"
#include "ball_move.h"

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

    int score_l = 0;
    int score_r = 0;

    int width = 80;
    int height = 25;

    char command = ' ';
    
    int flag;
    while (flag != 2) {
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
        }
        if (flag == 1) {
            y_l_rack += rLstep_y;
            y_r_rack += rRstep_y;
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
    }
    return 0;
}

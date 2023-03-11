#ifndef H_ADD_FUNC
#define H_ADD_FUNC

int isRack(int line, int col, int x_l_rack, int y_l_rack, int x_r_rack, int y_r_rack);

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

#endif

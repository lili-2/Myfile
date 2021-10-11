//ÂíÌ¤ÆåÅÌ£¨DFS£©²Î¿¼´úÂë
/**
 * Project Name: horse_step_board
 * File Name   : main.cpp
 * Author      : Chen Chunhan
 * Date        : 2021-9-24 Fri.
 */
#include <cstdio>
#include <iostream>
using namespace std;
/* --- Global variables --- */
int board[9][9];    // This 2-dimensional array represents a checkerboard.
int di[8][2] = {{-2, 1},
                {-1, 2},
                {1,  2},
                {2,  1},
                {2,  -1},
                {1,  -2},
                {-1, -2},
                {-2, -1}};    // This 2-dimensional array represents direction.

/* --- Function declaration --- */
void dfs(int x, int y, int step);

/* --- Main function --- */
int main() {
    int m, n;
    cin >> m >> n;
    board[m][n] = 1;    // Set the starting point equal to 1.
    dfs(m, n, 2);
    return 0;
}

/* --- Function definition --- */
void dfs(int x, int y, int step) {
    if (step > 64) {    // Print the board and return.
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                printf("%3d", board[i][j]);
            }
            cout << endl;
        }
        exit(0);
    }
    for (auto &i : di) {    // Depth-first search.
        int x_next = x + i[0];
        int y_next = y + i[1];
        if (x_next > 0 && x_next <= 8 && y_next > 0 && y_next <= 8 && board[x_next][y_next] == 0) {
            board[x_next][y_next] = step;
            dfs(x_next, y_next, step + 1);
            board[x_next][y_next] = 0;    // Recall
        }
    }
}


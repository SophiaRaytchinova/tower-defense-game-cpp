#include "../include/render.h"
#include "../include/constants.h"
#include "../include/path.h"
#include "../include/utils.h"
#include <iostream>
using std::cout;
using std::endl;

void render(char map[ROWS][COLS]) {
    clearScreen(); //works only on windows
    //cout << "\x1b[2J\x1b[H"; //works everywhere but it flickers on windows
    cout << topAndBottomBorder << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << "| ";
        for (int j = 0; j < COLS; j++){
            if (map[i][j] == 'E') {
                cout << RED << map[i][j] << RESET << " ";
            }
            else if (map[i][j] == 'B') {
                cout << BLUE << map[i][j] << RESET << " ";
            }
            else cout << map[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << topAndBottomBorder << endl;
}
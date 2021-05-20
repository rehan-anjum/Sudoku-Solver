#include <iostream>
using namespace std;

int grid[9][9];

void outputBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!j) cout << " ";
            cout << grid[i][j] << " ";
            if ((j+1) % 3 == 0 && (j != 8)) cout << "| ";
        }
        if ((i+1) % 3 == 0 && (i != 8)) {
            cout << "\n-------+-------+-------\n";
        } else {
            cout << endl;
        }
        
    }
}

bool assignNum(int board[9][9], int row, int col, int num) {
    
    int tempRow, tempCol;
    tempRow = row - (row % 3);
    tempCol = col - (col % 3);

    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num)
            return false;
    }

    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num)
            return false;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i+tempRow][j+tempCol] == num) 
                return false;
        }
    }

    return true;

}

bool solveBoard(int board[9][9], int row, int col) {

    if (row == 8 && col == 9) return true;

    if (col == 9) {
        row++;
        col = 0;
    }

    if (board[row][col] > 0) {
        return solveBoard(grid, row, col+1);
    }

    for (int i = 1; i <= 9; i++) {
    
        if (assignNum(grid, row, col, i)) {
            
            board[row][col] = i;

            if (solveBoard(grid, row, col + 1)) {
                return true;
            }
        }

        board[row][col] = 0;

    }

    return false;

}


int main() {
    cout << "This is the sudoku solver program!\n" <<
            "Use spaces to separate each number and enter each row on a new line \n" <<
            "Enter your board below:\n" <<
            "========================\n\n";

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cin >> grid[row][col]; 
        }
    }

    cout << "\n========================\n";

    if (solveBoard(grid, 0, 0)) {
        cout << "  There is a solution!\n" <<
                "========================\n\n";
        outputBoard(grid);
        cout << "\n";
    } else {
        cout << "There is no solution.";
    }

    system("pause");
}
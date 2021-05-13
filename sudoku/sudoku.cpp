/** Wendy Ortiz Alfaro (B75584)
Profesor: Sauma - Curso: Analisis de algoritmos
Universidad de Costa Rica - ECCI
LABORATORIO #1: Ejercicio 3 - SUDOKU 
COTA O = N^3 */
#include<iostream> 
#include <iostream>

using namespace std;

// Global size for the matrix
const int SIZE = 9;

// prototype of function 
bool playSudoku(int sudoku[][SIZE], int row, int column);
bool check(const int sudoku[][SIZE], int row, int col, int val);

bool checkRow(const int row[], int column, int val);
bool checkColumn(const int sudoku[][SIZE], int row, int col, int val);
bool checkQuadrant(const int sudoku[][SIZE], int row, int col, int val);

void printGame(const int sudoku[][SIZE]);


// main method of the program
int main() {
    // Create principal matrix 9x9
    int sudoku[SIZE][SIZE]  = { {0,2,6,0,4,3,0,0,0},
                                {0,0,0,6,0,0,0,0,0},
                                {0,0,3,0,0,0,2,0,5},
                                {5,6,8,0,0,0,0,0,2},
                                {0,0,0,0,0,0,9,0,1},
                                {0,0,7,0,0,0,0,3,0},
                                {0,1,0,0,0,0,0,4,6},
                                {7,0,0,0,6,0,0,0,0},
                                {0,8,0,9,7,4,0,0,0} };  
    // call functions
    printGame(sudoku);
    playSudoku(sudoku, 0, 0);
    printGame(sudoku);

    return 0;
}

/**
* this method check the numbers in the row
*  @param the actual row, the position of the column and
*   the number
*  @return true if it's okay to put the number
*/
bool checkRow(const int row[], int column, int number) {

    bool flag = true;

    for (size_t index = 0; index < SIZE; index++) {
        if (index != column && row[index] == number) {
            flag = false;
        }
    }
    return flag;
}

/**
* this method check the numbers in the column
*  @param the matrix game (sudoku), the position of the row, the position
*   of the colum nand the number
*  @return true if it's okay to put the number
*/
bool checkColumn(const int sudoku[][SIZE], int row, int column, int number) {
    
    bool flag = true;

    for (size_t index = 0; index < SIZE; index++) {
        if (index != row && sudoku[index][column] == number) {
            flag = false;
        }
    }

    return flag;
}

/**
* this method check the numbers in the quadrant (3x3)
*  @param the matrix game (sudoku), the position of the row and the column in the sudoku, 
*   and the number
*  @return true if it's okay to put the number
*/
bool checkQuadrant(const int sudoku[][SIZE], int sudokuRow, int sudokuColumn, int number) {
    
    bool flag = true;

    // limits
    int sizeOfQuadrant = (SIZE / 3);
    int finalRowOfQuadrant = (sudokuRow / sizeOfQuadrant) * sizeOfQuadrant;
    int finalColumnOfQuadrant = (sudokuColumn/ sizeOfQuadrant) * sizeOfQuadrant;

    // check
    for (size_t rowQuadrant = finalRowOfQuadrant; rowQuadrant < 
        (finalRowOfQuadrant + sizeOfQuadrant); rowQuadrant++) {

        for (size_t columnQuadrant = finalColumnOfQuadrant; columnQuadrant <
            (finalColumnOfQuadrant + sizeOfQuadrant); columnQuadrant++) {

            if ((rowQuadrant != sudokuRow || columnQuadrant != sudokuColumn) && 
                sudoku[rowQuadrant][columnQuadrant] == number) {
                flag = false; 
            }
        }
    }

    return flag;
}
/**
* this method check all the  possibilities for the number
*  @param the matrix game (sudoku), the position of the row, the position
*   of the column and the number
*  @return true if it's okay to put the number in respect with all
*   sides
*/
bool check(const int sudoku[][SIZE], int row, int column, int number) {

    bool flag = false;

    // We need to check all the sides 
    if ((checkRow(sudoku[row], column, number) &&
        checkColumn(sudoku, row, column, number) &&
        checkQuadrant(sudoku, row, column, number))) {
        flag = true;
    } 

    return flag;
}

/**
* A recursive function that go over the all matrix and complete the game
*   with the correct rules
*  @param the matrix game (sudoku), the position of the row and the position
*   of the column
*  @return the same function until the stop condition or true if the game
*   is completely okay
*/
bool playSudoku(int sudoku[][SIZE], int row, int column) {
    
    int nextRow = (column == SIZE - 1) ? row + 1 : row;
    int nextColumn= (column+ 1) % (SIZE);

    if (row == SIZE) {
        return true;
    }
     // zero means empty
    if (sudoku[row][column] != 0) {
        return playSudoku(sudoku, nextRow, nextColumn);
    }

    for (int index = 1; index <= SIZE; index++) {
        sudoku[row][column] = index;
        if (check(sudoku, row, column, index) && playSudoku(sudoku, nextRow, nextColumn)) {
            return true;
        }

        // zero means empty
        sudoku[row][column] = 0;
    }
    return false;
}

/**
*  This method print the entire matrix
*  @param the matrix game (sudoku)
*/
void printGame(const int sudoku[][SIZE]) {
    cout << "--- SUDOKU ---\n";
    for (int row = 0; row < SIZE; row++) {
        for (int column= 0; column< SIZE; column++) {
            cout << sudoku[row][column] << ' ';
        }
        cout << endl;
    }
}

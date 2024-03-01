#include <iostream>
#include <vector>

using namespace std;

class EightQueens {
private:
    vector<vector<char>> board;

public:
    EightQueens() {
        initBoard();
    }

    void initBoard() {
        board = vector<vector<char>>(8, vector<char>(8, '.'));
    }

    void placeQueen(int row, int col) {
        board[row][col] = 'Q';
    }

    void removeQueen(int row, int col) {
        board[row][col] = '.';
    }

    bool isConflict(int row, int col) {
        for (int i = 0; i < 8; ++i) { // Проверка строки и столбца
            if (board[row][i] == 'Q' || board[i][col] == 'Q') {
                return true;
            }
        }
        for (int i = 0; i < 8; ++i) {// Проверка диагоналей
            for (int j = 0; j < 8; ++j) {
                if ((i + j == row + col || i - j == row - col) && board[i][j] == 'Q') {
                    return true;
                }
            }
        }

        return false;
    }

    bool solve(int col = 0) {
        if (col >= 8) {
            return true;
        }

        for (int i = 0; i < 8; ++i) {
            if (!isConflict(i, col)) {
                placeQueen(i, col);
                if (solve(col + 1)) {
                    return true;
                }
                removeQueen(i, col);
            }
        }

        return false;
    }

    void printBoard() {
        for (const auto& row : board) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    EightQueens eq;
    if (eq.solve()) {
        eq.printBoard();
    }
    else {
        cout << "Не найдено решений." << endl;
    }
    return 0;
}
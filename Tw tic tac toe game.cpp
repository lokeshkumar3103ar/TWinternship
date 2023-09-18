#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char token = 'x';

void functionOne() {
    cout << "     |      |   \n";
    cout << "  " << space[0][0] << "  |  " << space[0][1] << "   |  " << space[0][2] << "  \n";
    cout << "_____|______|_____\n";
    cout << "     |      |   \n";
    cout << "  " << space[1][0] << "  |  " << space[1][1] << "   |  " << space[1][2] << "  \n";
    cout << "_____|______|_____\n";
    cout << "     |      |   \n";
    cout << "  " << space[2][0] << "  |  " << space[2][1] << "   |  " << space[2][2] << "  \n";
    cout << "     |      |   \n";
}

bool functionTwo(char space[3][3], char token, string playerName) {
    int digit;
    cout << playerName << ", please enter your move (1-9): ";
    cin >> digit;

    if (digit < 1 || digit > 9) {
        cout << "Invalid move! Please enter a number between 1 and 9." << endl;
        return false;
    }

    int row = (digit - 1) / 3;
    int column = (digit - 1) % 3;

    if (space[row][column] != 'x' && space[row][column] != 'o') {
        space[row][column] = token;
        return true;
    } else {
        cout << "That cell is already occupied. Please choose an empty cell." << endl;
        return false;
    }
}

bool functionThree(char space[3][3]) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }

    // Check diagonals
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }

    // Check for a tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != 'o') {
                return false;
            }
        }
    }
    return true; // It's a tie
}

int main() {
    string player1, player2;
    cout << "Enter the name of the first player: ";
    cin >> player1;
    cout << "Enter the name of the second player: ";
    cin >> player2;

    cout << player1 << " is player 1 (X), and " << player2 << " is player 2 (O)." << endl;

    while (!functionThree(space)) {
        functionOne();
        bool validMove = false;
        while (!validMove) {
            if (token == 'x') {
                validMove = functionTwo(space, token, player1);
                if (validMove) token = 'o';
            } else {
                validMove = functionTwo(space, token, player2);
                if (validMove) token = 'x';
            }
        }
    }

    functionOne();
    if (token == 'x') {
        cout << player2 << " (O) wins!" << endl;
    } else {
        cout << player1 << " (X) wins!" << endl;
    }

    return 0;
}

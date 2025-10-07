#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

const int GRID_SIZE = 3;

void initBoard(char board[GRID_SIZE][GRID_SIZE])
{
    int num = 1;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++) 
        {
            board[i][j] = '0' + num++;
        }
    }
}

#include <iomanip>

void displayBoard(char board[GRID_SIZE][GRID_SIZE])
{
    system("cls");
    cout << "======== Tic-Tac-Toe Game ========" << endl << endl;
    cout << "Player 1: x, Player 2: o" << endl;
    cout << "Enter a number (1-9) to place your mark:" << endl << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---+---+---" << endl;
    }
    cout << endl;
}

int isValidMove(char board[GRID_SIZE][GRID_SIZE], int pos)
{
    if (pos < 1 || pos > 9) 
    {
        return 0;
    }
    int row = (pos - 1) / GRID_SIZE;
    int col = (pos - 1) % GRID_SIZE;
    return (board[row][col] != 'x' && board[row][col] != 'o');
}

void placeMark(char board[GRID_SIZE][GRID_SIZE], int pos, char mark)
{
    int row = (pos - 1) / GRID_SIZE;
    int col = (pos - 1) % GRID_SIZE;
    board[row][col] = mark;
}

int checkWin(char board[GRID_SIZE][GRID_SIZE], char mark) 
{
    for (int i = 0; i < GRID_SIZE; i++) 
    {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) 
        {
            return 1;
        }
    }

    for (int j = 0; j < GRID_SIZE; j++)
    {
        if (board[0][j] == mark && board[1][j] == mark && board[2][j] == mark) 
        {
            return 1;
        }
    }

    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
    {
        return 1;
    }

    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
    {
        return 1;
    }
    return 0;
}

int isBoardFull(char board[GRID_SIZE][GRID_SIZE]) 
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++) 
        {
            if (board[i][j] != 'x' && board[i][j] != 'o')
            {
                return 0;
            }
        }
    }
    return 1;
}

int main() 
{
    char board[GRID_SIZE][GRID_SIZE];
    initBoard(board);
    char currentPlayer = 'x';
    int moves = 0;

    while (moves < 9)
    {
        displayBoard(board);

        cout << "Player " << (currentPlayer == 'x' ? "1 (x)" : "2 (o)") << ", enter position (1-9): ";
        int pos;
        char input = _getch();
        cout << input << endl;
        pos = input - '0';

        if (pos < 1 || pos > 9 || !isValidMove(board, pos))
        {
            cout << "Invalid move! Choose an empty position (1-9)." << endl;
            cout << "Press any key to continue...";
            _getch();
            continue;
        }

        placeMark(board, pos, currentPlayer);
        moves++;

        if (checkWin(board, currentPlayer)) 
        {
            displayBoard(board);
            cout << "Player " << (currentPlayer == 'x' ? "1 (x)" : "2 (o)") << " wins!" << endl;
            break;
        }

        if (isBoardFull(board))
        {
            displayBoard(board);
            cout << "Game drawn!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'x') ? 'o' : 'x';
    }

    cout << endl << "Press any key to exit...";
    _getch();

    return 0;
}
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void iniboard(char board[][COLS]);
void disboard(char board[][COLS]);
bool isvalid(char board[][COLS], int position);
void makemove(char board[][COLS], int position, char player);
bool chewin(char board[][COLS], char player);
bool isfull(char board[][COLS]);

int main()
{
    char board[ROWS][COLS];
    char player = 'X'; //x start first
    int position;

    iniboard(board);
    disboard(board);

    while (true)
    {
        cout << "Player " << player << ", enter a position: ";
        cin >> position;

        while (!isvalid(board, position)) //check invalid
        {
            cout << "Invalid move. Enter again: ";
            cin >> position;
        }

        makemove(board, position, player);
        disboard(board);

        if (chewin(board, player))
        {
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        if (isfull(board))
        {
            cout << "No more moves are possible" << endl;
            break;
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}

void iniboard(char board[][COLS]) //initialize board from number 1 to 9
{
    char num = '1';

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = num;
            num++;
        }
    }
}

void disboard(char board[][COLS]) //display current board
{
    cout << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isvalid(char board[][COLS], int position) //check whether position is valid
{
    int row, col;

    if (position < 1 || position > 9)
        return false;

    row = (position - 1) / 3;
    col = (position - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    return true;
}

void makemove(char board[][COLS], int position, char player)
{
    int row, col;

    row = (position - 1) / 3;
    col = (position - 1) % 3;

    board[row][col] = player;
}

bool chewin(char board[][COLS], char player) //check wining condition
{
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }

    for (int j = 0; j < COLS; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

bool isfull(char board[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}
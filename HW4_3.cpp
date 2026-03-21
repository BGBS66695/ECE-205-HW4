#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int ROWS = 10;
const int COLS = 4;

void inseats(char seats[][COLS]);
void disseats(char seats[][COLS]);
int seatcolumn(char letter);
bool isfull(char seats[][COLS]);
void assignseat(char seats[][COLS], int row, char letter);

int main()
{
    char seats[ROWS][COLS];
    int row;
    char letter;
    char choice;

    inseats(seats); //choose the seat

    do
    {
        disseats(seats);

        if (isfull(seats))
        {
            cout << "All seats are taken" << endl;
            break;
        }

        cout << "Enter desired row number: ";
        cin >> row;
        cout << "Enter desired seat letter: ";
        cin >> letter;

        while (row < 1 || row > 10 || seatcolumn(letter) == -1 || seats[row - 1][seatcolumn(letter)] == 'X') //determine invalid code
        {
            cout << "Invalid or taken seat. Enter again: ";
            cin >> row;
            cout << "Enter seat letter again: ";
            cin >> letter;
        }

        assignseat(seats, row, letter);
        disseats(seats); //display the seat everytime after choose
        if (isfull(seats))
        {
            disseats(seats);
            cout << "All seats are taken" << endl;
            break;
        }

        cout << "Do you want to add another seat? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y'); //continue if yes

    return 0;
}

void inseats(char seats[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        seats[i][0] = 'A';
        seats[i][1] = 'B';
        seats[i][2] = 'C';
        seats[i][3] = 'D';
    }
}

void disseats(char seats[][COLS]) //display the seating chart
{
    cout << endl;
    for (int i = 0; i < ROWS; i++)
    {
        cout << i + 1 << "    ";
        for (int j = 0; j < COLS; j++)
        {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int seatcolumn(char letter)
{
    if (letter == 'A' || letter == 'a')
        return 0;
    else if (letter == 'B' || letter == 'b')
        return 1;
    else if (letter == 'C' || letter == 'c')
        return 2;
    else if (letter == 'D' || letter == 'd')
        return 3;
    else
        return -1;
}

bool isfull(char seats[][COLS]) //determine whether all seat is full
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (seats[i][j] != 'X')
            {
                return false;
            }
        }
    }
    return true;
}

void assignseat(char seats[][COLS], int row, char letter) //assign the seat
{
    int col = seatcolumn(letter);
    seats[row - 1][col] = 'X';
}
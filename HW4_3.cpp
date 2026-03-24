#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int rows = 10;
const int cols = 4;

void inseats(char seats[][cols]);
void disseats(char seats[][cols]);
int seatcolumn(char letter);
bool isfull(char seats[][cols]);
void assignseat(char seats[][cols], int row, char letter);

int main()
{
    char seats[rows][cols];
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

void inseats(char seats[][cols])
{
    for (int i = 0; i < rows; i++)
    {
        seats[i][0] = 'A';
        seats[i][1] = 'B';
        seats[i][2] = 'C';
        seats[i][3] = 'D';
    }
}

void disseats(char seats[][cols]) //display the seating chart
{
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << i + 1 << "    ";
        for (int j = 0; j < cols; j++)
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

bool isfull(char seats[][cols]) //determine whether all seat is full
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (seats[i][j] != 'X')
            {
                return false;
            }
        }
    }
    return true;
}

void assignseat(char seats[][cols], int row, char letter) //assign the seat
{
    int col = seatcolumn(letter);
    seats[row - 1][col] = 'X';
}
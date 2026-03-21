#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int SIZE = 7; //set constant value

void inputscores(double score[], int size);
double inputdifficulty();
double findhigh(const double score[], int size);
double findlow(const double score[], int size);
double findsum(const double score[], int size);
double finalscore(double sum, double highest, double lowest, double difficulty);

int main()
{
    double score[SIZE];
    double difficulty;
    double highest, lowest, sum, result;

    difficulty = inputdifficulty();
    inputscores(score, SIZE);

    highest = findhigh(score, SIZE);
    lowest = findlow(score, SIZE);
    sum = findsum(score, SIZE);

    result = finalscore(sum, highest, lowest, difficulty);

    cout << "The final diver score is: " << result << endl;

    return 0;
}

double inputdifficulty()
{
    double difficulty;

    cout << "Enter the degree of difficulty:" << endl;
    cin >> difficulty;

    while (difficulty < 1.2 || difficulty > 3.8) //determine whether it is valid
    {
        cout << "Invalid input. Enter again:" << endl;
        cin >> difficulty;
    }

    return difficulty;
}

void inputscores(double score[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter score " << i + 1 << endl; //get the score
        cin >> score[i];

        while (score[i] < 0 || score[i] > 10)
        {
            cout << "Invalid input. Enter score " << i + 1 << " again:" << endl;
            cin >> score[i];
        }
    }
}

double findhigh(const double score[], int size)
{
    double highest = score[0];

    for (int i = 1; i < size; i++) //get highest score
    {
        if (score[i] > highest)
        {
            highest = score[i];
        }
    }

    return highest;
}

double findlow(const double score[], int size)
{
    double lowest = score[0];

    for (int i = 1; i < size; i++) ////get highest low
    {
        if (score[i] < lowest)
        {
            lowest = score[i];
        }
    }

    return lowest;
}

double findsum(const double score[], int size)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum = sum + score[i];
    }

    return sum;
}

double finalscore(double sum, double highest, double lowest, double difficulty)
{
    double result;

    result = (sum - highest - lowest) * difficulty * 0.6; //do the calculation

    return result;
}
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int MAX_SIZE = 10000;

void input(int& size, int arr[])
{
    cout << "Please type how many number you want to use:" << endl;
    cin >> size; //input size

    if (size > MAX_SIZE)
    {
        size = MAX_SIZE;
    }

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i]; //input to array
    }
}

void cal(int size, int arr[], int bins[])
{
    for (int i = 0; i < MAX_SIZE; i++) //set all bin to zero
    {
        bins[i] = 0;
    }

    for (int i = 0; i < size; i++) //put number into bin
    {
        int index = arr[i] / 10;

        if (index < MAX_SIZE)
        {
            bins[index]++;
        }
    }
}

int main()
{
    int size;
    int arr[MAX_SIZE];
    int bins[MAX_SIZE];

    input(size, arr);
    cal(size, arr, bins);

    for (int i = 0; i < MAX_SIZE; i++) //print each bin
    {
        if (bins[i] > 0)
        {
            cout << i * 10 << "-" << i * 10 + 9 << ": "
                 << bins[i] << endl;
        }
    }

    return 0;
}
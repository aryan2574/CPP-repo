/* C++ program to find the frequency of each element of array */
#include <iostream>
using namespace std;
int main()

{
    int freq[100];
    int size, i, j, count;
    cin >> size;
    int arr[size];
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
        freq[i] = -1;
    }
    for (i = 0; i < size; i++)
    {
        count = 1;
        for (j = i + 1; j < size; j++)
        {
            /* If duplicate element is found */
            if (arr[i] == arr[j])
            {
                count++;
                /* Make sure not to count frequency of same element again */
                freq[j] = 0;
            }
        }
        /* If frequency of current element is not counted */
        if (freq[i] != 0)
        {
            freq[i] = count;
        }
    }
    /* Print frequency of each element */
    for (i = 0; i < size; i++)
    {
        if (freq[i] != 0)
        {
            cout << arr[i] << " " << freq[i] << endl;
        }
    }
}
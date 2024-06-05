#include <stdio.h>
#include <stdlib.h>

int min_max_sub(int arr[], int l, int length)
{
    int min = 100;
    int j = 0;
    while (j + l <= length)
    {
        int max = 0;
        for (int i = j; i < j + l; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        printf("Max din secventa este: %d\n", max);
        if (max < min)
        {
            min = max;
        }
        j = j + 1;
    }

    return min;
}

int main()
{
    int l = 3;
    int arr[20] = {1, 3, 5, 21, 5, 3, 6, 7, 5, 2, 1, 1, 7, 9, 3, 3, 5, 2, 6, 2};
    int value;
    value = min_max_sub(arr, l, 20);
    printf("Minimul din secvente este: %d\n", value);
    return 0;
}
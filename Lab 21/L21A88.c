#include <stdio.h>

int Binary_search(int[], int, int);

int main()
{
    int size, find, ans;
    printf("Enter Size : ");
    scanf("%d", &size);
    int a[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter Array Element : ");
        scanf("%d", &a[i]);
    }
    printf("Enter Element to be searched : ");
    scanf("%d", &find);
     ans = Binary_search(a, find, size);
    if (ans == -1)
    {
        printf("%d Not Found", find);
    }
    else
    {
        printf("%d Found At : %d", find, ans);
    }
    return 0;
}

int Binary_search(int a[], int key, int n)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == key)
            return mid;
        else if (key < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

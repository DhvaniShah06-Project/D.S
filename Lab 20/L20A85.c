#include "stdio.h"
#define n 10
int hashset[n];
void display();
void add(int);
void init();
int main()
{
    int choice, value;
    init();
    while (1)
    {
        printf("1 To Insert In Hashset\n2 To Display\n3 To Exit\n");
            scanf("%d",&choice);
            switch (choice)
            {
        case 1:
            printf("Enter Value : ");
            scanf("%d", &value);
            add(value);
            break;
        case 2:
            display();
            break;
        case 3:
            return 0;
        default:
            printf("Enter Valid Choice\n");
            break;
            }
    }
}
void init()
{
    for (int i = 0; i < n; i++)
    {
        hashset[i] = -1;
    }
}
int index_gen(int key)
{
    return key % n;
}

void add(int key)
{
    int index = index_gen(key);
    if (hashset[index] == -1)
    {
        hashset[index] = key;
        return;
    }
    else if (hashset[index] == key)
    {
        printf("Key Exists\n");
        return;
    }
    else
    {
        for (int probe = 1; probe < n; probe++)
        {
            int i = (index + probe) % n;
            if (hashset[i] == -1)
            {
                hashset[i] = key;
                return;
            }
            else if (hashset[i] == key)
            {
                printf("Key Exists\n");
                return;
            }
        }
        printf("Hashset Is Full\n");
        // return;
    }
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", hashset[i]);
    }
}
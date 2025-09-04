#include "stdio.h"
#include "string.h"
#define n 10
struct pair
{
    char key[n];
    int value;
};

struct pair hashmap[n];
void display();
void add(char[], int);
int key_gen(char[]);

int main()
{
    int choice, value;
    char key[25];
    while (1)
    {
        printf("1 To Insert In Hashset\n2 To Display\n3 To Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Key : ");
            scanf("%s", key);
            printf("Enter Value : ");
            scanf("%d", &value);
            add(key, value);
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

int key_gen(char k[])
{
    int index = 0;
    for (int i = 0; i < strlen(k); i++)
    {
        index += k[i];
    }
    return index % n;
}

void add(char k[], int value)
{
    int index = key_gen(k);
    if (hashmap[index].key[0] == "\0")
    {
        strcpy(hashmap[index].key, k);
        hashmap[index].value = value;
        return;
    }
    else if (strcmp(hashmap[index].key, k) == 0)
    {
        hashmap[index].value = value;
        return;
    }
    else
    {
        for (int probe = 1; probe < n; probe++)
        {
            int i = (index + probe) % n;
            if (hashmap[i].key[0] == '\0')
            {
                strcpy(hashmap[i].key, k);
                hashmap[i].value = value;
                return;
            }
            else if (strcmp(hashmap[i].key, k) == 0)
            {
                hashmap[i].value = value;
                return;
            }
        }
        printf("Full Hashmap\n");
    }
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        printf("%s : %d\n", hashmap[i].key, hashmap[i].value);
    }
}
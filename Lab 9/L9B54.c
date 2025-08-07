#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int size, i, flag;
    printf("Enter String Size : ");
    scanf("%d", &size);
    char *s = (char *)malloc((size + 1) * sizeof(char));
    printf("Enter String : ");
    scanf("%s", s);
    char *start = s;
    char *end = s + strlen(s) - 1;
    for (i = 0; i < size / 2; i++)
    {
        if (*(start + i) != *(end - i))
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 1)
    {
        printf("Not Palindrome");
    }
    else
    {
        printf("Palindrome");
    }
    free(start);
    free(end);
    free(s);
    return 0;
}
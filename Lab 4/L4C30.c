#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    printf("Enter String : ");
    gets(str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        else
        {
            str[i] = str[i];
        }
    }
    printf("Modified String: %s\n", str);
    return 0;
}
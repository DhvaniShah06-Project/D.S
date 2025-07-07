#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main()
{
    int n, i, j;
    printf("Enter The number Of Words You want to Enter : ");
    scanf("%d", &n);
    char Words[n][100], check[100], temp;
    for (i = 0; i < n; i++)
    {
        printf("Enter Word : ");
        scanf("%s", Words[i]);
    }
    srand(time(0)); // works as checkpoint if one e j value
    int index = rand() % n;
    printf("------------Start Game ------------\n");
    printf("The Word Is : %s\n", Words[index]);
    printf("Enter Analgam Word : ");
    scanf("%s", check);

    for (i = 0; i < strlen(Words[index]); i++)
    {
        for (j = 0; j < strlen(Words[index]); j++)
        {
            if (Words[index][i] > Words[index][j])
            {
                // swap
                temp = Words[index][i];
                Words[index][i] = Words[index][j];
                Words[index][j] = temp;
            }
        }
    }

    for (i = 0; i < strlen(check); i++)
    {
        for (j = 0; j < strlen(check); j++)
        {
            if (check[i] > check[j])
            {
                // swap
                temp = check[i];
                check[i] = check[j];
                check[j] = temp;
            }
        }
    }
    // printf("Sorted Word Is Random : %s\n", Words[index]);
    // printf("Sorted Word Is check amalgam : %s\n", check);
    printf("------------Game Over------------\n");
    if (strcmp(Words[index], check) == 0)
    {
        printf("Success The Entered Word Is Amalgam You Won !!!!");
    }
    else
    {
        printf("Sorry The Word You Entered Is Not Amalgam You Lost !!!!");
    }
    return 0;
}

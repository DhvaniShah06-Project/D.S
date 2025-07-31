#include "stdio.h"
#include "string.h"
char s[100];
int top = -1;
void push(char a);
char pop();

int main()
{
    char ans[50];
    int i, j, n, len, k = 0;
    printf("Enter n : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        top = -1;
        k = 0;

        char input[100];
        printf("Enter String : ");
        scanf("%s", input);
        for (j = 0; j < strlen(input) ; j++)
        {
            if (input[j] == 'a' || input[j] == 'e' || input[j] == 'i' || input[j] == 'o' || input[j] == 'u')
            {
               k=0;
                while (top != -1)
                {
                    char x = pop();
                    printf("Pop : %c\n", x);
                    ans[k++] = x;
                    printf("Answer inside : %c\n", ans[k-1]);
                }
                 for(i=0;i<k;i++)
                    {
                        push(ans[i]);
                    }
            }
            push(input[j]);
            
        }
        if (top != -1)
        {
            int temp = top;
            k=top;
            while (top != -1)
            {
                ans[k--] = pop();
            }
        ans[temp+1] = '\0';

        }

        printf("Answer String : %s\n", ans);
        j=0;
    }
}

void push(char a)
{
    top++;
    s[top] = a;
}

char pop()
{
    top--;
    return (s[top + 1]);
}

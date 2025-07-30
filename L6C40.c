#include"stdio.h"
#include"string.h"
char s[100];
int top = -1;
void push(char a);
char pop();

int main()
{
    char ans[50];
    int i,j,n,len,k=0;
    printf("Enter n : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        top = -1;
        k=0;
        memset(ans, 0, sizeof(ans));
        
        char input[100];
        printf("Enter String : ");
        scanf("%s",input);
        for(j=0;j<strlen(input);j++)
        {
            
            if(input[j]=='a'||input[j]=='e'||input[j]=='i'||input[j]=='o'||input[j]=='u')
            {

    while(top!=-1){
        char x = pop();
        printf("Pop : %c\n", x);
        ans[k] = x;
        printf("Answer : %c\n", ans[k]);
        k++;
    }
    ans[k] = input[j];
    printf("Answer : %s\n", ans);
    k++;
}

else{
    printf("Push : %c\n",input[j]);
    push(input[j]);
}
}
if(top!=-1)
{
    ans[k++] = pop();
}
// 
ans[k]='\0';
printf("Answer String : %s\n",ans);

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
    return (s[top+1]);
}
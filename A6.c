#include<stdio.h>
int main(){
    int sec;
    printf("Enter Seconds : ");
    scanf("%d",&sec);
    int hr = sec/3600;
    int min = (sec%3600)/60;
    int seconds = sec-((hr*3600)+(min*60));
    printf("%d :: %d ::%d",hr,min,seconds);
    return 0;
}
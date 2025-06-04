#include<stdio.h>
int main(){
    int days;
    printf("Enter Days : ");
    scanf("%d",&days);
    int year = days/365;
    int week = (days%365)/7;
    int day = days-(year*365)-(week*7);
    printf("%d Years %d Weeks %d Days",year,week,day);

    
    
    
    return 0;




}
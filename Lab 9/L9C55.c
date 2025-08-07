// define a C structure named Student (roll_no, name, branch and batch_no) 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct Student{
    int roll_no;
    char name [50];
    char Branch[50];
    int batch_no;

};
int main(){
    struct Student s1;
    struct Student *p;
    p = &s1;
    p-> roll_no = 101;
    strcpy(p->name,"Dhvani");
    strcpy(p->Branch,"Computer");
    p-> batch_no = 2;

    printf("Roll No : %d\n",p->roll_no);
    printf("Name : %s\n",p->name);
    printf("Branch : %s\n",p->Branch);
    printf("Batch No  : %d",p->batch_no);
    // free (p);    
    return 0;
}


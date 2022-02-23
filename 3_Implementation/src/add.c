#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <string.h>  

COORD b = {1,0};

void a(int x,int y)
{
    b.X = x;
    b.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),b);
}

int main()   ///main function
{
    FILE *fp, *ft;  /// file open and close
    char another;
	char choice;
  
    struct emp
    {
        char name[40];  ///name of the employee
        int DOB;       /// date of birth of employee
        int age;     /// age of the employee
		char ms[40];   
		char qualification[40];  
		char employement[40];    
        float bs;        /// basic salary of employee
    };

    struct emp e; 
    char employeename[40]; 
    long int resize; 
    fp = fopen("EMP.DAT","rb+");  
    if(fp == NULL)  
    {
        fp = fopen("EMP.DAT","wb+"); 
        if(fp == NULL)
        {
            printf("Connot open file"); 
            exit(1);
        }
    }
    
    resize = sizeof(e);
    while(1)
    {
        system("cls"); 
        a(20,5); 
        printf("1. Add Record"); /// adds record
        a(20,7);
        printf("Your Choice: "); /// entering our choice
        fflush(stdin); 
        choice = getchar(); 
        switch(choice)
        {
        case '1':  
            system("cls");
            fseek(fp,0,SEEK_END); 
            another = 'y';
            while(another == 'y')  
            {
                ///add details of employee
                printf("\nEnter name: ");  // enter name
                scanf("%s",e.name);
                printf("\nEnter date of birth: ");  /// enter date of birth
                scanf("%d", &e.DOB);
                printf("\nEnter age: "); /// enter age
                scanf("%d", &e.age);
                printf("\nEnter marital status: "); /// enter marital status
                scanf("%s",e.ms);
                printf("\nEnter academic qualifications: ");  ///enter qualification
                scanf("%s",e.qualification);
                printf("\nEnter  previous employment details: "); ///enter previous status
                scanf("%s",e.employement);
                printf("\nEnter salary: "); ///enter salary
                scanf("%f", &e.bs);
                fwrite(&e,resize,1,fp); 
                printf("\nAdd another record(y/n) "); /// add another one
                fflush(stdin);
                another = getchar(); 
            }
            break;
        }
    }
    return 0;
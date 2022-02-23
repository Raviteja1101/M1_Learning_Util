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
        printf("4. Delete Records"); /// deleting record
        a(20,13);
        printf("Your Choice: "); /// entering our choice
        fflush(stdin); 
        choice = getchar(); 
        switch(choice)
        {
            case '4':
        
            system("cls");
            another = 'y';
            while(another == 'y') 
            {
                printf("\nEnter employee name to delete: ");
                scanf("%s",employeename); 
                ft = fopen("Temp.dat","wb");  
                while(fread(&e,resize,1,fp) == 1)  
                {
                    if(strcmp(e.name,employeename) != 0)   
                    {
                        fwrite(&e,resize,1,ft); 
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("EMP.DAT"); /// removing the orginal file
                rename("Temp.dat","EMP.DAT");   
                fp = fopen("EMP.DAT", "rb+");
                printf("Delete another record(y/n)");  
                fflush(stdin);    
            }
        }
    }
    
    return 0;
}
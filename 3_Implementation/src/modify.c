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
        printf("3. Modify Records"); /// editing record
        a(20,11);
        printf("Your Choice: "); /// entering our choice
        fflush(stdin); 
        choice = getchar(); 
        switch(choice)
        {
            case '3':  
        
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the employee name to modify: ");
                scanf("%s", employeename);  
                rewind(fp);
                while(fread(&e,resize,1,fp)==1)  
                {
                    if(strcmp(e.name,employeename) == 0) 
                    {
                        printf("\nEnter new name,dob, age,ms,qualification,employement and bs: ");
                        scanf("%s %d %d %s %s %s %.2f",e.name,e.DOB,e.age,e.ms,e.qualification,e.employement,e.bs);
                        fseek(fp,-resize,SEEK_CUR); 
                        fwrite(&e,resize,1,fp); 
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        }
    }

    return 0;
}
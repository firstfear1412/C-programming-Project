#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#define sleep(sec) Sleep(1000*sec)
#include "game.h"

COORD coord = {0,0};
void gotoxy(int x,int y);
void Log();
void SignUp();
void SignIn();

FILE *Register, *Check;
char choice;

int main()
{
    while (1)
	{
		gotoxy(40,5);
        printf("--------------- KAWAII 666 -------------");
        gotoxy(40,7);
        printf("1.) Create new account");
        gotoxy(40,9);
        printf("2.) You already have an account? Sign in");
        gotoxy(40,11);
		printf("3.) Exit");
		gotoxy(40,13);
        printf("Please enter your choice : ");
        choice = getche();
        
        if (choice == '1'){
		    SignUp();
        }
        else if(choice == '2'){
        	SignIn();
		}
        else if(choice == '3'){
            exit(0);
        }
		else
		{
			gotoxy(35,17);
			printf("*********** Input choice invalid!! ***********");
		}
		
	fclose(Register);
	fclose(Check);
	gotoxy(33,23);
	printf("========= Press any key to return Main Menu. =========");
	getch();
	system("cls");
    }
}

void gotoxy(int x,int y){
	coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Log(){
	gotoxy(40,15);
	printf("Username : ");
    scanf("%s",&acc.username);
    gotoxy(40,17);
    printf("Password : ");
    scanf("%s",&acc.password);
}

void SignUp(){
	Register = fopen("Login.txt","a+");
	Check = fopen("Login.txt","r");
	Log();

    while(fscanf(Check,"%s",data_acc.UserLog))
	{
		if(strcmp(acc.username,data_acc.UserLog) == 0)
		{
			gotoxy(28,19);
			printf("****** This Username is already in use, Try another one. ******");
			break;
		}
		if(feof(Check)){
			fprintf(Register,"%s\n%s\n",acc.username,acc.password);
			gotoxy(49,19);
			printf("****** Data saved ******");
			break;
		}
	}
}

void SignIn(){
	Check = fopen("Login.txt","r");
	Log();
	if (!Check){
		gotoxy(39,19);
		printf("******* No Login file in directory! *******");
	}
	else{
		while(fscanf(Check,"%s",data_acc.UserLog) && fscanf(Check,"%s",data_acc.PwdLog) )
		{
			if(strcmp(acc.username,data_acc.UserLog) == 0 && strcmp(acc.password,data_acc.PwdLog) == 0)
			{
				gotoxy(39,19);
				printf("************** Login Success **************");
				getch();
				gotoxy(52,21);
				system("cls");
	            RouletteGame();
				break;
			}
			if(feof(Check)){
				gotoxy(40,19);
				printf("*********** Login Failed ***********");
				break;
			}
		}
	}
}


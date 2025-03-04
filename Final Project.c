#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<stdbool.h> 
#include<time.h> 
#include <ctype.h>

void choose(int);
void hidecursor();
void playgame();
void viewhighscore();
void updatescore(int);
void reset();
void guidelines();
void mainmenu();
int main()
{
	system("COLOR  f3");
	mainmenu();
	return 0;
}

void mainmenu()
{
	char select;
	char text[256];
	FILE *fp;
	menu:
		fp=fopen("Menu.txt","r");
		while(fgets(text,256,fp)){
		printf("%s",text);
		}
		fclose(fp);
		hidecursor();
		select=getch();
		system("cls");
	switch(select){
		case '1':
			system("cls");
			playgame();
			goto menu;
			break;
		case '2':
			viewhighscore();
			goto menu;
			break;
		case '3':
			guidelines();
			goto menu;
			break;
		default:
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t------------------------\n");
			printf("\t\t\t\t\t\t\tEXITING!\n");
			printf("\t\t\t\t\t\t------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n");
			exit(1);
	}
}

void playgame()
{
	system("cls");
	char select;
	char text[256];
	FILE *fp;
	fp=fopen("PlaygameMenu.txt","r");
	while(fgets(text,256,fp)){
		printf("%s",text);
	}
	fclose(fp);
	select=getch();
	switch(select){
	case '1' ... '4':
	{
		choose(select);
		break;
	}
	default:
		break;
	}
	system("cls");
}


void viewhighscore()
{
	int i;
	char text[256], user1[50], user2[50], user3[50], score1[50], score2[50], score3[50], select;
	after:
	printf("\n\n\n\n\t\t\t\t\t\t------------------------\n");
	printf("\t\t\t\t\t\t   TOP 3 High Scores!");
	printf("\n\t\t\t\t\t\t------------------------\n\n\n");
	FILE *fp;
	fclose(fp);
	fp=fopen("Highscore.txt","r");
	for(i=1 ; i<=6 ; i++)
	{
		fgets(text,sizeof(text),fp);
		if (i == 1)
			strncpy(user1,text,50);
		if (i == 2)
			strncpy(score1,text,50);
		if (i == 3)
			strncpy(user2,text,50);
		if (i == 4)
			strncpy(score2,text,50);
		if (i == 5)
			strncpy(user3,text,50);
		if (i == 6)
			strncpy(score3,text,50);
	}
	printf("\t%s", user1);
	printf("\t%s\n\n", score1);
	printf("\t%s", user2);
	printf("\t%s\n\n", score2);
	printf("\t%s", user3);
	printf("\t%s\n\n\n\n", score3);
	printf("\tPress 'R' To Clear High Scores");
	fclose(fp);
	select=toupper(getch());
	if (select=='R')
	{
		reset();
		system("cls");
		goto after;
	}
	system("cls");
}
			
void updatescore(int totalscore)
{
	printf("Enter");
	system("cls");
	int i;
	char text[256], user1[50], user2[50], user3[50], score1[50], score2[50], score3[50], username[50];
	FILE *fp;
	fp=fopen("Highscore.txt","r");
	for(i=1 ; i<=6 ; i++)
	{
		fgets(text,sizeof(text),fp);
		if (i == 1)
			strncpy(user1,text,50);
		if (i == 2)
			strncpy(score1,text,50);
		if (i == 3)
			strncpy(user2,text,50);
		if (i == 4)
			strncpy(score2,text,50);
		if (i == 5)
			strncpy(user3,text,50);
		if (i == 6)
			strncpy(score3,text,50);
	}
	int check3=atoi(score3);
	if (totalscore>check3)
	{
		fclose(fp);
		fp=fopen("Highscore.txt", "w+");
		int check1=atoi(score1);
		int check2=atoi(score2);
		printf("\n\n\n\n\t\t\t      -------------------------------------------\n");
		printf("\t\t\t\tYou Have A New High Score In The TOP 3");
		printf("\n\t\t\t      -------------------------------------------\n\n\n\n\n\n");
		printf("\tEnter Your Username: ");
		fflush(stdin);
		gets(username);
		if (totalscore>check1)
		{
			strncpy(user3, user2, 50);
			check3=check2;
			strncpy(user2, user1, 50);
			check2=check1;
			strncpy(user1, username, 50);
			check1=totalscore;
			fputs(user1, fp);
			fputs("\n", fp);
			fprintf(fp, "%d\n", check1);
			fputs(user2, fp);
			fprintf(fp, "%d\n", check2);
			fputs(user3, fp);
			fprintf(fp, "%d\n", check3);
		}
		else if (totalscore>check2)
		{
			strncpy(user3, user2, 50);
			check3=check2;
			strncpy(user2, username, 50);
			check2=totalscore;
			fputs(user1, fp);
			fprintf(fp, "%d\n", check1);
			fputs(user2, fp);
			fputs("\n", fp);
			fprintf(fp, "%d\n", check2);
			fputs(user3, fp);
			fprintf(fp, "%d\n", check3);
		}
		else
		{
			strncpy(user3, username, 50);
			check3=totalscore;
			fputs(user1, fp);
			fprintf(fp, "%d\n", check1);
			fputs(user2, fp);
			fprintf(fp, "%d\n", check2);
			fputs(user3, fp);
			fputs("\n", fp);
			fprintf(fp, "%d\n", check3);
		}
	}
	fclose(fp);
	system("cls");
}

void reset()
{
	FILE *fp;
	fp=fopen("Highscore.txt", "w+");
	fputs("--------", fp);
	fputs("\n", fp);
	fputs("----", fp);
	fputs("\n", fp);
	fputs("--------", fp);
	fputs("\n", fp);
	fputs("----", fp);
	fputs("\n", fp);
	fputs("--------", fp);
	fputs("\n", fp);
	fputs("----", fp);
	fclose(fp);
}

void guidelines()
{	char select;
	char text[256];
	FILE *fp;
	fp=fopen("Guidelines.txt","r");
	while(fgets(text,256,fp)){
		printf("%s",text);
	}
	fclose(fp);
	select=getch();
	system("cls");
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void choose(int select)
{
	system("cls");
	int i,j,k=0;
	int totalscore=0, score1=0, score2=0, score3=0, l=1;
	int loc,x;
	time_t t;
	char ans;
	char answer[100];
	char empty[400][400];
	int arr[50];
	char line[256];
	char correct[100],option1[100],option2[100],option3[100],option4[100];
	FILE *fp;
	switch (select)
	{
		case '1':
		{
			fp=fopen("IQ.txt","r");
			break;
		}
		case '2':
		{
			fp=fopen("Maths.txt","r");
			break;
		}
		case '3':
		{
			fp=fopen("English.txt","r");
			break;
		}
		case '4':
		{
			fp=fopen("GK.txt","r");
			break;
		}
	}
	printf("\n\n\n\n\t\t\t\t\t   ***** ROUND ONE *****\n\n\n\n\n");
	printf("   -You'll Receive 10 Points For Correct Answer.\n");
	printf("   -You'll Lose 6 Points For Wrong Answer.\n");
	printf("\n   -Press L to use lifeline. You only have one lifeline for each round.\n\n\n");
	system("pause");
	system("cls");
	for (i = 0; i < 50; i++){
		arr[i] = 10 * i + 1;}
	for(j=0 ; j < 15; j++)
	{
		srand((unsigned)time(&t));
		x = rand() % 3;
		loc = (3 * j) + x;
		for (i = arr[3 * j]; i < arr[loc]; i++)
		{
			fgets(empty[k],sizeof(empty[k]),fp);
			k++;
		}
		for(i=1 ; i<=10 ; i++){
			fgets(line,sizeof(line),fp);
		if(i == 1)
			printf("\n\nQ%d) %s",j+1,line);
		if(i>1 && i<=7)
			printf("%s",line);
		if(i == 3)
			strncpy(option1,line,50);	
		if(i == 4)
			strncpy(option2,line,50);	
		if(i == 5)
			strncpy(option3,line,50);			
		if(i == 6)
			strncpy(option4,line,50);
		if(i == 8)
			strncpy(correct,line,100);
		}	
		if (arr[loc] + 10 < arr[3 * (j + 1)])
		  {  
			for (i = arr[loc] + 10; i < arr[3 * (j + 1)]; i++)
			{
			fgets(empty[k],sizeof(empty[k]),fp);
				k++;
			}
		  }
		nolifeline:
		ans=toupper(getch());
		switch (ans){
		case 'A':
			strncpy(answer,option1,50);
			break;
		case 'B':
			strncpy(answer,option2,50);
			break;
		case 'C':
			strncpy(answer,option3,50);
			break;
		case 'D':
			strncpy(answer,option4,50);
			break;
		case 'L':{
			if (l == 1){
				printf("\t\t\t\tUsing Lifeline for this round.\n");
				printf("\n\t\t\t\tNow you have zero lifelines for this round.");
				l=0;
				j--;
				getch();
				system("cls");
				continue;}
			else{
				printf("\n\t\t\t\tLifeline Already Used.\n");
				printf("\n\t\t\t\tEnter an option from above.\n");
				goto nolifeline;}}
			break;
		default:
			goto nolifeline;}
		if (strncmp(correct,answer,100)==0)
		{
			printf("Correct!");
			if(j>=0 && j<=4)
			score1 = score1 + 10;
			if(j>4 && j<=9)
			score2 = score2 + 20;
			if(j>9 && j<=14)
			score3 = score3 + 30;
			getch();
		}
		else
		{
			printf("Wrong answer");
			if(j>=0 && j<=4)
			score1 = score1 - 6;
			if(j>4 && j<=9)
			score2 = score2 - 12;
			if(j>9 && j<=14)
			score3 = score3 - 18;
			getch();
		}
		system("cls");
		if (j==4){
			if(score1>15)
			{
			l=1;
			system("cls");
			printf("\n\n\n\n\t\t\t\t  CONGRATULATIONS YOU CLEAR THE FIRST ROUND...\n\n");
			printf("\n\n\n\n\t\t\t\t       Your Score For This Round Was %d\n\n\n\n\n",score1);
			system("pause");
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t   ***** ROUND TWO *****\n\n\n\n\n");
			printf("   -You'll Receive 20 Points For Correct Answer.\n");
			printf("   -You'll Lose 12 Points For Wrong Answer.\n");
			printf("\n   -Press L to use lifeline. You only have one lifeline for each round.\n\n\n");
			system("pause");
			system("cls");
			}
			else
			{
				printf("\n\n\n\n\n\n\n\n\t\t\t\tScore Too Low. Cannot Qualify For The Next Round.\n");
				goto end;
			}
		}
		if (j==9){
			if(score2>35)
			{
			l=1;
			system("cls");
			printf("\n\n\n\n\t\t\t\t  CONGRATULATIONS YOU CLEAR THE SECOND ROUND...\n\n\n\n\n");
			printf("\n\n\t\t\t\tYour score for this round was %d\n\n\n\n\n", score2);
			system("pause");
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t   ***** THIRD TWO *****\n\n\n\n\n");
			printf("   -You'll Receive 30 Points For Correct Answer.\n");
			printf("   -You'll Lose 18 Points For Wrong Answer.\n");
			printf("\n   -Press L to use lifeline. You only have one lifeline for each round.\n\n\n");
			system("pause");
			system("cls");
			}
			else
			{
				printf("\n\n\n\n\n\n\n\n\t\t\t\t     Score Too Low. Cannot Qualify For The Next Round.\n\n\n\n\n\n\n");
				goto end;
			}
		}
	}
		end:
		totalscore=score1+score2+score3;
		printf("\n\n\n\n\t\t\t\t\t    Your Total Score is %d\n\n\n\n\n\n\n\n",totalscore);
		system("pause");
		updatescore(totalscore);
	fclose(fp);
}

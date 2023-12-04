#include "account.h"


// Variables
int select_mode, bets, number, numrand, parity, colorbet;
int strightbet;
long int money;
void gotoxy(int x,int y);

// Arrays
int red[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
int black[18] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};



int spin_roulette(void)
{
    int number;
    srand(time(NULL));
    number = (rand() % 36) + 1;
    gotoxy(47,21);
    printf("The ball has landed on %d", number);
    return number;
}

int NumberOnly(int check)
{
	    while (check != '\n'){
        	check = getchar();
		}
}

void StrightBets(void)
{
    while (1)
    {
    	strightbet = 0; 
    	bets = 0;
    	gotoxy(34,8);
        printf("Enter a number between 1-36 you'd like to bet on: ");
        scanf("%d",&strightbet);
        NumberOnly(strightbet);
    
        if (strightbet > 0 && strightbet <= 36){
        	gotoxy(34,9);
            printf("Now how much money you want to bet: ");
            scanf("%d", &bets);
            NumberOnly(bets);
            if(bets>0 && bets<=money);
            else{
            	gotoxy(34,15);
                printf("You have enter invalid value of bets please try again..");
                getch();
            	system("cls");
                continue;
            }
            gotoxy(53,21);  
            printf("Please Wait...");
            sleep(3);
            spin_roulette();
    
            if (number == strightbet){
                money += (bets * 35);
                gotoxy(34,10);
                printf("Winner Winner! You now have $%d in your pocket", money);
                break;
            }
            else{
                money -= bets;
                gotoxy(34,10);
                printf("Sorry. You've lost $%d. Your new balance is $%d\n", bets, money);
                break;
            }
        }
        else 
        {
        	
        	gotoxy(34,11);
            printf("Invalid Input (choose number 1-36)");
            getch();
            system("cls");
            continue;
        }
    }
    gotoxy(28,25);
    printf("============ Press any key to return Roulette Game ============\n");
    getch();
    system("cls");
    
}

// int red[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
// int black[18] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};
int colorCheck(int numrand)
{
    int i;
    for (i = 0; i < 18; i++)
    {
        if (red[i] == numrand)
        {
            return 1;printf("\nTest 1\n");
            break;
        }
        if (black[i] == numrand)
        {
            return 0;printf("\nTest 2\n");
            break;
        }
    }
}

void RedOrBlackBets(void)
{
	
    while (1){
        colorbet = 0;
        bets = 0;
        int resultCheckcolor;
        gotoxy(34,8);
        printf("Alright pick a color. Choose 1 for RED or 2 for BLACK: ");
        scanf("%d", &colorbet);
        NumberOnly(colorbet);
        if (colorbet != 1 && colorbet != 2)
        {
        	gotoxy(34,11);
            printf("Invalid input (choose 1 or 2)\n");
            getch();
            system("cls");
            continue;
        }
        else
        {
        	gotoxy(34,9);
            printf("Now how much money you want to bet: ");
            scanf("%d", &bets);
            NumberOnly(bets);
            if (bets > money || bets <= 0)
            {
            	gotoxy(34,15);
                printf("You have enter invalid value of bets please try again..");
                getch();
            	system("cls");
                continue;
            }
            else
            {
                if (colorbet == 1)
                {
                	gotoxy(48,11);
                    printf("You have bet $%d on RED\n", bets);
                    gotoxy(53,21);
                    printf("Please Wait...\n");
                    sleep(3);
                    resultCheckcolor = colorCheck(spin_roulette());                              
                    if (resultCheckcolor == 1)
                    {
                    	gotoxy(37,12);
                        money += bets;
                        printf("Winner Winner! You now have $%d in your pocket", money);
                        break;
                    }
                    else
                    {
                    	gotoxy(37,12);
                        money -= bets;
                        printf("Sorry. You've lost $%d. Your new balance is $%d", bets, money);
                        break;
                    }
                }
                else if (colorbet == 2)
                {
                	gotoxy(48,11);
                    printf("You have bet $%d on BLACK\n", bets);
                    gotoxy(53,21);
                    printf("Please Wait...");
                    sleep(3);
                    resultCheckcolor = colorCheck(spin_roulette());
                    if (resultCheckcolor == 0)
                    {
                    	gotoxy(37,12);
                        money += bets;
                        printf("Winner Winner! You now have $%d in your pocket", money);
                        break;
                    }
                    else
                    {
                    	gotoxy(37,12);
                        money -= bets;
                        printf("Sorry. You've lost $%d. Your new balance is $%d", bets, money);
                        break;
                    }
                }
            }
        }
    }
    gotoxy(28,25);
    printf("============ Press any key to return Roulette Game ============\n");
    getch();
    system("cls");
}

void OddOrEvenBets(void)
{
    while(1)
    {
    	parity = 0;
    	bets = 0;
    	gotoxy(34,8);
        printf("Alright enter 1 for odd or 2 for even. Choose wisely!: ");
        scanf("%d", &parity);
        NumberOnly(parity);
        if(parity==1||parity==2);
        else{
        	gotoxy(34,11);
            printf("Invalid input (choose 1 or 2)"); 
            getch();
            system("cls");
            continue;
        }
        gotoxy(34,9);
        printf("Now how much money are you willing to risk? Payout is 1 to 1: ");
        scanf("%d", &bets);
        NumberOnly(bets);
        if(bets>0 && bets<=money);
        else{
        	gotoxy(34,15);
            printf("You have enter invalid value of bets please try again..");
            getch();
            system("cls");
            continue;
        }
        if (parity == 1){
        	gotoxy(48,11);
            printf("You have bet $%d on odds", bets);
        }
        else{
        	gotoxy(48,11);
            printf("You have bet $%d on evens", bets);
        }
        gotoxy(53,21);
        printf("Please Wait...");
        //system("cls");
        sleep(3);
        int result_num = spin_roulette(); 
        if (parity == 1){
            if (result_num % 2 == 1){
                money += bets;
                gotoxy(37,12);
                printf("Winner Winner! You now have $%d in your pocket", money);
                break;
            }
            else{
                money -= bets;
                gotoxy(37,12);
                printf("Sorry. You've lost $%d. Your new balance is $%d", bets, money);
                break;
            }
        }
        else{
            if (result_num % 2 == 0){
                money += bets;
                gotoxy(37,12);
                printf("Winner Winner! You now have $%d in your pocket", money);
                break;
            }
            else{
                money -= bets;
                gotoxy(37,12);
                printf("Sorry. You've lost $%d. Your new balance is $%d", bets, money);
                break;
            }
        }
        
    }
    gotoxy(28,25);
    printf("============ Press any key to return Roulette Game ============");
    getch();
    system("cls");
}

void RouletteGame(void)
{
	gotoxy(33,5);
    printf("------------------- Roulette Game  ------------------------");
    while (1)
    {
        money = 0;
        gotoxy(47,7);
        printf("Enter amount of money: ");
        scanf("%d",&money);
        NumberOnly(money);
        if (money != 0 && money > 0 )
        {
            system("cls");
            break;
        } 
        else 
        {   system("cls");
        	gotoxy(33,5);
            printf("------------------- Roulette Game  ------------------------"); 
            continue;
        }
    }
    
    while (1)
    {
        select_mode = 0;
        gotoxy(32,5);
        printf("--------------------- Roulette Game ----------------------");
        gotoxy(35,6);
        printf("Current Player: %s\n",data_acc.UserLog);
        gotoxy(35,7);
        printf("Balance: %d\n",money);
        gotoxy(32,8);
        printf("-----------------------------------------------------------");
        gotoxy(35,9);
        printf("There are 3 types of bets you can make");
        gotoxy(35,10);
        printf("1) Straight-up bet: Choose a single number.(0-36)");
        gotoxy(35,11);
        printf("2) Red or black: Choose a color.(R/B)");
        gotoxy(35,12);
        printf("3) Odd or even: Choose odd or even (1 to 1)");
        gotoxy(35,13);
        printf("4) Quit.");
        gotoxy(35,14);
        printf("Please select your preferred type of bet: ");
        scanf("%d", &select_mode);
        NumberOnly(select_mode);
        
        
        
        if (select_mode == 1)
        {
        	system("cls");
            StrightBets();
        }
        else if (select_mode == 2)
        {
        	system("cls");
            RedOrBlackBets();
        }
        else if (select_mode == 3)
        {
        	system("cls");
            OddOrEvenBets();
        }
        else if (select_mode == 4)  
        {
            break;
        }
        else
        {
            system("cls");
            continue;
        }
    
        if (money == 0)
        {
        	
        	printf("  \\/________________ \n");
            printf(" /     _____________)\n");
            printf("/     /      _  _ |        \n");
            printf("\\/\\/\\/     (O) (O)|        \n");
            printf("  |           ------, \n");
            printf("  |  _       ______/ \n");
            printf("  | (_      /   \\  \\ 			  You don't have enough money to bet\n");
            printf("  |        /  ___\\_ \\      \n");
            printf("  |        \\      / / \n");
            printf("__|_________\\______/\n");
            printf("\\______________\\./__\\   \n");
            printf(" /     .       | \\  |\n");
            printf(" \\    /_\\   .  |  \\ |\\   \n");
            printf("|`\\       /_\\ |   \\| \\ \n");
            break;
            
   			
            
            
        }
    }
}
 
        

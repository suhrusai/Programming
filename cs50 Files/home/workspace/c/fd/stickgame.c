#include<stdio.h>
#include <unistd.h>

void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
int main(void)
{
    int sticknum=21;
    int playernum;
    while(sticknum>=1)
    {
        if(sticknum==1)
        {
            clearScreen();
            clearScreen();
            clearScreen();
            printf("\a\n\n Computer wins!!!");
            break;
        }
        else
        {
            printf("\nEnter the number of matchsticks you want to choose 1,2,3 or 4(only %d match stickes left): ",sticknum);
            scanf("%d",&playernum);
            clearScreen();
            printf("\nPlayer chooses %d matchstick(s)",playernum);
            sticknum=sticknum-playernum;
            if (sticknum!=1 )
            {
                if(playernum==1)
                {
                    sticknum=sticknum-4;
                    printf("\n\a Computer chooses 4 matchstick(s)");
                }
                else if(playernum==2)
                {
                    printf("\n\a Computer chooses 3 matchstick(s)");
                    sticknum=sticknum-3;
                }
                else if (playernum==3)
                {
                    printf("\n\a Computer chooses 2 matchstick(s)");
                    sticknum=sticknum-2;
                }
                else
                {
                    printf("\n\a Computer chooses 1 matchstick(s)");
                    sticknum=sticknum-1;
                }
            }
        }

    }
}
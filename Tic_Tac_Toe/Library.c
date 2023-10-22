#include "Library.h"
//initialise the display grid and actual grid
void Initialise_grids(char grid[][17], char Act_grid[][3])
{
                int i,j;
                for(i=0;i<9;i++)
                {
                                for(j=0;j<17;j++)
                                {
                                                if(j==5 || j==11)
                                                {
                                                                grid[i][j] = '|';
                                                }
                                                else if(i==2 || i==5)
                                                {
                                                                grid[i][j] = '_';
                                                }
                                                else
                                                                grid[i][j]= ' ';
                                }
                }
                for(i=0;i<3;i++)
                {
                                for(j=0;j<3;j++)
                                {
                                                Act_grid[i][j] = ' ';
                                }
                }
}
//displays the display grid
void display_grid(char grid[][17])
{
                int i,j;
                printf("\n");
                for(i=0;i<9;i++)
                {
                                for(j=0;j<17;j++)
                                {
                                                printf("%c", grid[i][j]);
                                }
                                printf("\n");
                }
                printf("\n");
}

void update_displaygrid(char grid[][17],int x, int y, char c)
{
                int pos_r = x;
                int pos_c = y;
                //the first horizental line
                if(pos_r==0 && pos_c == 0)
                {
                                grid[1][2]=c;
                }
                else if(pos_r==0 && pos_c == 1)
                {
                                grid[1][8]=c;
                }
                else if(pos_r==0 && pos_c == 2)
                {
                                grid[1][14]=c;
                }
                //the second horizental line
                else if(pos_r==1 && pos_c == 0)
                {
                                grid[4][2]=c;
                }
                else if(pos_r==1 && pos_c == 1)
                {
                                grid[4][8]=c;
                }
                else if(pos_r==1 && pos_c == 2)
                {
                                grid[4][14]=c;
                }
                //the third horizental line
                else if(pos_r==2 && pos_c == 0)
                {
                                grid[7][2]=c;
                }
                else if(pos_r==2 && pos_c == 1)
                {
                                grid[7][8]=c;
                }
                else if(pos_r==2 && pos_c == 2)
                {
                                grid[7][14]=c;
                }
}

void update_Actgrid(char Act_grid[][3], char grid[][17], int x, int y,char c)
{
                if(x>=1 && x<=3  && y>=1 && y<=3)
                {
                                int pos_r = x-1;
                                int pos_c = y-1;
                                if(Act_grid[pos_r][pos_c] ==' ')
                                {
                                                Act_grid[pos_r][pos_c] = c;
                                                update_displaygrid(grid,pos_r,pos_c,c);
                                }
                }
}


int check_wins(char Act_grid[][3])
{
                int flag;
                //Checking for horizental wins
                while(1)
                {if((Act_grid[0][0]==Act_grid[0][1]) && (Act_grid[0][1]==Act_grid[0][2]) && (Act_grid[0][0] != ' '))
                {
                                flag = 11;
                                break;
                }
                else if((Act_grid[1][0]==Act_grid[1][1]) && (Act_grid[1][1]==Act_grid[1][2]) && (Act_grid[1][0] != ' '))
                {
                                flag = 12;
                                break;
                }
                else if((Act_grid[2][0]==Act_grid[2][1]) && (Act_grid[2][1]==Act_grid[2][2]) && (Act_grid[2][0] != ' '))
                {
                                flag = 13;
                                break;
                }
                //Checking for vertical wins
                else if((Act_grid[0][0]==Act_grid[1][0]) && (Act_grid[1][0]==Act_grid[2][0]) && (Act_grid[0][0] != ' '))
                {
                                flag = 21;
                                break;
                }
                else if((Act_grid[0][1]==Act_grid[1][1]) && (Act_grid[1][1]==Act_grid[2][1]) && (Act_grid[1][0] != ' '))
                {
                                flag = 22;
                                break;
                }
                else if((Act_grid[0][2]==Act_grid[1][2]) && (Act_grid[1][2]==Act_grid[2][2]) && (Act_grid[0][2] != ' '))
                {
                                 flag = 23;
                                 break;
                }
                //Checking for diagonal wins
                //backslash wins
                else if((Act_grid[0][0]==Act_grid[1][1]) && (Act_grid[1][1]==Act_grid[2][2])&& (Act_grid[0][0] != ' '))
                {
                                flag = 31;
                                break;
                }
                else if((Act_grid[0][2]==Act_grid[1][1]) && (Act_grid[1][1]==Act_grid[2][0]) && (Act_grid[0][2] != ' '))
                {
                                flag = 32;
                                break;
                }
                else
                {
                                flag = 0;
                                break;
                }
                }
                return flag;

}

void initialize_players(char player1[], char* tool1, char player2[], char* tool2)
{
                printf("Insert the first player's name: ");
                scanf("%49s", player1);
                // Clear the input buffer
                while ((getchar()) != '\n');
                printf("Insert the second player's name: ");
                scanf("%49s", player2);
                int i;
                i = strcmp(player1,player2); //Check that the player's names are not identical
                while ((getchar()) != '\n');
                while (i==0)
                {
                                printf("Insert a valid second player's name: ");
                                scanf("%49s", player2);
                                while ((getchar()) != '\n');
                                i = strcmp(player1,player2);
                                if(i != 0)
                                                break;
                }
                //Player must choose his tool
                printf("Player %s: Pick 'X' or ' O' to play with: ", player1);
                scanf(" %c", tool1);
                while (*tool1 != 'X' && *tool1 != 'O')
                {
                                printf("Please pick a valid choice!!\n");
                                printf("Player %s: Pick 'X' or ' O' to play with: ", player1);
                                scanf(" %c", tool1);
                                while ((getchar()) != '\n');
                }
                if(*tool1 == 'X')
                {
                                *tool2 ='O';
                }
                else if(*tool1 == 'O')
                {
                                *tool2 ='X';
                }
}

void display_winner(int flag, char player[], char tool)
{
                if (flag != 0)
                {
                                int val = flag;
                                printf("The Winner is %s and his tool is %c! \n", player,tool);
                                printf("His winning position is: ");
                                switch(val) {
                                                case 11:
                                                                printf("The first row.\n");
                                                                break;
                                                case 12:
                                                                printf("The second row\n");
                                                                break;
                                                case 13:
                                                                printf("The third row\n");
                                                                break;
                                                case 21:
                                                                printf("The first column\n");
                                                                break;
                                                case 22:
                                                                printf("The second column\n");
                                                                break;
                                                case 23:
                                                                printf("The third column.\n");
                                                                break;
                                                case 31:
                                                                printf("The backslash diagonal.\n");
                                                                break;
                                                case 32:
                                                                printf("The forward slash diagonal.\n");
                                                                break;
                                }
                }
}


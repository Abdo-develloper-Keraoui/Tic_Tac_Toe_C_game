#include <stdio.h>
#include <stdlib.h>
#include "Library.h"

int main()
{
                char player1[50], player2[50], grid[9][17], Act_grid[3][3];
                char tool1, tool2;
                int i,j,k=1,flag;
                printf("Initializing game!!!\n");
                initialize_players(player1, &tool1, player2, &tool2);
                Initialise_grids(grid,Act_grid);//Act_grid is successfully intialized
                /* *The game Tic Tac Toe has 9 turns, given this fact the game must not exceed 9 turns;
                *Further more, this fact allows us to determine which player is currently playing, if the iterative k
                is odd then it is the first player, if it is even then it is the second player
                * Also, this iterative k will allow us to check for wins just at the right time (not early) because the minimum
                a win can happen is in 5 turns.
                */
                while(k<=9)
                {
                       i=0;j=0;flag=1;
                       display_grid(grid);
                       if(k%2 != 0)
                       {
                                       printf("It's %s's turn: \n", player1);
                                       printf("Insert '%c' in: \n", tool1);
                                       printf("row = ");
                                       scanf("%d", &i);
                                       printf("column = ");
                                       scanf("%d", &j);
                                       while(!(i>=1 && i<=3  && j>=1 && j<=3) || Act_grid[i-1][j-1] !=' ')
                                       {
                                                printf("\nPlayer %s, Attention!! \n", player1);
                                                printf("Insert '%c' in a valid row and column: \n", tool1);
                                                printf("new row = ");
                                                scanf("%d", &i);
                                                printf("new column = ");
                                                scanf("%d", &j);
                                       }
                                       update_Actgrid(Act_grid, grid, i,j,tool1);
                       }
                       else if(k%2 == 0)
                       {
                                       printf("It's %s's turn: \n", player2);
                                       printf("Insert '%c' in: \n", tool2);
                                       printf("row = ");
                                       scanf("%d", &i);
                                       printf("column = ");
                                       scanf("%d", &j);
                                       while(!(i>=1 && i<=3  && j>=1 && j<=3) || Act_grid[i-1][j-1] != ' ')
                                       {
                                                printf("\nPlayer %s, Attention!! \n", player2);
                                                printf("Insert '%c' in a valid row and column: \n", tool2);
                                                printf("new row = ");
                                                scanf("%d", &i);
                                                printf("new column = ");
                                                scanf("%d", &j);
                                       }
                                       update_Actgrid(Act_grid, grid, i,j,tool2);
                       }
                       if(k>=5)
                       {
                                       flag = check_wins(Act_grid);
                                       if (flag != 0)
                                                break;
                       }
                       k++;
                }
                /*Checking for winners*/
                //display winner
                if(flag != 0)
                {
                                if(k%2 != 0)
                                {
                                                display_grid(grid);
                                                display_winner(flag,player1,tool1);
                                }
                                if(k%2 == 0)
                                {
                                                display_grid(grid);
                                                display_winner(flag, player2, tool2);
                                }
                }
                //display tie
                else if(flag==0)
                {
                                printf("The game ended in a draw!! \n");
                }
                printf("Game Over!!\n");
                system("pause");
                return 0;
}

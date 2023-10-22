#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//All functions needed
void Initialise_grids(char grid[][17], char Act_grid[][3]);
void display_grid(char grid[][17]);
void update_displaygrid(char grid[][17],int x, int y, char c);
void update_Actgrid(char Act_grid[][3], char grid[][17], int x, int y,char c);
int check_wins(char Act_grid[][3]);
void initialize_players(char player1[], char* tool1, char player2[], char* tool2);
void display_winner(int flag, char player[], char tool);

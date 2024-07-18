#include <ncurses.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>

char playingfield[14][21]; 

int i, key;
int x = 9, y = 7;
int fruit_x = 5, fruit_y = 3;
bool isRunning = true;
int ox,oy;
int snake_len = 1;


int main(){
	initscr();
	while(isRunning){
		strcpy(playingfield[0], "####################");
		for(i = 1; i < 13; i++){
			strcpy(playingfield[i], "#                  #");
		}
		strcpy(playingfield[13], "####################");

		playingfield[y][x] = 'O';
		playingfield[fruit_y][fruit_x] = '*';

		clear();
		
		for(i = 0; i < 14; i++){
			printw("%s\n", playingfield[i]);

		}
		for(int r = snake_len - 2; r>=0; --i){
			playingfield[у+1][x+1] = playingfield[y][x]
		}
		refresh();
		
		key = getch();

		ox = x;
		oy = y;
		if(key == 'w') y--;	
		if(key == 's') y++;
		if(key == 'a') x--;
		if(key == 'd') x++;

		if(playingfield[y][x] == '#'){
			x = ox;
			y = oy;
		}

		if(x == fruit_x && y == fruit_y){
			fruit_x = rand() % (18 - 1) + 1;
			fruit_y = rand() % (12 - 1) + 1;
		}
	}

		

	endwin();

	return 0;

	
}


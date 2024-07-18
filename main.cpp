#include <ncurses.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>

char playingfield[14][21]; 

int i, key, speed = 10, score = 0;
int x = 9, y = 7;
int fruit_x = 5, fruit_y = 3;
bool isRunning = true;
int ox,oy;
int asterisk = 0;
int UP = 0;
int DOWN = 1;
int LEFT = 2;
int RIGHT = 3;

int snake_dir = UP;
void snake_movement(void);

struct  snakestail{
	int old_x, old_y;
} snakestail_old[216];

int main(){
	initscr();
	while(isRunning){
		strcpy(playingfield[0], "####################");
		for(i = 1; i < 13; i++){
			strcpy(playingfield[i], "#                  #");
		}
		strcpy(playingfield[13], "####################");

		playingfield[y][x] = 'O';
		if (asterisk > 0) { // Отрисовка хвоста змеи

			for (i = 0; i < asterisk; i++)

				playingfield[snakestail_old[i].old_y][snakestail_old[i].old_x] = 'O';

		}    

		playingfield[fruit_y][fruit_x] = '*';
		if(asterisk >= 0 && asterisk <= 3){
			speed = 10;
		}
		else if(asterisk > 3 && asterisk <= 6){
			speed = 7;
		}
		else if(asterisk > 6 && asterisk <= 15){
			speed = 5;
		}
		else if(asterisk > 15 ){
			speed = 3;
		}
			
		clear();
		
		printw("You score:%d",score);
		printw("%s\n",";");

		for(i = 0; i < 14; i++){
			printw("%s\n", playingfield[i]);

		}
				refresh();
		halfdelay(speed);
		key = getch();

		ox = x;
		oy = y;

		switch(key){
			case 'w': snake_dir = UP; y--;
				break;
			case 's': snake_dir = DOWN; y++;
				break;
			case 'a': snake_dir = LEFT; x--;
				break;
			case 'd': snake_dir = RIGHT; x++;
				break;
			case ERR: snake_movement();

		}
				
		
		if(playingfield[y][x] == 'O'){//playingfield[snakestail_old[i].old_y][snakestail_old[i].old_x]){
			isRunning = false;
		}
		if(playingfield[y][x] == '#'){
			x = ox;
			y = oy;
			isRunning = false;
		}

		if (playingfield[y][x] != '#' || playingfield[y][x] != 'O') { // Движение только если голова змеи не упирается

			for (i = asterisk; i >= 0; i--) { // в решётку или хвост

				snakestail_old[i + 1].old_x = snakestail_old[i].old_x;

				snakestail_old[i + 1].old_y = snakestail_old[i].old_y;

			}

			snakestail_old[0].old_x = ox;

			snakestail_old[0].old_y = oy;

			}
		if(x == fruit_x && y == fruit_y){
			score++;
			asterisk++;
			fruit_x = rand() % (18 - 1) + 1;
			fruit_y = rand() % (12 - 1) + 1;
		}
		if(fruit_x == x && fruit_y == y){
			fruit_x = rand() % (18 - 1) + 1;
			fruit_y = rand() % (12 - 1) + 1;
		}
	}

		

	endwin();

	return 0;

	
}

void snake_movement(){
	if(snake_dir == UP) y--;	
	if(snake_dir == DOWN) y++;	
	if(snake_dir == LEFT) x--;	
	if(snake_dir == RIGHT) x++;	
	
}

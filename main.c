#include<stdio.h>

//don't mess up [rows][columns]

//below two lines are like a resolution of the game screen
#define WIDTH 120
#define HEIGHT 40

void draw_scene(char scene[][WIDTH]);
void build_top(char scene[][WIDTH]);
void build_left(char scene[][WIDTH]);
void build_right(char scene[][WIDTH]);
void build_bottom(char scene[][WIDTH]);
void print(char scene[][WIDTH]);
void spacefy(char scene[][WIDTH]);

int main() {
	char scene_2d[HEIGHT][WIDTH];

	spacefy(scene_2d);
	draw_scene(scene_2d);
}

void draw_scene(char scene[][WIDTH]) {
	build_top(scene);
	build_left(scene);
	build_right(scene);
	build_bottom(scene);
	print(scene);
}

void build_top(char scene[][WIDTH]) {
	for(int i = 0; i < WIDTH; scene[0][i++] = '#');
}

void build_left(char scene[][WIDTH]) {
	for(int i = 0; i < HEIGHT; scene[i++][0] = '#');
}

void build_right(char scene[][WIDTH]) {
	for(int i = 0; i < HEIGHT; scene[i++][WIDTH - 1] = '#');
}

void build_bottom(char scene[][WIDTH]) {
	for(int i = 0; i < WIDTH; scene[HEIGHT - 1][i++] = '#');
}

void print(char scene[][WIDTH]) {
	for(int i = 0; i < HEIGHT; i++) {
		for(int j = 0; j < WIDTH; j++) {
			printf("%c", scene[i][j]);
		}
		printf("\n");
	}
}

void spacefy(char scene[][WIDTH]) {
	for(int i = 0; i < HEIGHT; i++) {
		for(int j = 0; j < WIDTH; j++) {
			scene[i][j] = ' ';
		}
	}
}

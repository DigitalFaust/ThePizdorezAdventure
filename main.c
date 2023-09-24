#include<stdio.h>

//don't mess up [rows][columns]

#define WIDTH 80

void draw_scene(char scene[][WIDTH], int height);
void build_top(char scene[][WIDTH], int height);
void build_left(char scene[][WIDTH], int height);
void build_right(char scene[][WIDTH], int height);
void build_bottom(char scene[][WIDTH], int height);
void print(char scene[][WIDTH], int height);
void spacefy(char scene[][WIDTH], int height);

int main() {
	int height = 30;
	char scene_2d[height][WIDTH];

	spacefy(scene_2d, height);
	draw_scene(scene_2d, height);
}

void draw_scene(char scene[][WIDTH], int height) {
	build_top(scene, height);
	build_left(scene, height);
	build_right(scene, height);
	build_bottom(scene, height);
	print(scene, height);
}

void build_top(char scene[][WIDTH], int height) {
	for(int i = 0; i < WIDTH; scene[0][i++] = '#');
}

void build_left(char scene[][WIDTH], int height) {
	//TODO
}

void build_right(char scene[][WIDTH], int height) {
	//TODO
}

void build_bottom(char scene[][WIDTH], int height) {
	//TODO
}

void print(char scene[][WIDTH], int height) {
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < WIDTH; j++) {
			printf("%c", scene[i][j]);
		}
		printf("\n");
	}
}

void spacefy(char scene[][WIDTH], int height) {
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < WIDTH; j++) {
			scene[i][j] = ' ';
		}
	}
}

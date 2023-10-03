#include<stdio.h>

//don't mess up [rows][columns]

//below two lines are like a resolution of the game screen
#define WIDTH 120
#define HEIGHT 40

typedef enum DIAG_LINE { UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT } DIAG_LINE;

//below is a scene builder entity
void build_scene(char scene[][WIDTH]);
void build_top(char scene[][WIDTH]);
void build_left(char scene[][WIDTH]);
void build_right(char scene[][WIDTH]);
void build_bottom(char scene[][WIDTH]);

//below is a perspective builder entity
void build_perspective(char scene[][WIDTH]);
void build_up_left_diag(char scene[][WIDTH], int deg);
void build_up_right_diag(char scene[][WIDTH], int deg);
void build_down_left_diag(char scene[][WIDTH], int deg);
void build_down_right_diag(char scene[][WIDTH], int deg);
void build_line_by_degree(char scene[][WIDTH], DIAG_LINE line, int deg);

//below is common actions entity
void draw(char scene[][WIDTH]);
void spacefy(char scene[][WIDTH]);

int main() {
	char scene_2d[HEIGHT][WIDTH];

	spacefy(scene_2d);
	build_scene(scene_2d);
	build_perspective(scene_2d);
	draw(scene_2d);
}

/**
 * the function builds borders
 * of the scene drawing lines
 * on top-bottom borders and
 * left-right borders
 */
void build_scene(char scene[][WIDTH]) {
	build_top(scene);
	build_left(scene);
	build_right(scene);
	build_bottom(scene);
}

/**
 * the function creates line on top of the scene
 */
void build_top(char scene[][WIDTH]) {
	for(int i = 0; i < WIDTH; scene[0][i++] = '#');
}

/**
 * the function creates line on left border of the scene
 */
void build_left(char scene[][WIDTH]) {
	for(int i = 0; i < HEIGHT; scene[i++][0] = '#');
}

/**
 * the function creates line on right border of the scene
 */
void build_right(char scene[][WIDTH]) {
	for(int i = 0; i < HEIGHT; scene[i++][WIDTH - 1] = '#');
}

/**
 * the function creates line on bottom of the scene
 */
void build_bottom(char scene[][WIDTH]) {
	for(int i = 0; i < WIDTH; scene[HEIGHT - 1][i++] = '#');
}

/**
 * the function draws 2d array on the screen i.e. prints array
 */
void draw(char scene[][WIDTH]) {
	for(int i = 0; i < HEIGHT; i++) {
		for(int j = 0; j < WIDTH; j++) {
			printf("%c", scene[i][j]);
		}
		printf("\n");
	}
}

/**
 * the function simply fill the scene i.e. array by spaces
 */
void spacefy(char scene[][WIDTH]) {
	for(int i = 0; i < HEIGHT; i++) {
		for(int j = 0; j < WIDTH; j++) {
			scene[i][j] = ' ';
		}
	}
}

void build_perspective(char scene[][WIDTH]) {
	build_line_by_degree(scene, UP_LEFT, 0);
	/*build_up_left_diag(scene);
	build_up_right_diag(scene);
	build_down_left_diag(scene);
	build_down_right_diag(scene);*/
}

/**
 * 11 12 13 14 15
 * 21 22 ** 24 25
 * 31 32 ** 34 35
 * 41 42 43 44 45
 *
 * 11 12 13 14 15 16
 * 21 22 23 24 25 26
 * 31 32 ** ** 35 36
 * 41 42 43 44 45 46
 * 51 52 53 54 55 56
 * */
void build_up_left_diag(char scene[][WIDTH], int deg) {
	for(int i = 0; i < HEIGHT; scene[i][i++] = '#');
}

void build_up_right_diag(char scene[][WIDTH], int deg) {
	for(int i = 0; i < HEIGHT; scene[i++][WIDTH - i] = '#');
}

void build_down_right_diag(char scene[][WIDTH], int deg) {
	for(int i = 1; i < HEIGHT; scene[HEIGHT - i][WIDTH - i++] = '#');
}

void build_down_left_diag(char scene[][WIDTH], int deg) {
	for(int i = 1; i < HEIGHT; scene[HEIGHT - i][i++ - 1] = '#');
}

/**
 * I have to rewrite diagonal builders via below function
 * and set correctly degree value
 * */
void build_line_by_degree(char scene[][WIDTH], DIAG_LINE line, int deg) {
	switch(line) {
		case UP_LEFT:
			for(int i = 0; i < HEIGHT; scene[HEIGHT - deg][i++] = '#');
			break;
		case UP_RIGHT:
			for(int i = 0; i < HEIGHT; scene[i++][deg - i] = '#');
			break;
		case DOWN_LEFT:
			for(int i = 1; i < HEIGHT; scene[deg - i][i++ - 1] = '#');
			break;
		case DOWN_RIGHT:
			for(int i = 1; i < HEIGHT; scene[deg - i][deg - i++] = '#');
			break;
	}
}

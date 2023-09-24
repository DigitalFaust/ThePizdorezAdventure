#include<stdio.h>

void draw_borders(int width, int height);
void draw_top(int width, int height);
void draw_bottom(int width, int height);
void draw_left(int width, int height);
void draw_right(int width, int height);

int main() {
	int width = 80;
	int height = 30;
	draw_borders(width, height);
}

void draw_borders(int width, int height) {
	draw_top(width, height);
	draw_left(width, height);
	draw_right(width, height);
	//draw_bottom(width, height);
}

void draw_top(int width, int height) {
	for(int i = 0; i < width; i++) printf("#");
	printf("\n");
}

void draw_bottom(int width, int height) {
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if(i < height - 1) printf(" ");
			else printf("#");
		}
		printf("\n");
	}
}

void draw_left(int width, int height) {
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if(j == 0) printf("#");
		}
		printf("\r");
	}
}

void draw_right(int width, int height) {
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if(j == width - 1) printf("#");
			else printf(" ");
		}
		printf("\n");
	}
}

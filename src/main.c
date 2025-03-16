#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 3
#define BALL_SIZE 1
#define WINNING_SCORE 21
#define PADDLE_OFFSET 10

void clear_field(char field[HEIGHT][WIDTH + 1]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            field[y][x] = ' ';
        }
        field[y][WIDTH] = '\0';
    }
};

int main() {
    char field[HEIGHT][WIDTH + 1];
    int paddle1_y = HEIGHT / 2 - 1;
    int paddle2_y = HEIGHT / 2 - 1;
    int ball_x = WIDTH / 2 - 1;
    int ball_y = HEIGHT / 2;
    int player1_score = 0;
    int player2_score = 0;
    int ball_direction_x = 1;
    int ball_direction_y = 1;

    clear_field(field);

    return 0;
}

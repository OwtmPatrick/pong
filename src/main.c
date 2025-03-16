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

void move_paddle(char input, int *paddle1_y, int *paddle2_y) {
    if (input == 'a' && *paddle1_y > 0) {
        (*paddle1_y)--;
    } else if (input == 'z' && *paddle1_y < HEIGHT - PADDLE_SIZE) {
        (*paddle1_y)++;

    } else if (input == 'k' && *paddle2_y > 0) {
        (*paddle2_y)--;

    } else if (input == 'm' && *paddle2_y < HEIGHT - PADDLE_SIZE) {
        (*paddle2_y)++;
    }
}

void set_initial_state(int *ball_x, int *ball_y, int *paddle1_y, int *paddle2_y) {
    *ball_x = WIDTH / 2 - 1;
    *ball_y = HEIGHT / 2;
    *paddle1_y = HEIGHT / 2 - 1;
    *paddle2_y = HEIGHT / 2 - 1;
}

void update_ball(int *ball_x, int *ball_y, int *ball_direction_x, int *ball_direction_y, int *paddle1_y,
                 int *paddle2_y, int player1_score, int player2_score) {
    *ball_x += *ball_direction_x;
    *ball_y += *ball_direction_y;

    if (*ball_y == 0 || *ball_y == HEIGHT - 1) {
        *ball_direction_y = -*ball_direction_y;
    }

    if (*ball_x == PADDLE_OFFSET + 1 && (*ball_y >= *paddle1_y - 1 && *ball_y < *paddle1_y + PADDLE_SIZE)) {
        *ball_direction_x = 1;
    }

    if (*ball_x == WIDTH - PADDLE_OFFSET - 1 &&
        (*ball_y >= *paddle2_y - 1 && *ball_y < *paddle2_y + PADDLE_SIZE)) {
        *ball_direction_x = -1;
    }

    if (*ball_x == WIDTH - 1) {
        player1_score += 1;
        set_initial_state(ball_x, ball_y, paddle1_y, paddle2_y);
    }

    if (*ball_x == 0) {
        player2_score += 1;
        set_initial_state(ball_x, ball_y, paddle1_y, paddle2_y);
    }
}

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

    move_paddle('k', &paddle1_y, &paddle2_y);

    return 0;
}

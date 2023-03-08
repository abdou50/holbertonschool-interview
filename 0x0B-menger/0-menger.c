#include "menger.h"

void menger(int level) {
    if (level < 0) {
        return;
    }

    int size = (int) pow(3, level);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i % 3 == 1 && j % 3 == 1) {
                // center of the square is left empty
                printf(" ");
            } else {
                draw(j, i, level);
            }
        }
        printf("\n");
    }
}

void draw(int x, int y, int level) {
    if (level == 0) {
        // base case: draw a single # character
        printf("#");
    } else {
        // recursive case: draw a 3x3 square of level-1 sponges
        int size = (int) pow(3, level - 1);
        int cx = x / 3;
        int cy = y / 3;

        if (cx % 3 == 1 && cy % 3 == 1) {
            // center of the square is left empty
            printf(" ");
        } else {
            draw(x % size, y % size, level - 1);
        }
    }
}

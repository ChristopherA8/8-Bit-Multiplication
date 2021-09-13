/*
 *
 * Multiply two 8-bit numbers (B and Q)
 * using only bit manipulation and addition
 *
 * Author: Christopher Anderson
 * Date: 13 September 2021
 *
 */


#import <stdio.h>
#import <stdint.h>

void binprint(int v);
typedef unsigned int uint;

int main() {

    // Declare two 8-bit variables to be multiplied
    uint8_t B = 0b1001;
    uint8_t Q = 0b1100;

    // Result is stored in A
    uint8_t A = 0;

    // Loop Counter
    uint N = 4;

    loop:

    printf("\nB: ");
    binprint(B);
    printf("\nQ: ");
    binprint(Q);
    printf("\nA: ");
    binprint(A);

    uint8_t mask = 0b0001;
    uint8_t LSB = Q & mask;

    printf("\n\nLSB of Q: ");
    binprint(LSB);
    printf("\n");

    printf("\n-------------\n");

    if (LSB) A = A + B;

    B <<= 1;
    Q >>= 1;

    N--;

    if (N) goto loop;

    printf("\n\nA: ");
    binprint(A);
    printf(" (%d)\n\n", A);

    return 0;
}

// Print binary
// https://www.reddit.com/r/C_Programming/comments/5hczva/integer_in_c_and_how_to_print_its_binary/daz90v7?utm_source=share&utm_medium=web2x&context=3
void binprint(int v) {
    unsigned int mask = 1 << ((sizeof(uint8_t) << 3) - 1);
    while (mask) {
        printf("%d", (v & mask ? 1 : 0));
        mask >>= 1;
    }
}
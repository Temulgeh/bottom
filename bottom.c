#include <stdlib.h>
#include <stdio.h>
#include <time.h>


const int c_min_length = 8;
const int c_max_length = 24;


int randInt(int min_val, int max_val)
{
    return rand() % (max_val - min_val) + min_val;
}


char randLetter()
{
    char first_letter = rand() % 2 ? 'a' : 'A';
    return randInt(first_letter, first_letter + 25);
}


int main()
{
    srand(time(NULL));

    int length = randInt(c_min_length, c_max_length + 1);
    char *keysmash = malloc(length + 1);
    if (!keysmash)
    {
        puts("no memory?\n");
        return 0;
    }
    keysmash[length] = '\0';
    for (size_t i = 0; i < length; ++i)
        keysmash[i] = randLetter();
    puts(keysmash);
    free(keysmash);
    return 0;
}

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Value of each letter
int POINT[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Prompt the user for two words
    string firstword = get_string("Player 1: ");
    string secondword = get_string("Player 2: ");

    // Compute the score
    int player1 = compute_score(firstword);
    int player2 = compute_score(secondword);

    // Compare the scores and print the winner
    if (player1 > player2)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1 < player2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            score += POINT[word[i] - 'A'];
        }
        if (islower(word[i]))
        {
            score += POINT[word[i] - 'a'];
        }
    }
    return score;
}

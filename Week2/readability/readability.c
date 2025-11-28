#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

float const index = 0.0588;
float const a = 0.296;
float const b = 15.8;

int calculate_words(string words);
int calculate_letters(string letters);
int calculate_sentences(string sentences);

int main(void)
{
    // Get the text to evaluate
    string text = get_string("Text: ");

    // Get the value of L
    float L = ((float) calculate_letters(text) / calculate_words(text)) * 100;

    // Get the value of S
    float S = ((float) calculate_sentences(text) / calculate_words(text)) * 100;

    // Calculate the value of CLI
    float CLI = (index * L) - (a * S) - b;
    printf("%f\n", CLI);

    // Print the reading level result
    if (CLI < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (CLI >= 0.5 && CLI < 1.5)
    {
        printf("Grade 1\n");
    }
    else if (CLI >= 1.5 && CLI < 2.5)
    {
        printf("Grade 2\n");
    }
    else if (CLI >= 2.5 && CLI < 3.5)
    {
        printf("Grade 3\n");
    }
    else if (CLI >= 3.5 && CLI < 4.5)
    {
        printf("Grade 4\n");
    }
    else if (CLI >= 4.5 && CLI < 5.5)
    {
        printf("Grade 5\n");
    }
    else if (CLI >= 5.5 && CLI < 6.5)
    {
        printf("Grade 6\n");
    }
    else if (CLI >= 6.5 && CLI < 7.5)
    {
        printf("Grade 7\n");
    }
    else if (CLI >= 7.5 && CLI < 8.5)
    {
        printf("Grade 8\n");
    }
    else if (CLI >= 8.5 && CLI < 9.5)
    {
        printf("Grade 9\n");
    }
    else if (CLI >= 9.5 && CLI < 10.5)
    {
        printf("Grade 10\n");
    }
    else if (CLI >= 10.5 && CLI < 11.5)
    {
        printf("Grade 11\n");
    }
    else if (CLI >= 11.5 && CLI < 12.5)
    {
        printf("Grade 12\n");
    }
    else if (CLI >= 12.5 && CLI < 13.5)
    {
        printf("Grade 13\n");
    }
    else if (CLI >= 13.5 && CLI < 14.5)
    {
        printf("Grade 14\n");
    }
    else if (CLI >= 14.5 && CLI < 15.5)
    {
        printf("Grade 15\n");
    }
    else if (CLI >= 15.5 && CLI < 16.5)
    {
        printf("Grade 16\n");
    }
    else if (CLI > 16.5)
    {
        printf("Grade 16+\n");
    }
}
int calculate_words(string words)
{
    // Count the number of words
    int x = 1;
    for (int i = 0; i < strlen(words); i++)
    {
        if (words[i] == 32)
        {
            x++;
        }
    }
    return x;
}
int calculate_letters(string letters)
{
    // Count the number of letters
    int x = 0;
    for (int i = 0; i < strlen(letters); i++)
    {
        if (letters[i] >= 'A' && letters[i] <= 'z')
        {
            x++;
        }
    }
    return x;
}
int calculate_sentences(string sentences)
{
    // Count the number of sentences
    int x = 0;
    for (int i = 0; i < strlen(sentences); i++)
    {
        if (sentences[i] == '.' || sentences[i] == '!' || sentences[i] == '?')
        {
            x++;
        }
    }
    return x;
}

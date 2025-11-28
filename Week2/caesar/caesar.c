#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int key;
string encrypt_letters(string text);

int main(int argc, string argv[])
{
    // Error message if there's more than 1 argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string letter = argv[1];

    // Prompt the user for a number; Non-int values should not be allowed
    key = atoi(argv[1]);
    if (key <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0, n = strlen(letter); i < n; i++)
    {
        if (letter[i] < 48 || letter[i] > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Prompt the user for the text to encrypt
    string encrypt = get_string("plaintext:  ");

    // Print the encrypted text
    printf("ciphertext: ");
    string text = encrypt_letters(encrypt);
    printf("\n");
}
string encrypt_letters(string text)
{
    int increment = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z') // Convert uppercase letters to uppercase
        {
            if (key > 26) // If the key entered is more than 26, only add the modulus
            {
                key = key % 26;
                increment = text[i] + key;
                printf("%c", increment);
            }
            else // If the key is 26 or less
            {
                increment = text[i] + key;
                if (increment > 'Z')
                {
                    increment = (increment - 'Z') + 64;
                }
                printf("%c", increment);
            }
        }
        else if (text[i] >= 'a' && text[i] <= 'z') // Convert lowercase letters to lowercase
        {
            if (key > 26)
            {
                key = key % 26; // If the key entered is more than 26, only add the modulus
                increment = text[i] + key;
                printf("%c", increment);
            }
            else // If the key is 26 or less
            {
                increment = text[i] + key;
                if (increment > 'z')
                {
                    increment = (increment - 'z') + 96;
                }
                printf("%c", increment);
            }
        }
        else // If the character is not alphanumeric, no need to encrypt
        {
            printf("%c", text[i]);
        }
    }
    return 0;
}

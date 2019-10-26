#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: crack \"hash\" \n");
        return 1;
    }
     // 26 lowercase + 26 uppercase + \0 counts as 1 character = 53
    int letters_count = 53;
     //Les Caracteres utiliser dans les mots de passe
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
    string hash = argv[1];

    char salt[3];
    memcpy(salt, hash, 2); //Copie les deux premiere valeur du hash dans salt
    salt[2] = '\0';

    char key[6] = "\0\0\0\0\0\0"; //va contenir le mot de passe rechercher

                //Recherche du mot de passe par force brute
    for (int fifth = 0; fifth < letters_count; fifth++)
    {
        for (int fourth = 0; fourth < letters_count; fourth++)
        {
            for (int third = 0; third < letters_count; third++)
            {
                for (int second = 0; second < letters_count; second++)
                {
                    for (int first = 1; first < letters_count; first++)
                    {
						// The innermost loop advances most frequently compared to its ascendants,
                        // therefore according to the scheme above, it maps to the first letter.
                        // We could initialize it to 0 but that would be an empty string
                        // (i.e. no password) which is not allowed (should not be!)
                        key[0] = letters[first];
                        key[1] = letters[second];
                        key[2] = letters[third];
                        key[3] = letters[fourth];
                        key[4] = letters[fifth];
                        // It's important to realize that most string manipulation functions in C
                        // stop looping over the characters once they encounter a null character.
                        // That's essentially what this algorithm leverages when it initializes
                        // the key_candidate full of null characters and progresses from 1-letter
                        // all the way through 5-letter strings.
                        if (strcmp(crypt(key, salt), hash) == 0)
                        {
                            printf("%s\n", key);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    printf("Password couldn't be cracked!");

    return 2;
}
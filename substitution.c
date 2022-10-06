#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool key_check(string key);
bool check_duplicate(string key);
bool if_is_alpha(string key);
void substitution(string key, string plaintext);

int main(int argc, string argv[])
{
    bool key_ok = false;
    string plaintext;
    string key;
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        key = argv[1];
        key_ok = key_check(key);
    }

    if (key_ok != true)
    {
        printf("Key must not contain repeated alphabet\n");
        return 1;
    }
    else
    {
        plaintext = get_string("plaintext: ");
        substitution(key, plaintext);
    }
    return 0;
}

// check key
bool key_check(string key)
{
    bool key_ok = false;
    bool duplicate = false;
    bool confirm = false;
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 0;
    }
    else
    {
        confirm = if_is_alpha(key);
        printf("if is alpha check -------- %d\n", confirm);
    }

    if (confirm == false)
    {
        printf("key must contain only alphabet\n");
        return 2;
    }
    else
    {
        duplicate = check_duplicate(key);
    }

    if (duplicate == true)
    {
        key_ok = false;
    }
    else
    {
        key_ok = true;
    }
    return key_ok;
}

// checks if it is alphabet
bool if_is_alpha(string key)
{
    printf("if debugalpha check \n");
    bool check = false;
    int count = 1;
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]))
        {
            count += 0;
        }
        else
        {
            count++;
        }
    }
    if (count > 1)
    {
        check = false;
    }
    else if (count <= 1)
    {
        check = true;
        printf(" i runned ----- %i\n", check);
    }
    printf(" this is my count %d\n", count);
    return check;
}



bool check_duplicate(string key)
{
    bool duplicate = false;
    int count = 1;
    printf("running duplicate------------------- \n");
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (key[i] == key[j])
            {
                count++;
            }
            else
            {
                count += 0;
            }
        }
    }
    if (count > 1)
    {
        duplicate = true;
    }
    else
    {
        duplicate = false;
    }
    return duplicate;
}


void substitution(string key, string plaintext)
{
    char letters[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, j;
    char ciphertext[strlen(plaintext)];
    for (i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]) != 0)
        {
            for (j = 0; j < 26; j++)
            {
                if (plaintext[i] == toupper(letters[j]))
                {
                    ciphertext[i] = toupper(key[j]);
                }
            }
        }
        else if (islower(plaintext[i]) != 0)
        {
            for (j = 0; j < strlen(letters); j++)
            {
                if (plaintext[i] == tolower(letters[j]))
                {
                    ciphertext[i] = tolower(key[j]);
                }
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
        ciphertext[i] = '\0';
    printf("ciphertext: %s", ciphertext);
        printf("\n");

    }

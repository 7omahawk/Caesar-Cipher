// This Encryption and Decryption code made by Rahul who is interested in security.
// Actually I had an idea to get your info secure that no one has to understand what the heck is!
// The encryption and decryption methods are using shift cipher concept.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define character 26

int encryption();
int decryption();
char arr[character] = {"abcdefghijklmnopqrstuvwxyz"};
char convert[1000];
int key;
int calculation;

int main()
{
    int choice;

    while (1)
    {
        printf("\n1.Encryption\n2.Decryption\n3.Exit\nPlease select:");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
        {
            encryption();
            break;
        }
        case 2:
        {
            decryption();
            break;
        }
        case 3:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("Please enter correct input.\n");
            break;
        }
        }
    }

    return 0;
}

// Here is the encryption process.
int encryption()
{

    char plaintext[1000];
    int length = -1;
    int n = 0;

    printf("Enter the Plaintext you wanted to encrypt:");

    fgets(plaintext, sizeof(plaintext), stdin);
    // fgets(plaintext, sizeof(plaintext), stdin); // If the input didn't work then use this fgets too

    printf("\nEnter the key[Integer value]:");
    scanf("%d", &key);

    // String length
    while (plaintext[n] != '\0')
    {
        n++;
        length++;
        convert[length] = tolower(plaintext[length]); // Any uppercase letter convert to lowercase letter
    }

    printf("\nYour encrypted ciphertext is: ");

    // Converting plaintext to ciphertext
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < character; j++)
        {
            if (arr[j] == convert[i])
            {
                calculation = (j + key) % character;
                printf("%c", arr[calculation]);
            }
        }
    }

    printf("\n\n");
}

int decryption()
{

    char ciphertext[1000];
    int length = -1;
    int n = 0;

    printf("Enter the Ciphertext you wanted to decrypt:");

    fgets(ciphertext, sizeof(ciphertext), stdin);
    // fgets(ciphertext, sizeof(ciphertext), stdin); // If the input didn't work then use this fgets too

    printf("\nEnter the key[Integer value]:");
    scanf("%d", &key);

    // String length
    while (ciphertext[n] != '\0')
    {
        n++;
        length++;
        convert[length] = tolower(ciphertext[length]); // Any uppercase letter convert to lowercase letter
    }

    // Converting ciphertext to plaintext
    printf("\nYour decrypted plaintext is: ");

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < character; j++)
        {
            if (arr[j] == convert[i])
            {
                if (key > j)
                {
                    calculation = (j - key) + character;
                }
                else
                {
                    calculation = (j - key) % character;
                }

                printf("%c", arr[calculation]);
            }
        }
    }

    printf("\n\n");
}
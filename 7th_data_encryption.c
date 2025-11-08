
Implement data encryption and decryption.
AIM: To implement data encryption and decryption
DESCRIPTION:
This program uses the Caesar Cipher technique to encrypt or decrypt text by shifting letters using a key. It accepts user input for the text, key (1–25), and the desired operation (encrypt or decrypt).Only alphabetic characters are shifted, while others remain unchanged. Modular arithmetic ensures proper letter wrapping within the alphabet.
PROGRAM:
#include <stdio.h>
#include <string.h>

void encrypt(char text[], int key) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + key) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + key) % 26) + 'a';
        }
        text[i] = ch;
    }
}

void decrypt(char text[], int key) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' - key + 26) % 26) + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' - key + 26) % 26) + 'a';
        }
        text[i] = ch;
    }
}

int main() {
    char text[100];
    int key, choice;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // remove newline

    printf("Enter key (1-25): ");
    scanf("%d", &key);

    printf("Choose operation:\n1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(text, key);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        decrypt(text, key);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

OUTPUT:
Enter text: helloworld
Enter key (1-25): 3
Choose operation:
1. Encrypt
2. Decrypt
Enter choice: 1
Encrypted text: khoorzruog



Enter text: hello world
Enter key (1-25): 3
Choose operation:
1. Encrypt
2. Decrypt
Enter choice: 2
Decrypted text: ebiil tloia


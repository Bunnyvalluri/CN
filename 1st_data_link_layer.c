 
1. Implement the data link layer farming methods such as character, character-stuffing 
and bit stuffing. 
BIT STUFFING: 
1. AIM: To implement the Data Link Layer farming method as Bit Stuffing 
DISCRIPTION: 
1. This program performs bit stuffing on binary input data to avoid accidental flag patterns 
in transmission. 
2. It inserts a '0' after every sequence of five consecutive '1's in the input stream. 
3. The program reads binary input from the user and stores the stuffed output in a separate 
array. 
4. It demonstrates a common data link layer technique used in communication protocols 
like HDLC. 
Program: 
#include <stdio.h> 
#include <string.h> 
 
#define MAX 100 
 
void bitStuffing(char *input, char *stuffed) { 
    int i, j = 0, count = 0; 
    int len = strlen(input); 
 
    for (i = 0; i < len; i++) { 
        if (input[i] == '1') { 
            count++; 
            stuffed[j++] = input[i]; 
            if (count == 5) { 
                stuffed[j++] = '0'; // Insert 0 after five 1s 
                count = 0; 
            } 
        } else { 
            stuffed[j++] = input[i]; 
            count = 0; // Reset count on 0 
        } 
    } 
    stuffed[j] = '\0'; // Null-terminate the stuffed string 
} 
 
int main() { 
    char data[MAX], stuffedData[2 * MAX]; // Allocate extra space for stuffing 
 
    printf("Enter the binary data: "); 
    scanf("%s", data); 
 
    bitStuffing(data, stuffedData); 
 
    printf("Original Data: %s\n", data); 
    printf("Stuffed Data : %s\n", stuffedData); 
 
    return 0; 
} 
 
OUTPUT: 
Enter the binary data: 110110010111111 
Original Data: 110110010111111 
Stuffed Data : 1101100101111101 
CHARACTER STUFFING: 
1.  AIM: To implement the Data Link Layer farming method as Character Stuffing 
DISCRIPTION: The program prompts the user to enter a string, a position within that string, 
and a character to insert. Frame Initialization: It initializes a new string b with a starting delimiter 
sequence 'd', 'l', 'e', 's', 't', 'x'. Character Insertion and Stuffing: As it iterates through the original 
string a, it inserts the specified character at the given position, encapsulated by delimiter 
sequences. Additionally, if the sequence 'd', 'l', 'e' is found in the original string, it is duplicated to 
prevent misinterpretation as a delimiter. Frame Termination: After processing, it appends an 
ending delimiter sequence 'd', 'l', 'e', 'e', 't', 'x' to the new string b and displays the result. 
PROGRAM: 
#include<stdio.h>  
#include<string.h>  
void main()  
{  
int  
i=0,j=0,n,pos;  
char  
a[20],b[50],ch;  
printf("enter string\n");  
scanf("%s",&a);  
n=strlen(a);  
printf("enter position\n");  
scanf("%d",&pos);  
if(pos>n)  
{  
printf("invalid position, Enter again :"); 
scanf("%d",&pos);  
}  
printf("enter the character\n");  
scanf("%s",&ch);  
b[0]='d';  
b[1]='l';  
b[2]='e';  
b[3]='s';  
b[4]='t';  
b[5] ='x';  
j=6;  
while(i<n)  
{  
if(i==pos-1)  
{  
b[j]='d';  
b[j+1]='l';  
b[j+2]='e';  
b[j+3]= ch;  
b[j+4]='d';  
b[j+5]='l';  
b[j+6]='e';  
j=j+7;  
}  
if(a[i]=='d' && a[i+1]=='l' && a[i+2]=='e')  
{  
b[j]='d';  
b[j+1]='l';  
b[j+2]='e';  
j=j+3;  
} 
b[j]= a[i];  
i++;  
j++;  
}  
b[j]='d';  
b[j+1]='l';  
b[j+2]='e';  
b[j+3]='e';  
b[j+4]='t';  
b[j+5]='x';  
b[j+6]='\0';  
printf("\nframe after stuffing:\n");  
printf("%s",b);  
} 
OUTPUT: 
enter string 
shravani 
enter position 
3 
enter the character 
p 
frame after stuffing: 
dlestxshdlepdleravanidleetx 
C)BYTE STUFFING(CHRACTER COUNT): 
AIM: To implement the Data Link Layer farming method as Character Count Framing 
DISCRIPTION: 
1. The program reads a message and calculates its length, including one extra byte for the 
character count. 
2.It constructs a frame by placing the length as the first byte, followed by the actual message 
characters. 
3. The frame is then displayed both in numeric (ASCII) and character format to show how it 
would be transmitted. 
PROGRAM: 
#include <stdio.h> 
#include <string.h> 
 
int main() { 
    char data[100]; 
    char frame[105]; // Includes character count 
    int length, i; 
 
    printf("Enter the message: "); 
    scanf("%s", data); 
 
    length = strlen(data) + 1; // +1 for the count byte 
 
    frame[0] = length;  // Store the character count as the first byte 
 
    // Copy data to the frame 
    for(i = 0; i < strlen(data); i++) { 
        frame[i + 1] = data[i]; 
    } 
 
    // Display the framed data (as integers) 
    printf("\nFramed data (with character count):\n"); 
    for(i = 0; i < length; i++) { 
        printf("%d ", frame[i]); // printing ASCII values 
    } 
 
    // Also print characters for clarity 
    printf("\n\nFramed data (as characters):\n"); 
    for(i = 0; i < length; i++) { 
        if(i == 0) 
            printf("[Count: %d] ", frame[i]); 
        else 
            printf("%c ", frame[i]); 
    } 
 
    printf("\n"); 
 
    return 0; 
} 
OUTPUT: 
Enter the message: HELLO 
 
Framed data (with character count): 
6 72 69 76 76 79  
 
Framed data (as characters): 
[Count: 6] H E L L O 
 
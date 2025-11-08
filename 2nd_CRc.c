EXPERIMENT-2 
2. Write a program to compute CRC code for the Polynomials CRC-12, CRC- 16 and CRC- 
CCIP 
AIM: Implement on a data set of characters the three CRC polynomials CRC 12, CRC- 16 and 
CRC- CCIP 
Description: Cyclic Redundancy Check (CRC) is an error-detecting code commonly used in 
digital networks and storage devices to detect accidental changes to raw data. In this method, a 
divisor polynomial (also known as generator polynomial) is used to divide the original data. The 
remainder of this division is appended to the data before transmission. At the receiver's end, the 
data is divided by the same generator, and if the remainder is zero, the data is considered error
free. 
SENDER: 
This program calculates the CRC remainder for given binary data using a generator polynomial. 
It appends the remainder to the data to generate the transmitted codeword for error detection. 
Algorithm: 
1. Input binary data and generator polynomial. 
2. Append zeros to data (length = degree of polynomial). 
3. Perform modulo-2 division (XOR) to find the remainder. 
4. Append the remainder to original data to form the codeword. 
SOURECE CODE: 
#include <stdio.h> 
#include <string.h> 
#define MAX 128 
void xorOperation(char *crc, const char *poly, int poly_len) { 
for (int i = 1; i < poly_len; i++) { 
crc[i] = (crc[i] == poly[i]) ? '0' : '1'; 
} 
// Perform modulo-2 division 
void computeCRC(const char *data, const char *poly, char *remainder) { 
int data_len = strlen(data); 
int poly_len = strlen(poly); 
char temp[MAX]; 
strncpy(temp, data, poly_len); 
temp[poly_len] = '\0'; 
for (int i = poly_len; i <= data_len; i++) { 
if (temp[0] == '1') { 
xorOperation(temp, poly, poly_len); 
} 
// Shift left by 1 
for (int j = 0; j < poly_len - 1; j++) { 
temp[j] = temp[j + 1]; 
} 
temp[poly_len - 1] = data[i]; // append next bit 
} 
strncpy(remainder, temp, poly_len - 1); 
remainder[poly_len - 1] = '\0'; 
} 
int main() { 
char data[MAX], poly[MAX], appendedData[MAX * 2], remainder[MAX]; 
printf("Enter binary data: "); 
scanf("%s", data); 
printf("Enter generator polynomial (binary): "); 
scanf("%s", poly); 
int data_len = strlen(data); 
int poly_len = strlen(poly); 
// Append zeros to data 
strcpy(appendedData, data); 
for (int i = 0; i < poly_len - 1; i++) { 
appendedData[data_len + i] = '0'; 
} 
appendedData[data_len + poly_len - 1] = '\0'; 
computeCRC(appendedData, poly, remainder); 
printf("CRC Remainder: %s\n", remainder); 
// Append CRC to original data to form codeword 
strcat(data, remainder); 
printf("Transmitted Codeword: %s\n", data); 
return 0; 
} 
OUTPUT: 
Enter binary data: 10101110 
Enter generator polynomial (binary): 1011 
CRC Remainder: 101 
Transmitted Codeword: 10101110101 
RECEIVER: 
Description: This program checks for errors in a received codeword using the Cyclic 
Redundancy Check (CRC) method. It performs modulo-2 division using a generator 
polynomial and calculates the remainder. If the remainder is all zeros, the data is considered 
error-free; otherwise, an error is detected. 
Algorithm: 
1. Input the received codeword and generator polynomial. 
2. Perform modulo-2 division (XOR) of the codeword by the polynomial. 
3. Check if the resulting remainder contains only zeros. 
Source code: 
#include <stdio.h> 
#include <string.h> 
#define MAX 256 
void xorOperation(char *crc, const char *poly, int poly_len) { 
for (int i = 1; i < poly_len; i++) { 
crc[i] = (crc[i] == poly[i]) ? '0' : '1'; 
} 
} 
void computeCRC(const char *data, const char *poly, char *remainder) { 
int data_len = strlen(data); 
int poly_len = strlen(poly); 
char temp[MAX]; 
strncpy(temp, data, poly_len); 
temp[poly_len] = '\0'; 
for (int i = poly_len; i <= data_len; i++) { 
if (temp[0] == '1') { 
xorOperation(temp, poly, poly_len); 
} 
// Shift left 
for (int j = 0; j < poly_len - 1; j++) { 
temp[j] = temp[j + 1]; 
} 
temp[poly_len - 1] = data[i];  // bring next bit 
} 
strncpy(remainder, temp, poly_len - 1); 
remainder[poly_len - 1] = '\0'; 
} 
int isErrorFree(const char *remainder) { 
for (int i = 0; remainder[i] != '\0'; i++) { 
if (remainder[i] != '0') { 
return 0; // Error detected 
} 
} 
return 1; // No error 
} 
int main() { 
char receivedData[MAX], poly[MAX], remainder[MAX]; 
printf("Enter received codeword: "); 
scanf("%s", receivedData); 
printf("Enter generator polynomial (binary): "); 
scanf("%s", poly); 
computeCRC(receivedData, poly, remainder); 
if (isErrorFree(remainder)) { 
printf("✅ No Error Detected. Remainder: %s\n", remainder); 
} else { 
printf("✅ Error Detected! Remainder: %s\n", remainder); 
} 
return 0; 
} 
OUTPUT: Enter received codeword: 101011100101 
Enter generator polynomial (binary): 1011 
✅ Error Detected! Remainder: 100 
2) Enter received codeword: 10101110101 
Enter generator polynomial (binary): 1011 
✅ No Error Detected. Remainder: 000 
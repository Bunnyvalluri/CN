EXPERIMENT-3 
Develop a simple data link layer that performs the flow control using the sliding 
window protocol,and loss recovery using the Go-Back-N mechanism. 
DISCRIPTION: 
Sliding Window Protocol: The sender can send multiple frames before needing an 
acknowledgment but is limited by the window size. 
Go-Back-N: If a frame is lost or an acknowledgment is missed, the sender goes back and 
retransmits that frame and all subsequent frames. 
Frame Transmission: The program sends frames in the window size of 4. The sender starts by 
sending frames Seq = 0 to Seq = 3. 
ACKs: The program then waits for user input to simulate the acknowledgment: 
After each frame is sent, the user is prompted to input the ACK received. 
If an ACK is valid (in the expected range), the sender's window is moved forward. 
Timeout and Retransmission: 
If -1 is entered (simulating a timeout or lost ACK), the sender retransmits frames starting from 
the base sequence number. 
For instance, after sending frames Seq = 4 to Seq = 7, the user enters -1 for an ACK, indicating a 
timeout. The sender then retransmits frames starting from Seq = 3. 
Window Sliding: 
After receiving a valid ACK, the sender slides the window, moves the base to the next frame in 
sequence, and proceeds to send the next frame. 
For example, when ACK 0 is received, the base moves to 1, then frames Seq = 1 to Seq = 4 are 
sent, and so on. 
Final Acknowledgment: 
Once the sender receives ACKs for all frames, the program outputs the message "All frames sent 
and acknowledged." 
PROGRAM: 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <unistd.h>  // for sleep() 
#define MAX_SEQ 7  // Maximum sequence number (modulo value) 
#define WINDOW_SIZE 4 
typedef struct { 
int seq; 
char data[20]; 
} Frame; 
// Simulate sending frame (in real scenario, this would send over physical medium) 
void send_frame(Frame frame) { 
printf("Sending Frame: Seq = %d, Data = %s\n", frame.seq, frame.data); 
} 
// Simulate receiving ACK (for demonstration, user inputs the ACK number) 
int receive_ack() { 
int ack; 
printf("Enter ACK number received by sender (-1 for timeout/no ACK): "); 
scanf("%d", &ack); 
return ack; 
} 
 
int main() { 
    int base = 0; 
    int next_seq_num = 0; 
    Frame window[WINDOW_SIZE]; 
 
    printf("Starting Go-Back-N Simulation\n"); 
    printf("Window Size = %d, Max Seq = %d\n\n", WINDOW_SIZE, MAX_SEQ); 
 
    while (true) { 
        // Send frames in window 
        while ((next_seq_num < base + WINDOW_SIZE) && (next_seq_num < MAX_SEQ)) { 
            window[next_seq_num % WINDOW_SIZE].seq = next_seq_num % (MAX_SEQ + 1); 
            snprintf(window[next_seq_num % WINDOW_SIZE].data, sizeof(window[next_seq_num % 
WINDOW_SIZE].data), 
                     "Frame %d data", next_seq_num % (MAX_SEQ + 1)); 
            send_frame(window[next_seq_num % WINDOW_SIZE]); 
            next_seq_num++; 
        } 
 
        // Wait for ACK or timeout simulation 
        int ack = receive_ack(); 
 
        if (ack == -1) { 
            // Timeout occurred, retransmit all frames from base 
            printf("Timeout occurred. Resending frames from Seq = %d\n", base % (MAX_SEQ + 1)); 
            next_seq_num = base;  // Reset next_seq_num to base to resend 
            sleep(1); 
            continue; 
        } 
 
        // Check if ACK is valid and move base accordingly 
        int seq_in_window = base % (MAX_SEQ + 1); 
        if ((ack >= seq_in_window && ack < (seq_in_window + WINDOW_SIZE)) ||  
            (seq_in_window + WINDOW_SIZE > MAX_SEQ && ack < ((seq_in_window + WINDOW_SIZE) % 
(MAX_SEQ + 1)))) { 
            base = (ack + 1) % (MAX_SEQ + 1); 
            printf("ACK %d received. Sliding window base to %d\n", ack, base); 
        } else { 
            printf("Received invalid ACK %d\n", ack); 
        } 
 
        // Check if all frames sent and acknowledged 
        if (base == MAX_SEQ) { 
            printf("All frames sent and acknowledged.\n"); 
            break; 
        } 
    } 
 
    return 0; 
} 
OUTPUT: 
Starting Go-Back-N Simulation 
Window Size = 4, Max Seq = 7 
Sending Frame: Seq = 0, Data = Frame 0 data 
Sending Frame: Seq = 1, Data = Frame 1 data 
Sending Frame: Seq = 2, Data = Frame 2 data 
Sending Frame: Seq = 3, Data = Frame 3 data 
Enter ACK number received by sender (-1 for timeout/no ACK): 0 
ACK 0 received. Sliding window base to 1 
Sending Frame: Seq = 4, Data = Frame 4 data 
Sending Frame: Seq = 5, Data = Frame 5 data 
Sending Frame: Seq = 6, Data = Frame 6 data 
Sending Frame: Seq = 7, Data = Frame 7 data 
Enter ACK number received by sender (-1 for timeout/no ACK): 1 
ACK 1 received. Sliding window base to 2 
Sending Frame: Seq = 2, Data = Frame 2 data 
Sending Frame: Seq = 3, Data = Frame 3 data 
Sending Frame: Seq = 4, Data = Frame 4 data 
Enter ACK number received by sender (-1 for timeout/no ACK): 2 
ACK 2 received. Sliding window base to 3 
Sending Frame: Seq = 5, Data = Frame 5 data 
Sending Frame: Seq = 6, Data = Frame 6 data 
Enter ACK number received by sender (-1 for timeout/no ACK): -1 
Timeout occurred. Resending frames from Seq = 3 
Sending Frame: Seq = 3, Data = Frame 3 data 
Sending Frame: Seq = 4, Data = Frame 4 data 
Sending Frame: Seq = 5, Data = Frame 5 data 
Enter ACK number received by sender (-1 for timeout/no ACK): 3 
ACK 3 received. Sliding window base to 4 
Sending Frame: Seq = 4, Data = Frame 4 data 
Sending Frame: Seq = 5, Data = Frame 5 data 
Enter ACK number received by sender (-1 for timeout/no ACK): 4 
ACK 4 received. Sliding window base to 5 
Sending Frame: Seq = 6, Data = Frame 6 data 
Enter ACK number received by sender (-1 for timeout/no ACK): 5 
ACK 5 received. Sliding window base to 6 
Sending Frame: Seq = 6, Data = Frame 6 data 
Enter ACK number received by sender (-1 for timeout/no ACK): 6 
ACK 6 received. Sliding window base to 7 
All frames sent and acknowledged. 

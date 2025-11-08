Write a program for frame sorting techniques used in buffers. 
Aim: Implementing frame sorting techniques used in buffers 
DESCRIPTION: Frame sorting is a common operation in network programming and data 
communication, where incoming data frames need to be reordered based on sequence 
numbers before being passed to the higher layers. This is especially relevant in protocols like 
TCP, where frames (packets) may arrive out of order. 
• Each frame has a sequence number and data. 
• Frames are inserted into a buffer. 
• After all frames are received, the buffer is sorted using the sequence number. 
• Then, frames are processed in order, simulating how a communication protocol 
ensures correct sequencing. 
PROGRAM: 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_FRAMES 100 
#define DATA_SIZE  50 
typedef struct { 
int sequence_number; 
char data[DATA_SIZE]; 
} Frame; 
void swap(Frame *a, Frame *b) { 
Frame temp = *a; 
*a = *b; 
*b = temp; 
} 
void sort_frames(Frame frames[], int count) { 
for (int i = 0; i < count-1; i++) { 
for (int j = 0; j < count-i-1; j++) { 
if (frames[j].sequence_number > frames[j+1].sequence_number) { 
swap(&frames[j], &frames[j+1]); 
} 
} 
} 
} 
int main() { 
Frame buffer[MAX_FRAMES]; 
int frame_count; 
printf("Enter number of frames to receive: "); 
scanf("%d", &frame_count); 
if (frame_count > MAX_FRAMES || frame_count <= 0) { 
printf("Invalid number of frames.\n"); 
return 1; 
} 
for (int i = 0; i < frame_count; i++) { 
printf("Enter sequence number for frame %d: ", i + 1); 
scanf("%d", &buffer[i].sequence_number); 
printf("Enter data for frame %d: ", i + 1); 
scanf("%s", buffer[i].data); 
} 
sort_frames(buffer, frame_count); 
printf("\nProcessing frames in order:\n"); 
for (int i = 0; i < frame_count; i++) { 
printf("Frame Seq %d: Data = %s\n", buffer[i].sequence_number, buffer[i].data); 
} 
return 0; 
} 
OUTPUT: 
Enter number of frames to receive: 5 
Enter sequence number for frame 1: 3 
Enter data for frame 1: C 
Enter sequence number for frame 2: 1 
Enter data for frame 2: A 
Enter sequence number for frame 3: 5 
Enter data for frame 3: E 
Enter sequence number for frame 4: 2 
Enter data for frame 4: B 
Enter sequence number for frame 5: 4 
Enter data for frame 5: D 
Processing frames in order: 
Frame Seq 1: Data = A 
Frame Seq 2: Data = B 
Frame Seq 3: Data = C 
Frame Seq 4: Data = D 
Frame Seq 5: Data = E 
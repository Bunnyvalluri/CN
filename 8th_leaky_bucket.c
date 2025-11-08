8. Write a c program for congestion control using leaky bucket algorithm 
AIM: Implement the leaky bucket algorithm.
DESCRIPTION: This program simulates congestion control using the Leaky Bucket algorithm. It accepts packet sizes as input and manages them within a fixed bucket capacity. Incoming packets are either added to the bucket or dropped if the bucket overflows. The bucket "leaks" packets at a constant rate to regulate the output flow and prevent congestion.
•	A bucket has a fixed capacity (maximum number of packets it can hold).
•	It can leak (process) a fixed number of packets per unit time.
•	If incoming packets overflow the bucket capacity, they are discarded (representing congestion).
PROGRAM:
#include <stdio.h>
int main() {
    int bucket_size, leak_rate, n, i;
    int incoming_packet_size[100], bucket_content = 0;
    printf("Enter the bucket size (capacity): ");
    scanf("%d", &bucket_size);
    printf("Enter the rate at which packets leak (leak rate): ");
    scanf("%d", &leak_rate);
    printf("Enter the number of incoming packet entries: ");
    scanf("%d", &n);
    printf("Enter the size of each incoming packet:\n");
    for(i = 0; i < n; i++) {
        printf("Packet %d size: ", i + 1);
        scanf("%d", &incoming_packet_size[i]);
    }
    printf("\nTime\tIncoming\tBucket\t\tDropped\n");
    printf("Unit\tPacket\t\tContent\t\tPackets\n");
    printf("---------------------------------------------\n");
    for(i = 0; i < n; i++) {
        printf("%d\t", i + 1);
        printf("%d\t\t", incoming_packet_size[i]);
        if(incoming_packet_size[i] + bucket_content <= bucket_size) {
            bucket_content += incoming_packet_size[i];
            printf("%d\t\t", bucket_content);
            printf("0\n");
        } else {
             int dropped = (incoming_packet_size[i] + bucket_content) - bucket_size;
            bucket_content = bucket_size;
            printf("%d\t\t", bucket_content);
            printf("%d\n", dropped);
        }
        if(bucket_content < leak_rate)
            bucket_content = 0;
        else
            bucket_content -= leak_rate;
    }
    while(bucket_content > 0) {
        i++;
        printf("%d\t0\t\t%d\t\t0\n", i, bucket_content);
        if(bucket_content < leak_rate)
            bucket_content = 0;
        else
            bucket_content -= leak_rate;
    }
    return 0;
}
OUTPUT:
Enter the bucket size (capacity): 10
Enter the rate at which packets leak (leak rate): 4
Enter the number of incoming packet entries: 5
Enter the size of each incoming packet:
Packet 1 size: 6
Packet 2 size: 3
Packet 3 size: 7
Packet 4 size: 2
Packet 5 size: 5
Time    Incoming    Bucket      Dropped
Unit    Packet      Content     Packets
---------------------------------------------
1       6           6           0
2       3           5           0
3       7           8           2
4       2           6           0
5       5           7           0
6       0           3           0
7       0           0           0

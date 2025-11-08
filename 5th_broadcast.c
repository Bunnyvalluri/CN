Take an example sub net of host and obtain broadcast tree for the sub net
Aim:sub net of host and obtain broadcast tree
Description: All valid hosts in a subnet, we can imagine them as nodes in a tree, where a broadcast packet originates from the root and propagates to all hosts.
The program takes a subnet in the format IP/prefix (e.g., 192.168.1.0/29) as input.
 It calculates the network address, broadcast address, and total number of usable hosts.
 It stores all valid host IPs in an array.
  It then prints a binary broadcast tree of the hosts using recursion.
  Subnet basics:
A subnet is defined by an IP and a mask (e.g., 192.168.1.0/29).
From this, we can compute:
Network address
Broadcast address
First host
Last host
Number of hosts
Tree representation:
                192.168.1.4
           /                      \
   192.168.1.2                  192.168.1.6
     /        \                  /        \
192.168.1.1 192.168.1.3   192.168.1.5   (leaf)
Program:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
void print_ip(unsigned int ip) {
    struct in_addr addr;
    addr.s_addr = htonl(ip);
    printf("%s", inet_ntoa(addr));
}
void print_tree(unsigned int hosts[], int start, int end, int level) {
    if (start > end) return;
    int mid = (start + end) / 2;
    for (int i = 0; i < level; i++) printf("   ");
    print_ip(hosts[mid]);
    printf("\n");
    print_tree(hosts, start, mid - 1, level + 1);
    print_tree(hosts, mid + 1, end, level + 1);
}
int main() {
    char subnet[30];
    printf("Enter subnet (e.g., 192.168.1.0/29): ");
    scanf("%s", subnet);
    char *slash = strchr(subnet, '/');
    if (!slash) {
        printf("Invalid format. Use IP/prefix.\n");
        return 1;
    }
    *slash = '\0';
    int prefix = atoi(slash + 1);

    struct in_addr addr;
    inet_aton(subnet, &addr);
    unsigned int ip = ntohl(addr.s_addr);
    unsigned int mask = (0xFFFFFFFF << (32 - prefix)) & 0xFFFFFFFF;
    unsigned int network = ip & mask;
    unsigned int broadcast = network | (~mask);
    printf("\nNetwork Address: ");
    print_ip(network);
    printf("\nBroadcast Address: ");
    print_ip(broadcast);
    printf("\n");
    int host_count = broadcast - network - 1;
    printf("Number of Hosts: %d\n\n", host_count);
    unsigned int *hosts = malloc(host_count * sizeof(unsigned int));
    for (int i = 0; i < host_count; i++) {
        hosts[i] = network + 1 + i;
    }
    printf("Broadcast Tree:\n");
    print_tree(hosts, 0, host_count - 1, 0);

    free(hosts);
    return 0;
}
Output:
Enter subnet (e.g., 192.168.1.0/29): 192.168.1.0/29
Network Address: 192.168.1.0
Broadcast Address: 192.168.1.7
Number of Hosts: 6
Broadcast Tree:
192.168.1.3
   192.168.1.1
      192.168.1.2
   192.168.1.5
      192.168.1.4
      192.168.1.6




NR23                                                                                                                          [COMPUTER NETWORKS LAB] 
 
M.SHRAVANI,CSE |  35 
 
 
 
Experiment 10: Network Analysis Using Wireshark and NS2 Simulator 
10. Wireshark 
 i. Packet Capture Using Wire shark 
 ii. Starting Wire shark 
 iii. Viewing Captured Traffic 
 iv. Analysis and Statistics & Filters. 
 How to run Nmap scan Operating System Detection using  
Nmap Do the following using NS2 Simulator 
i. NS2 Simulator-Introduction 
ii.  ii. Simulate to Find the Number of Packets Dropped  
iii.  Simulate to Find the Number of Packets Dropped by TCP/UDP 
iv.   Simulate to Find the Number of Packets Dropped due to Congestion  
v.  Simulate to Compare Data Rate & Throughput. vi. Simulate to Plot Congestion for Different 
Source/Destination vii. Simulate to Determine the Performance with respect to 
Transmission of Packets 
 
1. AIM 
To analyze network traffic using Wireshark and simulate network behavior using NS2 to study 
packet drops, throughput, and congestion control. 
 
2. ALGORITHM / DESCRIPTION 
A. Wireshark 
1. Packet Capture: 
o Launch Wireshark and select a network interface. 
o Click “Start Capturing Packets” to begin live capture. 
NR23                                                                                                                          [COMPUTER NETWORKS LAB] 
 
M.SHRAVANI,CSE |  36 
 
2. Starting Wireshark: 
o Open the application from the start menu or terminal (wireshark). 
3. Viewing Captured Traffic: 
o Use the middle pane to examine individual packets. 
o Apply filters like ip, tcp, udp, icmp for specific analysis. 
4. Analysis and Statistics: 
o Use “Statistics” → “Protocol Hierarchy”, “Conversations”, “IO Graphs” to 
interpret results. 
5. Running Nmap: 
o Run nmap -sS <target IP> to perform a SYN scan. 
o Use nmap -O <target IP> for OS detection. 
B. NS2 Simulator 
1. Introduction: 
o NS2 is a discrete event simulator used to simulate routing, congestion, and 
protocols. 
2. Packet Drop Analysis: 
o Write a Tcl script with dropping logic using DropTail or RED. 
o Analyze using trace file and tools like awk. 
3. TCP/UDP Drop Detection: 
o Filter trace file for lines with tcp or udp and event d. 
4. Congestion Simulation: 
o Create two flows to one destination with limited bandwidth and buffer. 
5. Data Rate & Throughput Comparison: 
o Analyze received packet count and timestamps. 
6. Plot Congestion: 
o Use Xgraph to visualize congestion points. 
7. Performance Evaluation: 
o Calculate metrics like throughput, drop ratio, delay using trace files. 
 
NR23                                                                                                                          [COMPUTER NETWORKS LAB] 
 
M.SHRAVANI,CSE |  37 
 
3. SAMPLE TCL PROGRAM (NS2 Simulation for Packet Drop) 
tcl 
CopyEdit 
set ns [new Simulator] 
 
set nf [open out.nam w] 
$ns namtrace-all $nf 
 
set tf [open out.tr w] 
$ns trace-all $tf 
 
set n0 [$ns node] 
set n1 [$ns node] 
 
$ns duplex-link $n0 $n1 1Mb 10ms DropTail 
 
set udp [new Agent/UDP] 
$ns attach-agent $n0 $udp 
set null [new Agent/Null] 
$ns attach-agent $n1 $null 
$ns connect $udp $null 
 
set cbr [new Application/Traffic/CBR] 
$cbr set packetSize_ 500 
$cbr set interval_ 0.005 
$cbr attach-agent $udp 
 
$ns at 0.1 "$cbr start" 
$ns at 4.0 "$cbr stop" 
$ns at 5.0 "finish" 
 
NR23                                                                                                                          [COMPUTER NETWORKS LAB] 
 
M.SHRAVANI,CSE |  38 
 
proc finish {} { 
    global ns nf tf 
    $ns flush-trace 
    close $nf 
    close $tf 
    exec nam out.nam & 
    exit 0 
} 
 
$ns run 
 
4. OUTPUT 
Wireshark: 
 Captured packets listed in real-time. 
 Filters applied (e.g., tcp.port == 80). 
 Protocol statistics: TCP = 60%, UDP = 30%, ICMP = 10%. 
Nmap: 
nginx 
CopyEdit 
nmap -sS 192.168.1.1 
nmap -O 192.168.1.1 
NS2 Trace Output (filtered): 
css 
CopyEdit 
d -t 2.05 -s 0 -d 1 -p tcp ... 
 Xgraph shows drop and congestion points. 
 Throughput graph plots received data vs time. 
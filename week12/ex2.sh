gcc ex2.c -o ex2.exe
sysctl -a | grep machdep.cpu | ./ex2.exe >> ex2.txt  
CC=gcc #Compiler to call
CFlags=-std=c89 -o MyTail #Flags called with compiler
#Pattern: Target: Filename
#Targeted File is used as input file

all: MyTail

test: MyTail
	MyTail sample1.txt>result1.txt ; cmp result1.txt expected1.txt
clear: MyTail
	rm MyTail
	rm result*

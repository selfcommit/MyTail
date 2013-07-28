CC=gcc #Compiler to call
CFlags=-std=c89 -o MyTail #Flags called with compiler
#Pattern: Target: Filename
#Targeted File is used as input file

all: MyTail

test: MyTail
	./MyTail samples/sample1.txt > result1.txt ; cmp result1.txt expected/expected1.txt
	./MyTail samples/sample2.txt > result2.txt ; cmp result2.txt expected/expected2.txt
	./MyTail samples/sample3.txt > result3.txt ; cmp result3.txt expected/expected3.txt
	./MyTail samples/sample4.txt > result4.txt ; cmp result4.txt expected/expected4.txt
	
clear: MyTail
	rm MyTail
	rm result*

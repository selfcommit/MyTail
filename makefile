CC=gcc #Compiler to call
CFlags=-std=c89 -o MyTail_v2 #Flags called with compiler
#Pattern: Target: Filename
#Targeted File is used as input file

all: MyTail_v2

test: MyTail_v2
	./MyTail_v2 samples/sample1.txt > result1.txt ; cmp result1.txt expected/expected1.txt
	./MyTail_v2 samples/sample2.txt > result2.txt ; cmp result2.txt expected/expected2.txt
	./MyTail_v2 samples/sample3.txt > result3.txt ; cmp result3.txt expected/expected3.txt
	./MyTail_v2 samples/sample4.txt > result4.txt ; cmp result4.txt expected/expected4.txt
	
clean: MyTail_v2
	rm MyTail_v2
	rm result*

#include <fcntl.h>
#include <stdio.h>
#define blocksize 4096
int lines = 0, blockcount = 1, blocks_checked = 0,
  bytes_in_file = 0, blocks_in_file = 0, print = 0;
FILE *filehandle;
char buffer[blocksize];

 /*Tail remake version 2 written by Dan O'Boyle for Tom Limoncelli 8/13/2013 */
 /*In short: This version of tail will read blocks 1 at a time until it finds at least 10 lines
    It will then do its best to  print up to the last 10 lines of a file. */

int
main (int argc, char *argv[])
{
  if (argc > 2 || argc < 1)
    {
      write (2, "Usage: tail requires exactly 1 file\n", 37);
      return 1;
    }

/*main() opens the file and calls find_seek_place then print_remaining
(and does any other glue code).*/

  /*Open File */
  filehandle = fopen (argv[1], "r");

find_seek_place(filehandle);

print_remaining();


int find_seek_place(filehandle){
/*find_seek_place() takes the file handle and does the loop mentioned
above.  It calls count_newlines on each block*/





}

int count_newlines(){
/*count_newlines() counts the newlines in one block.  What we need to
know is how many newlines we've seen so far, and if we've seen the
10th we need to know how far into the block it was.  Sounds complex.
I'm sure you'll think of something good.*/
}

int print_remaining(){
/*print_remaining() takes a file handle and prints from the current seek
position to the end of the file.*/
}

/*use read() to read blocks 8000 bytes at a time.*/

/*Count total Bytes*/

/*Start from end backwards*/

/*analyse blocks one at a time to find lines*/

/*Count seeks untli 10*/

  /*move pointer to end of file */
  fseek (filehandle, 0, SEEK_END);
  /*get distance from beginning to end of file */
  bytes_in_file = ftell (filehandle);

  /*Solve for blocks in file (bytes/block size) */
  blocks_in_file = (bytes_in_file / blocksize);
}


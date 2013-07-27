#include <fcntl.h>
#include <stdio.h>
#define blocksize 4096
int lines = 0, blockcount = 1, blocks_checked = 0,
 bytes_in_file = 0, blocks_in_file = 0, print = 0;
FILE *filehandle;
char buffer[blocksize];

/*Tail remake written by Dan O'Boyle for Tom Limoncelli 6/13/2013*/
/*In short: This version of tail will read blocks 1 at a time until it finds at least 10 lines
It will then do its best to  print up to the last 10 lines of a file.*/

int
main (int argc, char *argv[])
{
  if (argc > 2 || argc < 1 )
    {
      write (2, "Usage: tail requires exactly 1 file\n", 37);
      return 1;
    }
/*Open File */
  filehandle = fopen (argv[1], "r");

/*move pointer to end of file */
  fseek (filehandle, 0, SEEK_END);
/*get distance from beginning to end of file */
  bytes_in_file = ftell (filehandle);

/*Solve for blocks in file (bytes/block size)*/
  blocks_in_file = (bytes_in_file / blocksize);

  /*Debug commented out 
  printf ("The File has %d bytes in total, and %d Blocks", bytes_in_file, blocks_in_file);*/

/*Read up to every Block in the file, until 10 lines are reached, moving backwards a block at a time*/
  while (blocks_checked <= blocks_in_file)
    {
      
      /*Determine offset from beginning of file*/
      if (bytes_in_file < blocksize)
	{
	  blockcount = bytes_in_file * -1;
	}
      else
	{
	  blockcount = blocks_checked * blocksize * -1;
	}

      /*Stop Tally at 10 lines set print flag */
      if (lines >= 10)
	{
	  print = 1;
	  blockcount = ((blocks_checked - 1) * blocksize * -1);
	  fseek (filehandle, blockcount, SEEK_END);
	  break;
	}

      /*Set File Pointer back by blockcount */
      fseek (filehandle, blockcount, SEEK_END);

      /*offset tally to account for new block check */
      lines = 0;
      /*Count total number of lines in block */
      while (fgets (buffer, blocksize, filehandle) != NULL)
	{
	  /*tally total lines for each \n found */
	  lines++;

	}
      /* Debug commented out
      printf ("%d lines found in block %d \n", lines, blocks);*/

      blocks_checked++;
/*If the number of blocks counted is > the number of blocks in the file, move pointer to the beginning of the file. 
Set print indicator.*/
      if (blocks_checked > blocks_in_file)
	{
	  fseek (filehandle, blockcount, SEEK_END);
	  print = 1;
	  break;
	}

    }

/*Check if print indicator is set, print by block if true*/
  if (print = 1)
    {
     /* Debug
     printf ("%d lines found before printing \n", lines);*/

      /*advance pointer to line 10 */
      if (lines > 10)
	{
	  while (lines - 10 > 0)
	    {
	      fgets (buffer, blocksize, filehandle);
	      lines--;
	     /* Debug commented out
         printf ("pointer is at line %d \n", lines);*/
	    }

	}
/*prints last 10 lines */
      while (lines > 0)
	{
	  fgets (buffer, blocksize, filehandle);
	  fputs (buffer, stdout);
	  lines--;
	}
    }


  /*close file */
  fclose (filehandle);

}

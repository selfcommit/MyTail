#include <unistd.h>

int main (int argc, char *argv[])
{
char buffer[4]="test";
write (1, "Main called successfully\n",25); 

find_seek_place(buffer);

count_newlines();

print_remaining();
}

int find_seek_place(char buffer[4])
{
write (1,"Find_Seek_Place called successfully\n",36);
write (1,buffer,4);
}

int count_newlines()
{
write (1,"count_newlines called successfully\n", 35);
}

int print_remaining()
{
write (1,"print_remaining called successfully\n",36); 
}

#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

// Static variable holding line
static char * lineRead = (char *) 0;

char * readlineGets()
{
  // Verify buffer allocation
  if (lineRead)
  {
    free (lineRead);
    lineRead = (char *) 0;
  }

  // Get a line from the user
  lineRead = readline("");

  // Save text in history
  if (lineRead && *lineRead)
  {
    add_history(lineRead);
  }
  return (lineRead);
}

int main(int argc, char ** argv)
{
  printf("Test readline \n");

  printf("Type something: ");
  while(1)
  {
    readlineGets();
  }

  return 0;
}

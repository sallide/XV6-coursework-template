#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"

void execute_line(char** args) {

  // Use fork() to create a child process. Determine if the process
  // is a parent or a child, and run exec() if it is a child, and
  // run wait() if it is a parent.
  // For guidance, the model solution has 9 lines of code.


    int f = fork(); // from this point, two processes run the below code concurrently
    if (f == 0) {
        exec(args[0], args); // Child process executes the command.
        //int exit(int status); 
    } else {
        wait(); // Parent waiting for child process to exit.
    }
}


int main(int argc, char *argv[]) {

  // Two pointers: to a command and to a null terminator.
  char *args[2] = {0};
  // Fixed-size storage for reading in a line of input, and a pointer
  // to a particular character in this storage.
  char buf[512], *b;
  // Point b to the first character in the line.

    *b = buf; 

  // Read characters from the standard input. When we find '\n' that
  // means one line has terminated - execute the command.
  fprintf(2, "Please enter command and press enter (type 'q' to exit):\n");
  while (read(0, b, 1) > 0) {
    // Check the current character in b. If it is not special, move the pointer
    // b to the next character and continue reading. 
    // 
    if (*b == '\n') {
        *b = 0; //test 
        if (buf[0] == 'q') { 
            break; }


        args[0] = buf; 
        args[1] = 0; 
        execute_line(args); 
        
        b = buf; 
    } else {
        b++;
    }


    // If the command string has
    // been fully entered ('\n' is found in b), execute the command by calling
    // execute_line().
    // For guidance, the model solution has 10 lines of code in this loop.
  }
  exit(0);
}
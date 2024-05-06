# Project get_next_line

## Description

The get_next_line project consists of a function in C that reads a line from a given file descriptor (such as a file, terminal, or even a network connection) and returns it with each function call. The aim is to implement this function efficiently, using minimal resources, and allowing for easy integration into other programs.

## Features

- Reads lines from a file descriptor
- Handles different end-of-line characters (newline)
- Capable of reading files of any size, line by line
- Manages special cases such as empty files or end-of-file situations

## Usage

To use the get_next_line function in your program, you need to include the corresponding header file and compile your code with the get_next_line function. Here is a minimal example of usage:

```c
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

    // Open the file in read-only mode
    fd = open(argv[1], O_RDONLY);
    // -1 in case of an error
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    // Retrieve the next line with each call
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);  
    }
    // Close the file descriptor
    close(fd); 
    return 0;
}

*This project has been created as part of the 42 curriculum by zzhu*

Description:
This project is part of the 42 curriculum and consists of implementing the get_next_line function in C.
The goal is to read a file descriptor line by line and return one line each time the function is called.
The function reads the file using a buffer of size BUFFER_SIZE. Since a line can be longer than the buffer, the program stores the read chunks in memory until a newline character is found. Once a newline is detected (or the end of the file is reached), the stored data is used to build the line that will be returned.
This project mainly focuses on handling file reading, memory allocation, and managing data across multiple reads, while making sure there are no memory leaks and that different buffer sizes work correctly.

Instructions:
To compile this project you create the "main.c" and include the "get_next_line.h":
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line.h get_next_line_utils.c
You can try to change BUFFER_SIZE=42

Resources:
I watched the tutorial of Oceano on youtube and understood, how to use lists. Using list feels like the universal cheatcode, it is very flexible.
Then I used AI to get a refresh on lists, how to manipulate them.

Detailed explanation and justification of the algorithm selected for this project:
In this project, the function reads the files in number of BUFFER_SIZE chunks of data. If in the current chunk did not find any newline character, the program stores it in a linked list by creating/appending (on the heap memory) on the linked list and the repeats the process (read and storing).
If the program finds a newline, the program stores it in the linked list and stops to read new chunks of data. It then proceeds to allocate a memory of size equal to the head of the linked list until the newspace included minus the number of placeholder characters, it also copies it to this new allocated memory, during the copy of the tail node it makes the copied characters to a placeholder character. It then proceed to free all the linked list's node until the tail of the linked list(the tail is not freed), the tail will be freed naturally at the end of the file because the program does not execute the read/store to list cycle because the number of characters read is zero.
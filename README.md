*This project has been created as part of the 42 curriculum.*

Get Next Line
Description

Get Next Line is a project from the 42 curriculum. The goal is to create a function that reads a file descriptor one line at a time.

Each call returns the next line, including the newline character when present. The function must also handle the end of a file, even when the last line does not end with a newline.

This project introduces several C programming concepts, such as file descriptors, static variables, dynamic memory allocation and buffer management.

Instructions
Compilation

The project can be compiled using cc with the following flags:

-Wall
-Wextra
-Werror

The BUFFER_SIZE macro can be defined during compilation to determine how many bytes are read at a time.

The project consists of three files:

get_next_line.c
get_next_line_utils.c
get_next_line.h
Usage

Include get_next_line.h in your program and call get_next_line() with a valid file descriptor.

The returned line must be freed after use to avoid memory leaks.

Algorithm

The algorithm uses a static variable to preserve unread data between function calls.

Reading: Data is read from the file descriptor in chunks using read(), with the size determined by BUFFER_SIZE.
Storage: The read data is appended to a static variable so that previously read characters are not lost.
Line extraction: When a newline character is found, the first complete line is extracted and returned.
Persistence: Any remaining characters are preserved for the next call.
End of file: If EOF is reached, the remaining characters are returned as the final line. If no data remains, the function returns NULL.
Algorithm choice

This approach avoids reading the entire file into memory and allows the function to process large files progressively.

Using a static variable ensures that unread data remains available between calls. The buffer-based approach also makes the function adaptable to different BUFFER_SIZE values.

Project Structure
get_next_line.c: Main function and reading algorithm.
get_next_line_utils.c: Helper functions for string manipulation.
get_next_line.h: Function prototypes and definitions.
README.md: Project documentation.
Resources
Documentation
read() - Linux Manual
malloc() - Linux Manual
free() - Linux Manual
C Documentation - cppreference
AI Usage

ChatGPT was used exclusively to write and structure this README file, including organizing the sections and improving the documentation.

No AI tools were used for coding, debugging, or implementing the project. The entire source code was written independently.

Conclusion

Get Next Line provides a practical introduction to file handling in C, static variables, dynamic memory allocation and buffer management. It helps develop a better understanding of how data can be read and processed efficiently.

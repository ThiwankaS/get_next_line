#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 100

// Checks if a character is a whitespace
int ft_isnewline(int c)
{
    return (c == '\n');
}

// Prints a string, skipping leading whitespace
void ft_printstr(char *str)
{
    while (*str) // Print the remaining string
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1); // Correct size for '\n'
}

int main(void)
{
    int fd;
    ssize_t bytes_read;
    char buffer[BUFFER_SIZE];

    // Open the file
    fd = open("sample.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Print content header
    ft_printstr("Content:\n");

    // Read and process the file content
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE - 1)) > 0)
    {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        ft_printstr(buffer);      // Print the string
    }

    if (bytes_read == -1)
    {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    close(fd); // Close the file
    return 0;
}

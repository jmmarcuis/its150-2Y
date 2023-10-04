#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 100

int main()
{
    int fd //file descriptor variable for the named pipe
    char buffer[BUFFER_SIZE] // 100 Character buffer 
    ssize_t bytes_read;

    //Open the named pipe for reading using the open system call using the O_Rdonly Flag
    // Whilst implementing error checking
    fd = open("myfifo", O_RDONLY)
    if (fd == -1) {
        perror ("open");
        return 1;
    }

    //While waiting for a message from the write.c program, the terminal will display the current message from the writer
    printf("Waiting for message.....")

    //Read data from the named pipe using the read system call from the buffer whilst implementing error checking principle
    // And stores the bytes read in the bytes_read variable

    bytes_read = read(fd, buffer, sizeof(buffer));

    if (bytes_read == -1) {
        perror ("read");
        return 1;
    }

    // If sucessfully recieved an message from the write program, it will display the message in the terminal console
    printf("Message from Write Program!: %s\n", buffer);
    close(fd)

    return 0;

}
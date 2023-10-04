#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 100

int main()
{

  
    int fd; // File descriptor for the named pipe
    char buffer[BUFFER_SIZE];

    // Create a named pipe using nknod system call, specifying the name "nyfifo," setting the type as a FIOFO(S_IFIFO), 11 and granting read and write permissions (0666)
    if (mknod("myfifo", S_IFIFO | 0666, 0) == -1)
    {
        perror("mknod");
        return 1;
    }

    // Open the named pipe for writing using the open system call with the O_WRONLY, obteining a file descriptor fd
    //  check for error in opening the pipe.
    fd = open("myfifo", O_WRONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // Prompts the userto enter message of up to BUFFER_SIZE characters from the standard input (stdin)
    // and stores at in the buffer.
    printf("Enter a message to sent (max %d characters): ", BUFFER_SIZE);
    fgets(buffer, sizeof(buffer), stdin);


    //Write user message from the buffer through the pipe using the write system call function
    //Whilst also implementing error checking
    if (write(fd,buffer,strlen(buffer)) == -1) {
            perror("WRITE ERROR");
            return 1;
    }

    //Display the sent message to the console
    printf("Message sent: %s", buffer);

    //Close the fd with the named pipe
    close(fd);

    return 0;


}
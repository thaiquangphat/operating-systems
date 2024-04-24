#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <stdlib.h>

int main (int argc, char *argv[], char **envp) {
    int fd = open("shared_file.txt", O_RDWR | O_CREAT, 0666);
    ftruncate(fd, 16);

    char *mapm = mmap(NULL, 16, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (argc < 2) {
        printf("USAGE: %s read | write", argv[0]);
        return 0;
    }
    if (strcmp(argv[1], "read\0") == 0) {
        printf("Mapped memory content: %s\n", mapm);
    }
    else if (strcmp(argv[1], "write\0") == 0) {
        sprintf(mapm, "%s", argv[2]);
    }
    else {
        printf("Command not support");
    }
    
    close(fd);
    return 0;
}


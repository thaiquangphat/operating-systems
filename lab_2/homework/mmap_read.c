#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

int main() {
    int fd = open("shared_file.txt", O_RDONLY, 0666);
    ftruncate(fd, 5000);
    char *mapm = mmap(NULL, 5000, PROT_READ, MAP_PRIVATE, fd, 0);
    printf("Mapped memory content: %s\n", mapm);
    close(fd);
    return 0;
}
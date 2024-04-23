#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

int main() {
    int fd = open("shared_file.txt", O_RDWR | O_CREAT, 0666);
    ftruncated(fd, 16);
    char *mapm = mmap(NULL, 5000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    char str[] = "Hello Paul\n";
    sprintf(mapm, str);
    close(fd);
    return 0;
}
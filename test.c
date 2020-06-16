#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void func(char *data) {
        char buffer[32];

        if (strlen(data) < 32)
                return;

        long magic = *((long*) data);
        if (magic == 0x4947464841424544) {
                strcpy(buffer, data);
                printf("%s\n", buffer);
        }
        return;
}

int main(int argc, char **argv) {
    size_t size = 16384;
    char *buffer = (char*) calloc(1, size + 1);
    read(0, buffer, size);
    func(buffer);
    free(buffer);
    return 0;
}


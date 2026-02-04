#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    for(int i = 1; i < argc; i++) {
        ssize_t written = write(1, argv[i], strlen(argv[i]));
        // 1 = fd(file descriptor) for stdout
        // 2 = fd for stderr
        if(written == -1) {
            write(2, "Error writing to stdout\n", 24);
            return 1;
        }

        if (i < argc - 1) {
            write(1, " ", 1);
        }
    }
    write(1, "\n", 1);

    return 0;
}

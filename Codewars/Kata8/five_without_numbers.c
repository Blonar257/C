#include <stdio.h>

int unusual_five(void);

int main() {
    printf("5: %d", unusual_five());

    return 0;
}


int unusual_five (void)
{
    char name[] = "Blon";
	return sizeof(name);
}

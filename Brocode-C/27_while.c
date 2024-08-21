#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool again = true;
    int run = 1;

    while (again)
    {
        printf("Run: %d\n", run);
        run += 1;
        if (run > 5)
        {
            again = false;
        }
    }




    return 0;
}

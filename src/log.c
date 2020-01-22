#include "log.h"

// ___________________________________________________________________________
bool checkArguments(int argc, char** argv)
{
    if ( argc < 2 )
    {
        fprintf(stdout, "usage: %s <device>\n", *(argv+0));
        return 0;
    }
    return 1;
}

// ___________________________________________________________________________
void logLoop(int argc, char** argv)
{
    int fd = open(*(argv+1), O_RDONLY);

    struct input_event* ev = (struct input_event*) malloc(sizeof(struct input_event));
    memset(ev, 0, sizeof(struct input_event));

    while (1)
    {
        read(fd, ev, sizeof(struct input_event));

        if ( (*ev).type == 1 )
        {
            fprintf(stdout, "Key %i state %i\n", (*ev).code, (*ev).value);
        }
    }

    free(ev);
}


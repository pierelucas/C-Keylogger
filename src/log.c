// Copyright 2020 (C) Julian Huch
// autor: Julian Huch

#include "log.h"

const char* kDevice;

// ___________________________________________________________________________
bool checkArguments(int argc, char** argv)
{
    if ( argc < 2 )
    {
        fprintf(stdout, "One argument needed.\n", *(argv+0));
        fprintf(stdout, "-h     -- for help message.\n");
        return 0;
    }

    int opt = getopt(argc, argv, ":hd:");
    while ( opt != -1 )
    {
        switch( opt )
        {
         case 'h':
             fprintf(stdout, "[HELP]\n");
             fprintf(stdout, "Options:\n");
             fprintf(stdout, "%10s -d <device>      -- device to listen.\n", *(argv+0));
             fprintf(stdout, "%10s -h               -- for help message\n", *(argv+0));
             return 0;
        case 'd':
            kDevice = optarg;
            return 1;
        case ':':
            fprintf(stdout, "option: %c needs a value.\n");
            return 0;
        case '?':
            fprintf(stdout, "unknown option: %c\n", optopt);
            return 0;
        }
    }
}

// ___________________________________________________________________________
void logLoop()
{
    int fd = open(kDevice, O_RDONLY);

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
    free((void*)kDevice);
}


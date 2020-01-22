// Copyright 2020 (C) Julian Huch
// Autor: Julian Huch

#include "log.h"

// Main function.
int main(int argc, char** argv)
{
    if ( !checkArguments(argc, argv) )
    {
        fprintf(stdout, "Error in parsing arguments.\n");
        return EXIT_FAILURE;
    }

    logLoop(argc, argv);
    return EXIT_SUCCESS;
}

// Copyright 2020 (C) Julian Huch
// Autor: Julian Huch

#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

extern const char* kDevice;

bool checkArguments(int argc, char** argv);

void logLoop();
 

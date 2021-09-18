#include <unistd.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_buffer
{
    int i;
    int j;
    char *buf;
}   t_buffer;

t_buffer g_buffer;
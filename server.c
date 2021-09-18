#include "server.h"

void get_signal(int sig)
{
    sig -=30;
    if(g_buffer.j == 7)
        g_buffer.buf[g_buffer.i] = 0;
    g_buffer.buf[g_buffer.i] += sig * 1<<g_buffer.j;
    if(g_buffer.j == 0)
    {
        if(!g_buffer.buf[g_buffer.i])
        {
            write(1,g_buffer.buf,g_buffer.i);
            write(1,"\n",1);
            g_buffer.i = 0;
            g_buffer.j = 7;
            return;
        }
        g_buffer.j = 7;
        g_buffer.i++;
    }
    else
        g_buffer.j--;
}

int main(void)
{
    int pid = getpid();

    printf("PID = %d\n", pid);
    g_buffer.i = 0;
    g_buffer.j = 7;
    g_buffer.buf = malloc(100000);
    signal(SIGUSR1,get_signal); 
    signal(SIGUSR2,get_signal);
    while(1)
    {
        pause();
    }
    return 0;
}
#include "client.h"

void send_char(pid_t pid,char c, int i)
{
    if(!i)
    {
        return;
    }
    i--;
    send_char(pid,c/2,i);
    if(c % 2)
        kill(pid, SIGUSR2);
    else
        kill(pid, SIGUSR1);
    usleep(30);
}

int main(int c, char **v)
{
    pid_t pid = (pid_t)ft_atoi(v[1]);
    int i;
    while(1)
    {
        send_char(pid,v[2][i],8);
        if(!v[2][i])
            return 0;
        i++;
    }
}
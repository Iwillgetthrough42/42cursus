#include "minitalk.h"

static t_msg msgbit;

void getbitbybit(int bit)
{
  msgbit.num += (bit & 1) << msgbit.size;
  msgbit.size++;
  if (msgbit.size == 7)
  {
    write(1, &msgbit.num, msgbit.size);
    msgbit.num = 0;
    msgbit.size = 0;
  }
}

int main()
{
  int   pid;
  char  *str;

  pid = getpid();
  str = ft_itoa(pid);
  write(1, str, ft_strlen(str));
  msgbit.num = 0;
  msgbit.size = 0;
  write(1, "\n", 1);
  while (1)
  {
    signal(SIGUSR2, getbitbybit);
    signal(SIGUSR1, getbitbybit);
    pause();
  }
}

#include "apue.h"
#include "fcntl.h"
#include "stdio.h"

#define	BUFFSIZE	400

int
main(void)
{
	int		n;
	char	buf[BUFFSIZE];
    int flag = fcntl(STDOUT_FILENO,F_GETFD,0);
    if(flag < 0){
        err_sys("fcntl get error");
    }
    flag = flag | O_SYNC;
    if(fcntl(STDOUT_FILENO,F_SETFD,flag) < 0){
        err_sys("fcntl set error");
    }
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");

	if (n < 0)
		err_sys("read error");

	exit(0);
}

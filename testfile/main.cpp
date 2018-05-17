#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <net/if_arp.h>
#include <netpacket/packet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
using namespace std;
int modify_config_ini1(char *p2ip, char *p2netmask, char *p2gateway)
{
        int fd;
    struct flock flock;
    flock.l_type = F_WRLCK;
    flock.l_whence = SEEK_SET;
    flock.l_start = 0;
    flock.l_len = 0;
    flock.l_pid = -1;

    fd = open("/home/zen/res/ip.ini", O_RDWR|O_TRUNC);
    fcntl(fd, F_SETLKW, &flock);

    if(fd < 0)
    {

        return -1;
    }

    char buf[128] = {'\0'};
    char page[1024] = {'\0'};
    while(read(fd, buf, sizeof(buf)) > 0)
    {
        strcat(page, buf);
        memset(buf, '\0', sizeof(buf));
    }



    char tmp[1024] = {'\0'};
    sprintf(tmp,"IPADDR=%s \nNETMASK=%s \nGATEWAY=%s \n",p2ip,p2netmask,p2gateway);


    if(write(fd, tmp, strlen(tmp)) != strlen(tmp)){

    }
    close(fd);

    return 0;
}
int main()
{
    modify_config_ini1("192.168.1.219","255.255.255.0","192.168.1.1");
    cout << "Hello World!" << endl;
    return 0;
}


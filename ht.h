#include <stdbool.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>

using namespace std;

typedef struct HTSocket{
    int clientSD;
    sockaddr_in sendSockAddr;
    void InitializeConnection(char* targetIP, int port){
        struct hostent* host = gethostbyname(targetIP);
        bzero((char*)&sendSockAddr, sizeof(sendSockAddr));
        sendSockAddr.sin_family = AF_INET;
        sendSockAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));
        sendSockAddr.sin_port = htons(port);
        int clientSD = socket(AF_INET, SOCK_STREAM, 0);
    }
    bool TryConnect(){
        int status = connect(clientSD, (sockaddr*)&sendSockAddr, sizeof(sendSockAddr));
        if (status < 0)
            return false;
        return true;
    }

};
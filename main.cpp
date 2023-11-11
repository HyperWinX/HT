#include <iostream>
#include "ht.h"

int main(){
    HTSocket socket;
    char* ip = "127.0.0.1";
    socket.InitializeConnection(ip, 8080);
    bool connected = socket.TryConnect();
    if (connected == false){
        cerr << "Connection failure\n";
        return -1;
    }
    cout << "Hello World\n";
}
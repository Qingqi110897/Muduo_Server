#include "chatserver.hpp"
#include "chatservice.hpp"
#include <iostream>
#include <signal.h>
using namespace std;


int main()
{
    EventLoop loop;
    InetAddress addr("127.0.0.1",3360);
    ChatServer server(&loop,addr,"ChatServer");

    server.start();
    loop.loop();
}
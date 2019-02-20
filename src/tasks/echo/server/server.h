//
// Created by michael on 11.01.19.
//

#ifndef CP_TASKS_SERVER_H
#define CP_TASKS_SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <unistd.h>


class EchoServer {
    int max_events;
    int master;
    int epoll;
    static constexpr size_t buff_size = 10000;

    void addToEPoll(int socket);

    void nonblock(int fd);

public:
    EchoServer(uint16_t port, int max_events);
    void start_loop();

    ~EchoServer();
};

#endif //CP_TASKS_SERVER_H

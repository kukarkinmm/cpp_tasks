//
// Created by michael on 11.01.19.
//

#include <cerrno>
#include <iostream>

#include "server.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

void EchoServer::nonblock(int fd) {
    int flags;
#if defined(O_NONBLOCK)
    if (-1 == (flags = fcntl(fd, F_GETFL, 0)))
        flags = 0;
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
#else
    flags = 1;
    ioctl(fd, FIOBIO, &flags);
#endif
}

void EchoServer::addToEPoll(int socket) {
    struct epoll_event Event;
    Event.data.fd = socket;
    Event.events = EPOLLIN;
    epoll_ctl(epoll, EPOLL_CTL_ADD, socket, &Event);

}

EchoServer::EchoServer(uint16_t port, int max_events) : max_events(max_events),
                                                        master(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)), epoll(epoll_create1(0)) {
    struct sockaddr_in sockAddr;
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(port);
    sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(master, (struct sockaddr *)(&sockAddr), sizeof(sockAddr));

    nonblock(master);

    listen(master, SOMAXCONN);

    addToEPoll(master);
}

[[noreturn]] void EchoServer::start_loop() {
    std::cout << "Server has started\n" ;
    while(true) {
        struct epoll_event Events[max_events];
        int N = epoll_wait(epoll, Events, max_events, -1);
        for (size_t i = 0; i < N; ++i) {
            if (Events[i].data.fd == master) {
                int slave = accept(master, 0, 0);
                nonblock(slave);
                addToEPoll(slave);

                std::cout << "Client connected\n";

            } else {
                static char buff[buff_size];
                ssize_t recvResult = recv(Events[i].data.fd, buff, buff_size, MSG_NOSIGNAL);
                if (recvResult == 0 && errno != EAGAIN) {
                    shutdown(Events[i].data.fd, SHUT_RDWR);
                    close(Events[i].data.fd);

                    std::cout << "Client disconnected\n";
                } else if (recvResult > 0) {
                    send(Events[i].data.fd, buff, recvResult, MSG_NOSIGNAL);
                    buff[recvResult] = '\0';
                    std::cout << "Echo " << buff << '\n';
                }
            }
        }
    }
}

EchoServer::~EchoServer() {
    shutdown(master, SHUT_RDWR);
    close(master);
}

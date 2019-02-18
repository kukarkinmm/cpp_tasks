//
// Created by michael on 11.01.19.
//

#include "client.h"

#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

Client::Client(std::string address, int port) : client_socket (socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)){
    struct sockaddr_in sockAddr;
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(port);
    sockAddr.sin_addr.s_addr = inet_addr(address.c_str());

    connect(client_socket, (struct sockaddr*) (&sockAddr), sizeof(sockAddr));
}

void Client::start_loop() {
    while (true) {
        static std::string buff;
        static char buff1[buff_size];
        std::getline(std::cin, buff);
        send(client_socket, buff.c_str(), buff.size(), MSG_NOSIGNAL);
        int n = recv(client_socket, buff1, buff_size, MSG_NOSIGNAL);
        buff1[n] = '\0';
        std::cout << buff1 << '\n';
    }
}

Client::~Client() {
    shutdown(client_socket, SHUT_RDWR);
    close(client_socket);
}

//
// Created by michael on 11.01.19.
//

#ifndef CP_TASKS_CLIENT_H
#define CP_TASKS_CLIENT_H

#include <string>
#include <iostream>
#include <cstddef>

class Client {
    int client_socket;
    static constexpr size_t buff_size = 10000;

public:
    Client(std::string address, int port);
    void start_loop();
    virtual ~Client();
};

#endif //CP_TASKS_CLIENT_H

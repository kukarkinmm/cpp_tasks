//
// Created by michael on 11.01.19.
//

#include "server.h"

int main() {
    EchoServer server(8001, 32);
    server.start_loop();
    return 0;
}
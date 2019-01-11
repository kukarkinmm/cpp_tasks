//
// Created by michael on 11.01.19.
//

#include "client.h"

int main() {
    Client cl("127.0.0.1", 8001);
    cl.start_loop();
    return 0;
}

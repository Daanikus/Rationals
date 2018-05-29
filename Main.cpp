#include "Integer.h"

using namespace cosc326;

int main() {
    Integer i("-123456");
    Integer j("-987654321");
    Integer r = i + j;
    std::cout << r.getValue();
    return 0;
}


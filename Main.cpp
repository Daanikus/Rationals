#include "Integer.h"

using namespace cosc326;

int main() {
    Integer i("123456");
    Integer j("987654321");
    Integer r = i + j;
    std::cout << r.getValue() << '\n';
    r = i;
    std::cout << r.getValue() << '\n';
    r = j;
    i = j;
    std::cout << (r == i) << '\n';
    Integer x("523");
    Integer y("102524524");
    Integer z;
    z = x * y;
    std::cout << "523 * 102524524 = " << z.getValue() << '\n';
    Integer a1("5");
    Integer a2("3");
    a2 += a1;
    std::cout << "5 + 3 = " << a2.getValue() << '\n';
    return 0;
}


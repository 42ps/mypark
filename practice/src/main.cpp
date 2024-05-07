#include <iostream>
#include <type_traits>

using namespace std;

template <typename T, typename std::enable_if<std::is_integral<T>::value,
                                              T>::type* = nullptr>
void func(T a) {
    cout << a << endl;
};

int main() {
    // bool i = std::is_integral<int>::value;
    // bool f = std::is_integral<float>::value;
    // std::cout << i << std::endl;
    // std::cout << f << std::endl;

    double a = 1.1;
    func(a);

    // int a = 1;
    // func(1);
    return 0;
}

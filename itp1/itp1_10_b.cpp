#include <iostream>#include <iomanip>#define _USE_MATH_DEFINES#include <cmath>int main(){    double a, b, c;    std::cin >> a >> b >> c;    double h = b * std::sin(M_PI * c/180);    double d = std::sqrt(std::pow(a, 2) + std::pow(b,2) - 2 * a * b * std::cos(M_PI * c/180));    double s = a * h / 2;    std::cout << std::fixed;    std::cout << std::setprecision(4) << s << std::endl;    std::cout << std::setprecision(4) << a + b + d << std::endl;    std::cout << std::setprecision(4) << h << std::endl;    return 0;}
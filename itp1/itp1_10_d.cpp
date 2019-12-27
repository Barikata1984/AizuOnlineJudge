#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> abses(n);
    int val;
    for(int i = 0; i < n; ++i){
        std::cin >> abses.at(i);
    }
    for(int i = 0; i < n; ++i){
        std::cin >> val;
        abses.at(i) = std::abs(abses.at(i) - val);
    }

    double sum = std::accumulate(abses.begin(), abses.end(), 0.0);
    double squaredSum = std::accumulate(abses.begin(), abses.end(), 0.0, [](int first, int second){return first + std::pow(second, 2);});
    long long cubedSum = std::accumulate(abses.begin(), abses.end(), 0.0, [](long first, long second){return first + std::pow(second, 3);});
 
    std::cout << std::fixed;
    std::cout << sum << std::endl;
    std::cout << std::sqrt(squaredSum) << std::endl;
    std::cout << std::cbrt(cubedSum) << std::endl;
    std::cout << *std::max_element(abses.begin(), abses.end()) << std::endl;

    return 0;
}
#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> vec(n + 1);
    vec.at(0) = 1;
    vec.at(1) = 1;
    for(int i = 2; i <= n; ++i){
        vec.at(i) = vec.at(i - 1) + vec.at(i - 2);
    }

    std::cout << vec.at(n) << std::endl;

    return 0; 
}
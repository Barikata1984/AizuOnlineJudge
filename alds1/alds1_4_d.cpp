#include <algorithm>
#include <iostream>
#include <vector>

int main(){
    int n, k;
    std::cin >> n >> k;

    std::vector<int> w(n), cumSumW(n + 1, 0);
    for(int i = 0; i < n; ++i){
        std::cin >> w.at(i);
        cumSumW.at(i + 1) = cumSumW.at(i) + w.at(i);
    }

    int load = cumSumW.at(n) / k;
    if(0 != cumSumW.at(n) % k){
        ++load;
    }

    int count = k - 1; // if count differes from k, every value is okay
    while(k != count){
        auto itr = std::begin(cumSumW);
        count = 0;
        while(std::end(cumSumW) != itr){
            itr = std::upper_bound(itr, std::end(cumSumW), *itr + load) - 1;
            ++count;
        }

        ++load;
    }

    std::cout << load - 1 << std::endl;

    return 0;
}

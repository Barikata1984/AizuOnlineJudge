#include <iostream>
#include <vector>

int main(){
    int n, k;
    std::cin >> n >> k;

    std::vector<int> w(n);
    std::vector<int> cumSumW(n + 1, 0);
    for(int i = 0; i < n; ++i){
        std::cin >> w.at(i);
        cumSumW.at(i + 1) = cumSumW.at(i) + w.at(i);
    }

    int unitW = cumSumW.at(n) / k;
    while(){

while(int i = unitW; i < cumSumW.at(n); i += unitW){
            auto itr = std::lower_bound(std::begin(cumSumW), std::end(cumSumW), i);


#include <iostream>
#include <vector>

int main(){
    int n, limit;
    std::cin >> n >> limit;

    std::vector<int> value(n), weight(n);
    for(int i = 0; i < n; ++i){
        std::cin >> value.at(i) >> weight.at(i);
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(limit + 1, 0));

    for(int i = 0; i < n; ++i){
        for(int w = 0; w <= limit; ++w){
            if(weight.at(i) <= w){
                dp.at(i + 1).at(w) += std::max(dp.at(i).at(w - weight.at(i)) + value.at(i), dp.at(i).at(w));
            }else{
                dp.at(i + 1).at(w) = dp.at(i).at(w);
            }
        }
    }

    std::cout << dp.at(n).at(limit) << std::endl;

    return 0;
}

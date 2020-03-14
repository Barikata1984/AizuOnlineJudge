#include <algorithm>
#include <iostream>
#include <vector>

#define INF 1000000007

int main(){
    int limit, m;
    std::cin >> limit >> m;

    std::vector<int> c(m);
    for(int i = 0; i < m; ++i){
        std::cin >> c.at(i);
    }

    std::sort(std::begin(c), std::end(c));

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(limit + 1, INF));
    for(int i = 0; i <= m; ++i){
        dp.at(i).at(0) = 0;
    }

    for(int i = 0; i < m; ++i){
        for(int amount = 0; amount <= limit; ++amount){
            if(c.at(i) <= amount){
                dp.at(i + 1).at(amount) = std::min(dp.at(i + 1).at(amount - c.at(i)) + 1, dp.at(i).at(amount));
            }else{
                dp.at(i + 1).at(amount) = dp.at(i).at(amount);
            }
        }
    }

    std::cout << dp.at(m).at(limit) << std::endl;

    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

void print(std::vector<int> vec){
    int n = vec.size();
    for(int i = 0; i < n; ++i){
        std::cout << vec.at(i);
        if(n - 1 != i){
            std::cout << " ";
        }else{
            std::cout << std::endl;
        }
    }
}

int main(){
    int n;
    std::cin >> n;

    std::vector<int> num(n);
    for(int i = 0; i < n; ++i){
        std::cin >> num.at(i);
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
    for(int w = 2; w <= n; ++w){
        for(int l = 0; l < n; ++l){ // left
            int r = l + w;
            if(r > n){
                continue;
            }

            if(dp.at(l + 1).at(r - 1) == w - 2 && std::abs(num.at(l) - num.at(r - 1)) <= 1){
                dp.at(l).at(r) = w;
            }

            for(int mid = l;mid <= r;mid++){
                dp.at(l).at(r) = std::max(dp.at(l).at(r) , dp.at(l).at(mid) + dp.at(mid).at(r));
            }
        }
    }

    for(int i = 0; i <= n; ++i){
        print(dp.at(i));
    }

    std::cout << dp.at(0).at(n) << std::endl;

    return 0;
}

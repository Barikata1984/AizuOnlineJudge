#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

#define INF 1000000007

void print(std::vector<int> vec){
    int n = vec.size();
    for(int i = 0; i < n; ++i){
        std::cout << std::setw(5) << std::setfill('0') << vec.at(i);
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

    std::vector<int> row(n), col(n);
    for(int i = 0; i < n; ++i){
        std::cin >> row.at(i) >> col.at(i);
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, INF));
    for(int l = n - 1; 0 <= l; --l){
        for(int r = 1; r <= n; ++r){
            if(l + 2 == r){
                dp.at(l).at(r) = row.at(l) * col.at(l) * col.at(r - 1);
            }else if(l + 2 < r){
                for(int m = l; m < r; ++m){
                    std::cout << m << std::endl;
                    dp.at(l).at(r) = std::min(dp.at(l).at(r), dp.at(l).at(m) + row.at(l) * col.at(m) * col.at(r) + dp.at(m + 1).at(r));
                }
            }
        }
    }

    for(int i = 0; i <= n; ++i){
        print(dp.at(i));
    }

    std::cout << dp.at(0).at(n) << std::endl;

    return 0;
}

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

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

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
    for(int l = n - 1; 0 <= l; --l){
        for(int r = 1; r <= n; ++r){
            if(l < r){
                if(l + 2 == r){
                    dp.at(l).at(r) = row.at(l) * col.at(l) * col.at(r - 1);
                }else{
                    dp.at(l).at(r) = std::min(dp.at(l).at(r - 1) + row.at(l) * row.at(r - 1) * col.at(r - 1), dp.at(l + 1).at(r) + row.at(l) * col.at(l) * col.at(r - 1));
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

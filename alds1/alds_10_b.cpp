#include <algorithm>
#include <iostream>
#include <vector>

#define INF 1000000007

int main(){
    int n;
    std::cin >> n;

    std::vector<int> row(n), col(n);
    for(int i = 0; i < n; ++i){
        std::cin >> row.at(i) >> col.at(i);
    }

    // consider a n * n dp matrix with INF as the minimum value is the interest of this exercise
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, INF));
    for(int l = n - 1; 0 <= l; --l){
        for(int r = 0; r < n; ++r){
            if(r == l){
                // set the dp value at self multiplication zero
                dp.at(l).at(r) = 0;
            }else if(r == l + 1){
                // multiply 2 matrixes
                dp.at(l).at(r) = row.at(l) * col.at(l) * col.at(r);
            }else if(r > l + 1){
                for(int m = l; m < r; ++m){
                    // examine the all dp values in every case where a separating point differs each other
                    dp.at(l).at(r) = std::min(dp.at(l).at(r), dp.at(l).at(m) + row.at(l) * col.at(m) * col.at(r)+ dp.at(m + 1).at(r));
                }
            }
        }
    }

    std::cout << dp.at(0).at(n - 1) << std::endl;

    return 0;
}

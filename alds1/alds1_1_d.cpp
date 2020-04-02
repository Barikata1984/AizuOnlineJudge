#include <algorithm>
#include <iostream>
#include <vector>

#define INF 1e18 + 7

int main(){
    int  n;
    std::cin >> n;

    std::vector<long long> r(n);
    for(int i = 0; i < n; ++i){
        std::cin >> r.at(i);
    }

    long long min = (long long)INF, diffMax = (long long)-INF;
    for(int i = 0; i < n; ++i){
        // The minmum element of "vec" is set as "min" in the former steps of each loop.
        // Therefore, comparing "r.at(i) - min" with "diffMax" garantees that the "diffMax" after the final comparison is the maximum variance amid every step.
        diffMax = std::max(diffMax, r.at(i) - min);
        min = std::min(min, r.at(i));
    }
    
    std::cout << diffMax << std::endl;

    return 0;
}

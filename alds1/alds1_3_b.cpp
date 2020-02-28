#include <algorithm>
#include <iostream>
#include <vector>

int main(){
    int n, q;
    std::cin >> n >> q;

    std::vector<std::string> names(n);
    std::vector<int> times(n);
    int val, buf, totalTime = 0;
    for(int i = 0; i < n; ++i){
        std::cin >> names.at(i) >> val;
        buf = std::min(q, val);
        totalTime += buf;
        times.at(i) = val - buf;        
        if(0 == times.at(i)){
            std::cout << names.at(i) << " " << totalTime << std::endl;
        }
    }

    while(1){
        std::vector<int>::iterator itr = std::find_if(times.begin(), times.end(), [] (int elem) {return 0 != elem;});

        if(times.end() == itr){
            break;
        }else{
            while(times.end() != itr){
                buf = std::min(q, *itr);
                *itr -= buf;
                totalTime += buf;
                if(0 == *itr){
                    int i = std::distance(times.begin(), itr);
                    std::cout << names.at(i) << " " << totalTime << std::endl;
                }
                ++itr;
                itr = std::find_if(itr, times.end(), [] (int elem) {return 0 != elem;});
            }
        }
    }

    return 0;
}

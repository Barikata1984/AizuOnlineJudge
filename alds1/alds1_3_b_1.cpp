#include <algorithm>
#include <iostream>
#include <vector>

int main(){
    int n, q;
    std::cin >> n >> q;

    std::vector<std::pair<std::string, int>> processes(n);
    for(auto itr = processes.begin(); processes.end() != itr; ++itr){
        std::cin >> itr->first >> itr->second;
    }

    int flg = 1, time = 0;
    while(flg){
        flg = 0;
        for(auto itr = processes.begin(); processes.end() != itr; ++itr){
            int& val = itr->second;
            if(0 < val){
                time += std::min(val, q);
                if(val <= q){
                    std::cout << itr->first << " " << time << std::endl;
                }
                val -= q;
                flg = 1;
            }
        }
    }

    return 0;
}
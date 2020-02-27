#include <algorithm>
#include <iostream>
#include <vector>

int main(){
    int n, q;
    std::cin >> n >> q;

    std::vector<std::pair<std::string, int>> processes;
    for(int i = 0; i < n; ++i){
        std::string str;
        int val;
        std::cin >> str >> val;
        processes.push_back(std::make_pair(str, val));
    }

    int flg = 1, time = 0;
    while(flg){
        flg = 0;
        for(auto itr = processes.begin(); processes.end() != itr; ++itr){
            auto& val = itr->second;
            if(0 < val && val <= q){
                time += val;
                std::cout << itr->first << " " << time << std::endl;
                val -= q;
                flg = 1;
            }else if(q < val){
                time += q;
                val -= q;
                flg = 1;
            }
        }
    }

    return 0;
}

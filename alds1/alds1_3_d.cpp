#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

void print(std::unordered_map<int, int> readUmp){
    int n = readUmp.size();
    auto itr = readUmp.begin();
    for(int i = 0; i < n; ++i){
        std::cout << itr->second;
        if(n - 1 != i){
            std::cout << " ";
        }else{
            std::cout << std::endl;
        }
        ++itr;
    }
}

int main(){
    std::string str;
    std::cin >> str;

    int n = str.size(), sum = 0;
    std::vector<int> downslope;
    std::unordered_map<int, int> areas;
    for(int i = 0; i < n; ++i){
        switch(str.at(i)){
            case 92: // DOWN
                downslope.push_back(i);
                break;

            case 47: // UP
                auto itr = std::find_if(areas.begin(), areas.end(), [downslope](auto elem){
                    return *(downslope.end() - 1) < elem.first; 
                });

                if(areas.end() == itr){
                    areas.insert(std::make_pair(i, sum));
                    areas.erase(itr);
                    sum = 0;
                }else{
                    sum += i - *(downslope.end() - 1);
                }
                break;
        }
    }

    std::cout << std::accumulate(areas.begin(), areas.end(), 0, [](int init, auto elem){
        return init + elem.second;
    }) << std::endl;
    std::cout << areas.size() << " ";
    print(areas);

    return 0;
}
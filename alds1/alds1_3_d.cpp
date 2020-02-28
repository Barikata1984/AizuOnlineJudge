#include <numeric>
#include <iostream>
#include <vector>

int main(){
    std::string str;
    std::cin >> str;

    int n = str.size(), depth = 0, subArea = 0;
    std::vector<int> areas;
    for(int i = 0; i < n; ++i){
        switch(str.at(i)){
            case 47: // up
                if(1 <= depth){
                    subArea += depth * 2 - 1;
                    if(1 == depth){
                        areas.push_back(subArea);
                        subArea = 0;
                    }
                    --depth;
                }
                break;
    
            case 92: // down
                subArea += depth * 2 + 1;
                ++depth;
                break;
   
            case 95: // flat
                subArea += depth * 2;
                break;
        }

        std::cout << subArea << std::endl;
    }

    std::cout << "------" << std::endl;

    std::cout << std::accumulate(areas.begin(), areas.end(), 0) / 2 << std::endl;
    std::cout << areas.size() << " ";

    for(auto itr = areas.begin(); areas.end() != itr; ++itr){
        std::cout << *itr / 2;
        if(areas.end() - 1 == itr){
            std::cout << " ";
        }else{
            std::cout << std::endl;
        }
    }

    return 0;
}

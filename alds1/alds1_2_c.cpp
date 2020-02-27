#include <iostream>
#include <utility>
#include <vector>
#include <map>

void print(std::vector<std::pair<int, char>>& readVec){
    int n = readVec.size();
    for(int i = 0; i < n; ++i){
        std::cout << readVec.at(i).second << readVec.at(i).first;
        if(n - 1 != i){
            std::cout << " ";
        }else{
            std::cout << std::endl;
        }
    }
}

bool isStable(std::multimap<int, char>& readMmp, std::vector<std::pair<int, char>>& readVec){
    int n = readMmp.size(), m = readVec.size();

    if(n != m){
        return false;
    }

    bool flg = true;
    auto mmpItr = readMmp.begin();
    auto vecItr = readVec.begin();
    while(flg && readMmp.end() != mmpItr && readVec.end() != vecItr){
        flg = mmpItr->first == vecItr->first && mmpItr->second == vecItr->second; 
        ++mmpItr;
        ++vecItr; 
    }

    if(flg){
        std::cout << "Stable" << std::endl;
    }else{
        std::cout << "Not stable" << std::endl;
    }

    return true;
}

int bubbleSort(std::vector<std::pair<int, char>>& readVec){
    int n = readVec.size(), count = 0;
    bool flg = true; // existence of the left-adjacent element less than an interest one.
    while(flg){
        flg = false;
        for(int j = n - 1; 0 < j; --j){
            if(readVec.at(j).first < readVec.at(j - 1).first){
                std::swap(readVec.at(j), readVec.at(j - 1));
                flg = true;
                ++count;
            }
        }
    }

    print(readVec);

    return count;
}

int selectionSort(std::vector<std::pair<int, char>>& readVec){
    int n = readVec.size(), count = 0;
    for(int i = 0; i < n; ++i){
        int minJ = i;
        for(int j = i; j < n; ++j){
            if(readVec.at(j).first < readVec.at(minJ).first){
                minJ = j;
            }
        }
        
        if(i != minJ){
            std::swap(readVec.at(i), readVec.at(minJ));
            ++count;
        }
    }

    print(readVec);

    return count;
}

int main(){
    int n;
    std::cin >> n;

    std::vector<std::pair<int, char>> a(n);
    std::multimap<int, char> mmp;
    for(int i = 0; i < n; ++i){
        std::string str;
        std::cin >> str;
        a.at(i) = std::make_pair(str.at(1) - 48, str.at(0));
        mmp.insert(std::make_pair(str.at(1) - 48, str.at(0)));
    }

    auto bubbled = a, selected = a;

    bubbleSort(bubbled);
    isStable(mmp, bubbled);

    selectionSort(selected);
    isStable(mmp, selected);

    return 0;
}
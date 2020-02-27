#include <iostream>
#include <cstdlib>
#include <vector>

void print(std::vector<std::string>& readVec){
    int n = readVec.size();
    for(int i = 0; i < n; ++i){
        std::cout << readVec.at(i);
        if(n - 1 != i){
            std::cout << " ";
        }else{
            std::cout << std::endl;
        }
    }
}

int isOperator(std::string readStr){
    if(1 != readStr.size()){
        return 0;
    }

    switch(readStr.at(0)){
        case 42: // *
        case 43: // +
        case 45: // -
            return readStr.at(0);
            break;
        default:
            return 0;
            break;
    }
}

void invertedPoland(std::vector<std::string>& readVec, int i){
    int j = i + 1, k = j + 1, flg = 0;
    long long val, lOp = std::atoi(readVec.at(i).c_str()), rOp = std::atoi(readVec.at(j).c_str());
    switch((isOperator(readVec.at(i)) + 1) * (isOperator(readVec.at(j)) + 1) * (isOperator(readVec.at(k)))){
        case 42:
            ++flg;
            val = lOp * rOp;
            break;
        case 43:
            ++flg;
            val = lOp + rOp;
            break;
        case 45:
            ++flg;
            val = lOp - rOp;
            break;
    }

    if(flg){
        readVec.at(i) = std::to_string(val);
        auto itr = readVec.begin();
        readVec.erase(itr + j, itr + k + 1);
    }
}


int main(){
    std::vector<std::string> vec;
    std::string str;
    while(std::cin >> str){
        vec.push_back(str);
    }

    int n = vec.size();
    while(1 != vec.size()){
        for(int i = n - 3; 0 <= i; --i){
            invertedPoland(vec, i);
        }
    
        n = vec.size();
    }

    std::cout << vec.at(0) << std::endl;

    return 0;
}
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
        case 47: // /
            return readStr.at(0);
            break;
        default:
            return 0;
            break;
    }
}

void getLR(std::vector<std::string>& readVec, long long& left, long long& right){
    left = std::atoll((readVec.end() - 2)->c_str());
    right = std::atoll((readVec.end() - 1)->c_str());
}

int main(){
    std::string str;
    std::vector<std::string> stack;
    while(std::cin >> str){
        long long left, right, val, flg = 0;
        switch(isOperator(str)){
            case 42:
                getLR(stack, left, right);
                val = left * right;
                ++flg;
                break;
            case 43:
                getLR(stack, left, right);
                val = left + right;
                ++flg;
                break;
            case 45:
                getLR(stack, left, right);
                val = left - right;
                ++flg;
                break;
            default:
                stack.push_back(str);
        }

        if(flg){
            auto itr = stack.end();
            *(itr - 2) = std::to_string(val);
            stack.erase(itr - 1, itr);
        }
    }

    std::cout << *stack.begin() << std::endl;

    return 0;
}
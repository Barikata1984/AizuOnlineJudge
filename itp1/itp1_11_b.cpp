#include <iostream>
#include <vector>

int main(){
    std::vector<int> previous(6);
    std::vector<int> current(6);
    for(int i = 0; i < 6; ++i){
        std::cin >> dice.at(i);
    }

    char key;
    while(std::cin >> key){
        switch(key){
            case 'N':
                std::swap(dice.at(0), dice.at(1));
                std::swap(dice.at(1), dice.at(5));
                std::swap(dice.at(5), dice.at(4));
                break;
            case 'E':
                std::swap(dice.at(0), dice.at(3));
                std::swap(dice.at(3), dice.at(5));
                std::swap(dice.at(5), dice.at(2));
                break;
            case 'W':
                std::swap(dice.at(0), dice.at(2));
                std::swap(dice.at(2), dice.at(5));
                std::swap(dice.at(5), dice.at(3));
                break;
            case 'S':
                std::swap(dice.at(0), dice.at(4));
                std::swap(dice.at(4), dice.at(5));
                std::swap(dice.at(5), dice.at(1));
                break;
        }
    }

    std::cout << dice.at(0) << std::endl;

    return 0;
}
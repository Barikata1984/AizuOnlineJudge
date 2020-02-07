#include <iostream>
#include <vector>

enum{
    TOP, FRONT, RIGHT, LEFT, REAR, BOTTOM
};

class Dice{
private:
    std::vector<int> faces;

public:
    Dice(){
        for(int i = 0; i < 6; ++i){
            faces.push_back(i + 1);
        }
    }

    Dice(std::vector<int> readVec){
        int sz = readVec.size();
        for(int i = 0; i < sz; ++i){
            faces.push_back(readVec.at(i));
        }
    }

    void roll(int readVal){
        std::vector<int> index{0, 2, 5, 3};
        switch(readVal){
            case 78: // 'N'
                index.at(1) = 1; index.at(3) = 4; 
                break;
            case 87: // 'W'
                index.at(1) = 2; index.at(3) = 3; 
                break;
            case 69: // 'E'
                index.at(1) = 3; index.at(3) = 2; 
                break;
            case 83: // 'S'
                index.at(1) = 4; index.at(3) = 1; 
                break;
            case 82: // 'R' (rotate the dice clockwisely)
                index.at(0) = 1; index.at(2) = 4; 
                break;
        }

        for(int i = 0; i < 3; ++i){
            std::swap(faces.at(index.at(i)), faces.at(index.at(i + 1)));
        }
    }

    int number(int i){
        return faces.at(i);
    }
};

int main(){
    std::vector<int> vec1(6);
    for(int i = 0; i < 6; ++i){
        std::cin >> vec1.at(i);
    }

    std::vector<int> vec2(6);
    for(int i = 0; i < 6; ++i){
        std::cin >> vec2.at(i);
    }

    Dice dice1(vec1), dice2(vec2);

    if(dice1.number(TOP) == dice2.number(LEFT)){
        dice2.roll('E');
    }else if(dice1.number(TOP) == dice2.number(RIGHT)){
        dice2.roll('W');
    }

    bool flg1 = false;
    int i = 0;
    while(!flg1 && i < 4){
        dice2.roll('N');
        flg1 = dice1.number(TOP) == dice2.number(TOP);
        ++i;
    }

    bool flg2 = false;
    int j = 0;
    while(!flg2 && j < 4){
        dice2.roll('R');
        flg2 = dice1.number(FRONT) == dice2.number(FRONT);
        ++j;
    }

    std::string ans = "No";
    if(flg1 && flg2 && dice1.number(RIGHT) == dice2.number(RIGHT)){
        ans = "Yes";
    }

    std::cout << ans << std::endl;

    return 0;
}
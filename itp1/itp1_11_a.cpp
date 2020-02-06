#include <iostream>
#include <vector>

class Dice{
private:
    std::vector<int> surfaces;

public:
    Dice(std::vector<int> readVec){
        int sz = readVec.size();
        for(int i = 0; i < sz; ++i){
            surfaces.push_back(readVec.at(i));
        }
    }

    void roll(int readVal){
        int i, j;
        switch(readVal){
            case 78:
                i = 1; j = 4;
                break;
            case 87:
                i = 2; j = 3;
                break;
            case 69:
                i = 3; j = 2;
                break;
            case 83:
                i = 4; j = 1;
                break;
        }

        int buf = surfaces.at(0);
        surfaces.at(0) = surfaces.at(i);
        surfaces.at(i) = surfaces.at(5);
        surfaces.at(5) = surfaces.at(j);
        surfaces.at(j) = buf;
    }

    void top(){
        std::cout << surfaces.at(0) << std::endl;
    }
};

int main(){
    std::vector<int> vec(6);
    for(int i = 0; i < 6; ++i){
        std::cin >> vec.at(i);
    }

    Dice dice(vec);

    std::string cmd;
    std::cin >> cmd;

    int sz = cmd.size();
    for(int i = 0; i < sz; ++i){
        dice.roll(cmd.at(i));
    }

    dice.top();

    return 0;
}

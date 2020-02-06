#include <iostream>
#include <vector>

enum week {
  TOP, FRONT, RIGHT, LEFT, REAR, BOTTOM;
}

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

    void surfaceNumber(int readVal){
        std::cout << surfaces.at(readVal) << std::endl;
    }
};

int main(){
    std::vector<int> vec(6);
    for(int i = 0; i < 6; ++i){
        std::cin >> vec.at(i);
    }

    Dice dice(vec);

    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        int a, b;
        std::cin >> a >> b;
        if(a == dice.left){
            dice.roll('E');
        }
        if(a == dice.right){
            dice.roll('W');
        }
        while(a != dice.top){
            dice.roll('N');
        }
        dice.roll(cmd.at(i));
    }

    dice.surfaceNumber(top);

    return 0;
}

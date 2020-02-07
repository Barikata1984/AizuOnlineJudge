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
        if(a == dice.number(LEFT)){
            dice.roll('E');
        }
        if(a == dice.number(RIGHT)){
            dice.roll('W');
        }
        while(a != dice.number(TOP)){
            dice.roll('N');
        }
        while(b != dice.number(FRONT)){
            dice.roll('R');
        }

        std::cout << dice.number(RIGHT) << std::endl;
    }

    return 0;
}

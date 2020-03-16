#include <iostream>
#include <vector>

std::vector<int> dx{1, 1, 0, -1, -1, -1, 0, 1};
std::vector<int> dy{0, 1, 1, 1, 0, -1, -1, -1};

void dfs(std::vector<std::vector<bool>> &seen, std::vector<std::vector<int>> &map, int x, int y){
//    std::cout << x << ", " << y << std::endl;
    seen.at(y).at(x) = true;
    for(int i = 0; i < 8; ++i){
        int nextX = x + dx.at(i), nextY = y + dy.at(i);
        if(!seen.at(nextY).at(nextX) && 1 == map.at(nextY).at(nextX)){
            dfs(seen, map, nextX, nextY);
        }
    }
}

int main(){
    int w, h;
    while(std::cin >> w >> h){
        if(0 == w && 0 == h){
            break;
        }

        std::vector<std::vector<int>> map(h + 2, std::vector<int>(w + 2, 0));
        for(int i = 1; i <= h; ++i){
            for(int j = 1; j <= w; ++j){
                std::cin >> map.at(i).at(j); 
            }
        }

        std::vector<std::vector<bool>> seen(h + 2, std::vector<bool>(w + 2, false));
        int count = 0;
        for(int i = 1; i <= h; ++i){
            for(int j = 1; j <= w; ++j){
                if(!seen.at(i).at(j) && 1 == map.at(i).at(j)){
                    dfs(seen, map, j, i);
                    ++count;
                } 
            }
        }
    
        std::cout << count << std::endl;
    }

    return 0;
}
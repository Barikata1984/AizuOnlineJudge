#include <iostream>
#include <vector>

std::vector<int> dx{1, 1, 0, -1, -1, -1, 0, 1}, dy{0, 1, 1, 1, 0, -1, -1, -1};
void dfs(std::vector<std::vector<bool>> &seen, std::vector<std::vector<int>> &map, int y, int x){
    seen.at(y).at(x) = true;
    for(int i = 0; i < 8; ++i){
        int nextX = x + dx.at(i), nextY = y + dy.at(i);
        if(0 == map.at(nextY).at(nextX) || seen.at(nextY).at(nextX)){
            continue;
        }

        dfs(seen, map, nextY, nextX);
    }
}


int main(){
    int w, h;
    while(std::cin >> w >> h){
        if(0 == w && 0 == h){
            return 0;
        }

        std::vector<std::vector<int>> map(h + 2, std::vector<int>(w + 2, 0));
        for(int j = 1; j <= h; ++j){
            for(int i = 1; i <= w; ++i){
                std::cin >> map.at(j).at(i);
            }
        }

        int count = 0;
        std::vector<std::vector<bool>> seen(h + 2, std::vector<bool>(w + 2, false));
        for(int j = 1; j <= h; ++j){
            for(int i = 1; i <= w; ++i){
                if(0 == map.at(j).at(i) || seen.at(j).at(i)){
                    continue;
                }

                ++count;
                dfs(seen, map, j, i);
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}

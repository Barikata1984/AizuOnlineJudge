#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

#define INF 1000000007

using Graph = std::vector<std::vector<std::pair<int, int>>>;

void print(std::vector<long long> &vec){
    int n = vec.size();
    for(int i = 0; i < n; ++i){
        if(INF == vec.at(i)){
            std::cout << "INF" << std::endl;
        }else{
            std::cout << vec.at(i) << std::endl;
        }
    }
}

// depth first search
void dfs(std::vector<long long> &w, const Graph &g, const int r){
    for(auto elem : g.at(r)){
        int first = elem.first, second = elem.second;
        w.at(first) = std::min(w.at(first), w.at(r) + second);
        dfs(w, g, first);

//        auto itr = std::find(g.at(r).begin(), g.at(r).end(), elem);
//        if(g.at(r).end() != itr){
//            g.at(r).erase(std::find(g.at(r).begin(), g.at(r).end(), elem));
//        }
    }
}

int main(){
    int v, e, r;
    std::cin >> v >> e >> r;
    
    if(1 == v){
        std::cout << 0 << std::endl;
        return 0;
    }

    Graph g(v);
    int s, t, d;
    while(std::cin >> s >> t >> d){
        g.at(s).push_back(std::make_pair(t, d));
//        g.at(t).push_back(std::make_pair(s, d)); // a directed graph is used in this exercise
    }

    std::vector<long long> w(v, INF);
    w.at(r) = 0;
    dfs(w, g, r);
    print(w);
    return 0;
}

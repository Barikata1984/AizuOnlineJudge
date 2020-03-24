#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using graph = std::vector<std::unordered_map<long long, long long>>;

#define INF (long long)(1e18 + 7)

void print(std::vector<long long> vec){
    int n = vec.size();
    for(int i = 0; i < n; ++i){
        if((long long)5e10 < vec.at(i)){
            std::cout << "INF" << std::endl;
        }else{
            std::cout << vec.at(i) << std::endl;
        } 
    }
}

int main(){
    long long v, e, r;
    std::cin >> v >> e >> r;

    graph g(v);
    long long s, t, w;
    while(std::cin >> s >> t >> w){
        g.at(s).insert(std::make_pair(w, t)); // weight and to
    }

    auto compare = [](std::pair<long long, long long> &lhs, std::pair<long long, long long> &rhs){
        return lhs.first < rhs.first;
    }; 
   
    std::priority_queue<
        long long,
        std::vector<std::pair<long long, long long>>,
        decltype(compare) 
    > pq(compare); // weight and to
    pq.push(std::make_pair(0, r));

    std::vector<long long> dist(v, INF);
    dist.at(r) = 0;

    while(!pq.empty()){
        auto from = pq.top();
        pq.pop();
        
        if(dist.at(from.second) < from.first){
            continue;
        }

        for(auto to : g.at(from.second)){
            auto len = to.first + dist.at(from.second);
            if(len < dist.at(to.second)){
                dist.at(to.second) = len;
                pq.push(std::make_pair(dist.at(to.second), to.second));
            }
        }
    }

    print(dist);

    return 0;
}

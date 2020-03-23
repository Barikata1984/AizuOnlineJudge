#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using Graph = std::vector<std::unordered_map<long long, long long>>;

#define INF 1000000000000000007

int main(){
    long long v, e, r;
    std::cin >> v >> e >> r;

    Graph g(v);
    long long s, t, d;
    while(std::cin >> s >> t >> d){
        g.at(s).insert(std::make_pair(t, d));
    }

    std::vector<long long> dist(v, INF);
    dist.at(0) = 0;

    std::map<long long, long long> pq;
    pq.insert(std::make_pair(0, r));
    auto itr = pq.begin();
    while(std::end(pq) != itr){
        std::cout << g.at(itr->second).size() << std::endl;
        for(auto elem : g.at(itr->second)){
            auto len = elem.second + dist.at(itr->first);
            if(len < dist.at(elem.first)){
                dist.at(elem.first) = len;
                pq.insert(std::make_pair(elem.second, elem.first));
            }else{
                auto deleteItr = itr;
                ++itr;
                pq.erase(deleteItr); // caution
                break;
            }
            ++itr;
        }
    }

    std::cout << dist.at(v - 1) << std::endl;

    return 0;
}

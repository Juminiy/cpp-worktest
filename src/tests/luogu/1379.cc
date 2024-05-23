#include <iostream>
#include <cstdio>
#include <queue>

class Node {
public:
    char sta[3][3] = {};
    int v;
    explicit Node(char _sta[3][3], int _v = 0)
        : sta(_sta), v(_v) { }
    
    int diff(const Node & _n) const {
        int dF = 0;
        for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            dF += sta[i][j] != _n.sta[i][j];
        
        return dF;
    }

    friend std::istream& operator >> (std::istream& _is, Node & _n){
        for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            _is >> sta[i][j];
        return _is;
    }
};

class NCmp {
public:
    Node ed;
    explicit NCmp(const Node & _n) 
        : ed(_n) { }
    bool operator() (const Node & _n1, const Node & _n2) 
        const noexcept {
        int cost1 = _n1.diff(ed);
        int cost2 = _n2.diff(ed);
        if(cost1 == cost2)
            return _n1.v > _n2.v;
        return cost1 > cost2;
    }
};

class eNum {
public: 
    Node st, ed;
    int ans = 0;

    using pq = std::priority_queue<Node, std::vector<Node>, NCmp>;

    /* 
        2 8 3    1 2 3
        1 0 4 -> 8 0 4    
        7 6 5    7 6 5
    */

    void bfs(){

    }
};


int main()
{
    eNum eN;
    for(int i=0;i<9;++i)
        eN.chs[i/3][i%3] = getchar();
    return 0;
}
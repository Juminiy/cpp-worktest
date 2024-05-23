#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_self_algo_.hpp"

#include <iostream>
#include <queue>
#include <fstream>

__DEF_NS__(Alan::SelfAlgo::Inst::PBFS)

class Node {
public:
    int x,y,pass,val;
    explicit Node(int _x = 0, int _y = 0, int _v = 0) 
        : x(_x), y(_y), pass(0), val(_v) { }

    friend std::ostream& operator << (std::ostream& _os, const Node & _n){
        _os << "[" 
            << _n.x << "," 
            << _n.y << ","
            << _n.pass << ","
            << _n.val
            << "]";
        return _os;
    }

    bool operator < (const Node & _rhs) 
        const noexcept {
            if(this->pass == _rhs.pass)
                return this->val < _rhs.val;
            else if (this->pass)
                return true;
            else 
                return false;
        }

    Node operator + (int _a[2])
    {
        auto newNode = Node(x+_a[0], y+_a[1], val);
        newNode.pass = this->pass;
        return newNode;
    }

    int manH(const Node & _rhs)
    const 
    {
        int dx = (this->x - _rhs.x);
        int dy = (this->y - _rhs.y);
        return std::abs(dx) + std::abs(dy);
    }

    int olaH(const Node & _rhs)
    const 
    {
        int dx = (this->x - _rhs.x);
        int dy = (this->y - _rhs.y);
        return static_cast<int>(::sqrt(dx*dx + dy*dy));
    }

};

typedef int (*fnH)(const Node &, const Node & );

int manF(const Node & _lhs, const Node & _rhs)
{
    return _lhs.val + _lhs.manH(_rhs);
}

int olaF(const Node & _lhs, const Node & _rhs)
{
    return _lhs.val + _lhs.olaH(_rhs);
}

    struct CompFnH {
        Node ed;
        fnH h;
        explicit CompFnH(const Node & _ed, fnH _h) : ed(_ed), h(_h) { }
        bool operator () (const Node &_lhs, const Node &_rhs)
        {
            int res1 = h(_lhs, ed);
            int res2 = h(_rhs, ed);
            if (res1 == res2)
                return _rhs < _lhs;
            else 
                return res1 > res2;
        }
    };

class Sol {
public:
    explicit Sol(int pMode = 4) : mode(pMode) {
        
    }
    int n,m;
    std::string gra[250][250] = {};
    bool vis[250][250] = {};
    Node st, ed;
    std::priority_queue<int, std::vector<int>, std::greater<int> > anss;

    int mode;
    int pxy4[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    int pxy8[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

    inline bool valid1(int x, int y)
    {
        return I32_IN_RANGE(x, 0, n-1) && 
                I32_IN_RANGE(y, 0, m-1) && 
                gra[x][y] != "B" && gra[x][y] != "S";
    }

    inline bool valid2(int x, int y)
    {
        return !vis[x][y];
    }

    using fhPQ = std::priority_queue<Node, std::vector<Node>, CompFnH>;

    void debugfhPQ(fhPQ q){
        while(!q.empty())
        {
            PRINT(q.top()), PRINT(",");
            q.pop();
        }
        PRINTLN("");
    }

    void bfs()
    {
        auto comp = CompFnH(ed, olaF);
        auto fhpq = fhPQ(comp);
        fhpq.push(st);

        while(!fhpq.empty()){
            auto ele = fhpq.top(); fhpq.pop();
            vis[ele.x][ele.y] = 1;
            for(int pro=0;pro<mode;++pro)
            {
                auto ppt = ele+ ((mode == 8) ? pxy8[pro] : pxy4[pro]);
                if(valid1(ppt.x, ppt.y)){
                    if(gra[ppt.x][ppt.y] == "E" && ppt.pass)
                        {
                            anss.push(ppt.val); return;
                        }
                    else if(gra[ppt.x][ppt.y] == "C") 
                        ppt.pass = 1;
                    else 
                        ppt.val += std::strtol(gra[ppt.x][ppt.y].data(), nullptr, 10);
                    if(valid2(ppt.x, ppt.y))
                    {
                        fhpq.push(ppt);
                    }
                }
            }
            // debugfhPQ(fhpq);
        }
    }

    friend std::istream& operator >> (std::istream& _is, Sol & sol) {
        _is >> sol.n >> sol.m;
        for(int i=0;i<sol.n;++i)
        for(int j=0;j<sol.m;++j){
            _is >> sol.gra[i][j];
            if(sol.gra[i][j]=="S")
                sol.st = Node(i,j,0);
            else if(sol.gra[i][j]=="E")
                sol.ed = Node(i,j,0);
        }
        return _is;
    }

    friend std::ostream& operator << (std::ostream& _os, const Sol & sol) {
        if(sol.anss.empty())
            _os << -1 << '\n';
        else 
            _os << sol.anss.top() << '\n';
        return _os;
    }

};

void TestPBFS()
{
    Sol sol(8);
    // auto ifs = std::ifstream("test/probls/pbfs_input.txt");
    // ifs >> sol;
    std::cin >> sol;
    sol.bfs();
    std::cout << sol;
}

__END_NS__
#include <cstdio>
#include <iostream>
#include <string>

/*
          root
        /  |  \
       a   b   c 
      / \     
     c   d
     |
     d          
      
*/
struct trie{
    #define NOT_FOUND 0
    #define ONLY_ONE 1
    #define MORE_ONE 2
    #define HAS_VISIT 3
    int count;
    bool vis;
    struct trie* chi[26];

    trie(int cnt = 0)
        : count(cnt), vis(false), chi({nullptr}) { }
};

void add(trie* root, const std::string & str)
{
    size_t len = str.size();
    if(!len) return;
    if(root->chi[str[0]-'a'] == nullptr)
    {
        trie* newNode = new trie();
        root->chi[str[0]-'a'] = newNode;
    }

    if(len == 1)
        root->chi[str[0]-'a']->count ++;
    
    add(root->chi[str[0]-'a'], str.substr(1, len-1));
}

void del(trie* root, const std::string & str)
{

}

// 
int query(trie* root, const std::string & str)
{
    size_t len = str.size();
    if(root == nullptr || !len)
        return NOT_FOUND;
    else if(len == 1)
    {
        root = root->chi[str[0]-'a'];
        if (root == nullptr)
            return NOT_FOUND;
        if(root->count)
        {
            if(root->vis)
                return HAS_VISIT;
            else {
                root->vis = true;
                return ONLY_ONE;
            }
        } 
    }

    return query(root->chi[str[0]-'a'], str.substr(1, len-1));
}

int main()
{
    int n, t;
    std::string s;
    trie* tr = new trie();

    std::cin >> n;
    while(n--){
        std::cin >> s;
        add(tr, s);
    }

    std::cin >> t;
    while(t--){
        std::cin >> s;
        int stat = query(tr, s);
        switch(stat)    
        {
        case NOT_FOUND:
            std::cout << "WRONG\n";
        break;
        case ONLY_ONE:
            std::cout << "OK\n";
        break;
        case HAS_VISIT:
            std::cout << "REPEAT\n";
        break;
        }
    }
    return 0;
}
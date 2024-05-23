#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_self_algo_.hpp"

#include <vector>
#include <string>
#include <algorithm>

__DEF_NS__(Alan::SelfAlgo::Inst)

size_t __edit_distance_
(const std::string & __dest, const std::string & __src)
{
    using _sz_vec = std::vector<size_t>;
    auto __dl = __dest.size(), __sl = __src.size();
    auto __dis_ = 
        std::vector<_sz_vec>(__dl+1, _sz_vec(__sl+1, 0));
    for(size_t i = 0; i <= __dl; ++i)
    {
        for(size_t j = 0; j <= __sl; ++j)
        {
        if(i == 0 && j == 0) 
            __dis_[i][j] = 0;
        else if (i == 0 && j != 0)
            __dis_[i][j] = __dis_[i][j-1] + 1;
        else if (i != 0 && j == 0)
            __dis_[i][j] = __dis_[i-1][j] + 1;
        else
        {
            auto __replace_of = (__dest[i-1] == __src[j-1]) ? 
                __dis_[i-1][j-1] : __dis_[i-1][j-1] + 1;
            __dis_[i][j] = std::min({
                __dis_[i-1][j] + 1, 
                __dis_[i][j-1] + 1, 
                __replace_of
            });
        }
        }
    }
    return __dis_[__dl][__sl];
}

size_t __edit_distance_optv2
(const std::string & __dest, const std::string & __src)
{
    size_t dl = __dest.size(), sl = __src.size();
    size_t dp[dl+1][sl+1];
    for(size_t j = 0; j <= sl; ++j)
        dp[0][j] = j;
    for(size_t i = 0; i <= dl; ++i)
        dp[i][0] = i;
    for(size_t i = 1; i <= dl; ++i)
    {
    for(size_t j = 1; j <= sl; ++j)
    {
        auto __replace_of = (__dest[i-1] == __src[j-1]) ? 
                dp[i-1][j-1] : dp[i-1][j-1] + 1;
        dp[i][j] = std::min(
            __replace_of,
            std::min(
            dp[i-1][j] + 1, 
            dp[i][j-1] + 1
            )
        );
    }
    }
    
    return dp[dl][sl];
}

// insert -> i
// delete -> d
// replace -> r
std::vector<std::string> __get_edits_
(const std::string & __dest, const std::string & __src)
{
    return {};
}

// horse | ros
size_t __edit_distance_bf
(const std::string & s, const std::string & t)
{
    auto szs = s.size(), szt = t.size();
    if(szs == 0)
        return szt;
    else if(szt == 0)
        return szs;
    
    auto _ins = __edit_distance_bf(s, t.substr(1, szt-1));
    auto _del = __edit_distance_bf(s.substr(1, szs-1), t);
    auto _rep = __edit_distance_bf(s.substr(1, szs-1), t.substr(1, szt-1));

    if(s[0] == t[0])
        return std::min({_del+1, _ins+1, _rep});
    else 
        return std::min({_del+1, _ins+1, _rep+1});
    
}

__END_NS__

__USE_NS__(Alan::SelfAlgo::Inst);
__DEF_NS__(Alan::SelfAlgo::Inst::Test)

void TestLC72()
{
    PRINTLN("brute force");
    PRINTLN(__edit_distance_bf("horse", "ros"));              // 3
    PRINTLN(__edit_distance_bf("intention", "execution"));    // 5
    // too long time!!!
    // PRINTLN(__edit_distance_bf("zoogeologist", "zoologicoarchaeologist")); // 10

    PRINTLN("dynamic programming");
    PRINTLN(__edit_distance_("horse", "ros"));              // 3
    PRINTLN(__edit_distance_("intention", "execution"));    // 5
    PRINTLN(__edit_distance_("zoogeologist", "zoologicoarchaeologist")); // 10

    PRINTLN("dynamic programming optimize");
    PRINTLN(__edit_distance_optv2("horse", "ros"));              // 3
    PRINTLN(__edit_distance_optv2("intention", "execution"));    // 5
    PRINTLN(__edit_distance_optv2("zoogeologist", "zoologicoarchaeologist")); // 10
}

__END_NS__
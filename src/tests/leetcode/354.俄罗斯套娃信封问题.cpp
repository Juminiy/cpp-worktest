/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    

int maxEnvelopes(vector<vector<int>>& envelopes) {
    auto _comp_less = 
        [] (const vector<int> & _e1, const vector<int> & _e2)
            -> bool 
        {   
            if(_e1[0] == _e2[0])
                return _e1[1] > _e2[1];
            return _e1[0] < _e2[0];
        };
    auto _ev_less = 
        [] (const vector<int> & _e1, const vector<int> & _e2)
            -> bool 
        {   
            return _e1[1] < _e2[1];
        };
    auto _sstk_m_fn = 
        [&envelopes, &_ev_less] (auto && _comp_fn) -> int 
    {
    std::sort(envelopes.begin(), envelopes.end(), std::forward<decltype(_comp_fn)>(_comp_fn));
    #ifdef DEBUG_MODE
        Alan::ConsoleBeautyOutputEmbedded2(envelopes);
    #endif
    auto _lstk = std::vector<std::vector<int > >();
    for(size_t _i = 0; _i < envelopes.size(); ++ _i)
    {   
        if (_lstk.empty() || _ev_less(_lstk.back(), envelopes[_i]))
        {    
            _lstk.push_back(envelopes[_i]);
            continue;
        }
        auto _liter = 
            std::lower_bound(_lstk.begin(), _lstk.end(), envelopes[_i], _ev_less);
        *_liter = envelopes[_i];
        #ifdef DEBUG_MODE
            Alan::ConsoleBeautyOutputEmbedded2(_lstk); 
        #endif
    }

    return _lstk.size();
    };
    
    return _sstk_m_fn(_comp_less);
}




};
// @lc code=end


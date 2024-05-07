/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> opd; // -200 ~ 200
    // std::stack<char> opt; // + - * /
    // int eval = 0;
    auto optOpd = [](int lexpr, int rexpr, char opt) -> int {
        switch (opt)
        {
        case '+':
            return lexpr+rexpr;
        case '-':
            return lexpr-rexpr;
        case '*':
            return lexpr*rexpr;
        case '/':
            return lexpr/rexpr;        
        default:
            return 0;
        }
    };
    for(auto str : tokens)
    {
        if(str == "+" || 
            str == "-" ||
            str == "*" || 
            str == "/")
        {
            auto rexpr = opd.top(); opd.pop();
            auto lexpr = opd.top(); opd.pop();
            opd.push(optOpd(lexpr, rexpr, str[0]));
        }
        else 
        {
            opd.push(std::strtol(str.c_str(), nullptr, 10));
        }
    }
    // while(!opt.empty())
    // {

    // }

    return opd.top();
}
};
// @lc code=end


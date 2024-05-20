/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    // x -> |x|
    // -x -> |x|+1

    // 3 100000
    // 
    int divide(int dividend, int divisor) {
        if(!dividend || !divisor) return 0;
        bool s1 = dividend > 0, s2 = divisor > 0;
        int udd = s1 ? dividend : ~dividend+1;
        int udr = s2 ? divisor : ~divisor+1;
        if(udd < udr) return 0;
        
        int cnt = 0, cur = 0;
        int bOf = 0, pOf = udr;
        while(pOf < udd)
        {
            bOf ++;     // 1 2  ... 16
            pOf <<= 1;  // 6 12 ... 196608
        } 
        int lOf = pOf;
        while(lOf > udd)
        {
            bOf --;    // 15
            lOf >>= 1; // 98304
        }
        while(lOf < udd)
        {
            cnt++;
            lOf += udr;
        }
        if(lOf > udd)
            cnt--;
        
        cnt += (1<<bOf);

        return (s1^s2) ? ~cnt+1 : cnt;
    }
};
// @lc code=end


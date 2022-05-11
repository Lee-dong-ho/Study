#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 10e5 * 10e9 * 4;
    long long start= 0;
    long long end = 10e5 * 10e9 * 4;
    long long mid = 0;
    while(start<=end)
    {
        mid = (start + end) / 2;
        long long carry_g = 0;
        long long carry_s = 0;
        long long carry_gs = 0;

        for (int i = 0; i < g.size(); i++)
        {
            long long now_g = g[i];
            long long now_s = s[i];
            long long now_w = w[i];
            long long now_t = t[i];
            long long move_cnt = (mid % (now_t*2) >= now_t) ? (mid/(now_t*2) + 1) : mid/(now_t*2);

            carry_g += (now_g > move_cnt*now_w) ? move_cnt*now_w : now_g;
            carry_s += (now_s > move_cnt*now_w) ? move_cnt*now_w : now_s;
            carry_gs += ((now_g + now_s) > move_cnt*now_w) ? move_cnt*now_w : (now_g + now_s);
        }

        if (carry_g >= a && carry_s >= b && carry_gs >= a + b)
        {
            end = mid - 1;
            answer = min(answer, mid);
        }
        else
        {
            start = mid + 1;
        }
    }
    
    return answer;
}

int main(void)
{
    int a, b;
    vector <int> g,s,w,t;
    a = 90;
    b = 500;
    g = {70,70,0};
    s = {0,0,500};
    w = {100,100,2};
    t = {4,8,1};
    cout << solution(a,b,g,s,w,t) << endl;
    
    return 0;
}
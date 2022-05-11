#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> visited;
vector<pair<int, int>> dfs(int c, int x, int y, vector<pair<int, int>> &t)
{
    visited[x][y] = c;
    t.push_back(make_pair(x, y));
    if(x < visited.size()-1) if(visited[x+1][y] != c) dfs(c, x+1, y, t);
    if(x > 0) if(visited[x-1][y] != c) dfs(c, x-1, y, t);
    if(y < visited.size()-1) if(visited[x][y+1] != c) dfs(c, x, y+1, t);
    if(y > 0) if(visited[x][y-1] != c) dfs(c, x, y-1, t);

    return t;
}

void FindFigure(int c, vector<vector<int>> v, vector<vector<pair<int, int>>> &f)
{
    vector<pair<int, int>> temp;
    visited = v;
    for(int i=0; i<visited.size(); i++)
    {
        for(int j=0; j<visited[0].size(); j++)
        {
            temp.clear();
            if (visited[i][j] != c) f.push_back(dfs(c, i, j, temp));
        }
    }
}

void ToDefaultAxis(vector<pair<int, int>> &p)
{    
    int x = 50;
    int y = 50;
    for(int j=0; j<p.size(); j++)
    {
        x = min(x, p[j].first);
        y = min(y, p[j].second);
    }
    for(int j=0; j<p.size(); j++)
    {
        p[j].first -= x;
        p[j].second -= y;
    }
    sort(p.begin(), p.end());
}

vector<pair<int, int>> Rotation(vector<pair<int, int>> p, long long int angle)
{
    int count = (int)(angle/90);
    int temp;
    while(count-- > 0)
    {
        for (int i=0; i < p.size(); i++)
        {
            temp = -p[i].first;
            p[i].first = p[i].second;
            p[i].second = temp;
        }
    }
    ToDefaultAxis(p);
    return p;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<vector<pair<int, int>>> b;
    vector<vector<pair<int, int>>> f;

    FindFigure(1, game_board, b);
    FindFigure(0, table, f);
    
    for(int i=0; i<b.size(); i++)
    {
        ToDefaultAxis(b[i]);
    }
    for(int i=0; i<f.size(); i++)
    {
         ToDefaultAxis(f[i]);
    }
    for (int i=0; i<f.size(); i++)
    {
        for (int j=0; j<b.size(); j++)
        {
            if (f[i].size() == b[j].size())
            {
                if ( f[i] == b[j]
                    || f[i] == Rotation(b[j], 90)
                    || f[i] == Rotation(b[j], 180)
                    || f[i] == Rotation(b[j], 270) )
                {
                    answer += f[i].size();
                    vector<vector<pair<int,int>>>::iterator iter = b.begin() + j;
                    b.erase(iter);
                    break;
                }
            }
        }
    }    
    return answer;
}

int main(void)
{
    vector<vector<int>> g = {
        {1,1,0,0,1,0},
        {0,0,1,0,1,0},
        {0,1,1,0,0,1},
        {1,1,0,1,1,1},
        {1,0,0,0,1,0},
        {0,1,1,1,0,0}
    };
    vector<vector<int>> t = {
        {1,0,0,1,1,0},
        {1,0,1,0,1,0},
        {0,1,1,0,1,1},
        {0,0,1,0,0,0},
        {1,1,0,1,1,0},
        {0,1,0,0,0,0}
    };
    cout << solution(g,t) << endl;
    return 0;
}
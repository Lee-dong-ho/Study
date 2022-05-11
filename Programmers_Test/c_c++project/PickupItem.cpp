#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<bool>> visited(101, vector<bool>(101,false));
vector<vector<bool>> box(101, vector<bool>(101,false));

int dfs(int x, int y, int ix, int iy, int route)
{
    int res = 400;
    if (x == ix && y == iy) return route;
    visited[x][y] = true;
    if (x < 100) if (!visited[x+1][y] && box[x+1][y]) res = min(dfs(x+1, y, ix, iy, route+1), res);
    if (x > 0) if (!visited[x-1][y] && box[x-1][y]) res = min(dfs(x-1, y, ix, iy, route+1), res);
    if (y < 100) if (!visited[x][y+1] && box[x][y+1]) res = min(dfs(x, y+1, ix, iy, route+1), res);
    if (y > 0) if (!visited[x][y-1] && box[x][y-1]) res = min(dfs(x, y-1, ix, iy, route+1), res); 
    return res;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = rectangle[i][0]*2; j <= rectangle[i][2]*2; j++)
            for (int k = rectangle[i][1]*2; k <= rectangle[i][3]*2; k++)
                box[j][k] = true;
    }
    for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = rectangle[i][0]*2 + 1; j <= rectangle[i][2]*2 - 1; j++)
            for (int k = rectangle[i][1]*2 + 1; k <= rectangle[i][3]*2 - 1; k++)
                box[j][k] = false;
    }

    answer = dfs(characterX*2, characterY*2, itemX*2, itemY*2, 0) / 2;
    return answer;
}

int main(void)
{
    vector<vector<int>> r = {{1,1,8,4},{2,2,4,9},{3,6,9,8},{6,3,7,7}};
    int x = 9;
    int y = 7;
    int ix = 6;
    int iy = 1;
    cout << solution(r,x,y,ix,iy) << endl;
    return 0;
}
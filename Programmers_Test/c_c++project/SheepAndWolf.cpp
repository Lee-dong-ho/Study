#include <iostream>
#include <string>
#include <vector>

using namespace std;

int FullSearch(int idx, vector<int> visited, vector<int> &info, vector<vector<int>> &e, vector<int> nextNode, int s, int w)
{
    if (info[idx]) w++; else s++;
    if (w >= s) return s;
    int res = s;
    visited[idx] = 1;
   
    for (int i=0; i<nextNode.size(); i++)
    {
        if (!visited[nextNode[i]])
        {
            vector<int> nN;
            for (int j=0; j<nextNode.size(); j++) 
                if(i != j) nN.push_back(nextNode[j]);
            for (int j=0; j<e[nextNode[i]].size(); j++) 
                if(!visited[e[nextNode[i]][j]]) nN.push_back(e[nextNode[i]][j]);
            res = max(FullSearch(nextNode[i], visited, info, e, nN, s, w), res);
        }
    }
    return res;
}
 
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    vector<int> visited;
    for(int i=0; i<info.size(); i++) visited.push_back(0);
    vector<vector<int>> e(info.size());
    for (int i=0; i<edges.size(); i++)
    {
        e[edges[i][0]].push_back(edges[i][1]);
        e[edges[i][1]].push_back(edges[i][0]);
    }
    answer = FullSearch(0, visited, info, e, e[0], 0, 0);
    
    return answer;
}

int main(void)
{
    vector<int> i = { 0,0,1,1,
                      1,0,1,0,
                      1,0,1,1 };
    vector<vector<int>> e = { {0,1}, 
                              {1,2},
                              {1,4},
                              {0,8},
                              {8,7},
                              {9,10},
                              {9,11},
                              {4,3},
                              {6,5},
                              {4,6},
                              {8,9} };

    vector<int> i2 = { 0,1,0,1,
                      1,0,1,0,
                      0,1,0 };
    vector<vector<int>> e2 = { {0,1}, 
                              {0,2},
                              {1,3},
                              {1,4},
                              {2,5},
                              {2,6},
                              {3,7},
                              {4,8},
                              {6,9},
                              {9,10} };                              

    cout << solution(i,e) << endl;
    return 0;
}
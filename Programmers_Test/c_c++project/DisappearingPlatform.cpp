#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Make_NextLocation(vector<vector<int>> board, vector<int> loc)
{
    vector<vector<int>> next_loc;
    vector<int> temp;
    int row_size = board.size()-1;
    int col_size = board[0].size()-1;
    if (loc[0] != 0)
        if(board[loc[0]-1][loc[1]]) temp[0] = loc[0]-1; temp[1] = loc[1]; next_loc.push_back(temp);
    if (loc[1] != 0)
        if(board[loc[0]][loc[1]-1]) temp[0] = loc[0]; temp[1] = loc[1]-1; next_loc.push_back(temp);
    if (loc[0] != row_size)
        if(board[loc[0]+1][loc[1]]) temp[0] = loc[0]+1; temp[1] = loc[1]; next_loc.push_back(temp);
    if (loc[1] != col_size)
        if(board[loc[0]][loc[1]+1]) temp[0] = loc[0]; temp[1] = loc[1]+1; next_loc.push_back(temp);
    return next_loc;
}

int FullSearch(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int cnt)
{
    board[aloc[0]][aloc[1]] = 0;
    board[bloc[0]][bloc[1]] = 0;
    vector<vector<int>> next_aloc, next_bloc;
    next_aloc = Make_NextLocation(board, aloc);
    next_bloc = Make_NextLocation(board, bloc);
    if (next_aloc.size() == 0) return cnt*2; // A패배
    if (next_bloc.size() == 0) return cnt*2 + 1; // B패배
    for(int i=0; i<next_aloc.size(); i++)
    {
        for(int j=0; j<next_bloc.size(); j++)
        {
            FullSearch(board, next_aloc[i], next_bloc[j], cnt + 1);
        }
    }
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc)
{
    int answer = -1;
    answer = FullSearch(board, aloc, bloc, 0);
    return answer;
}

int main(void)
{
    vector<vector<int>> board = { {1,1,1},
                                  {1,1,1},
                                  {1,1,1} };
    vector<int> aloc = {1,0};
    vector<int> bloc = {1,2};

    cout << solution(board, aloc, bloc) << endl;

    return 0;
}
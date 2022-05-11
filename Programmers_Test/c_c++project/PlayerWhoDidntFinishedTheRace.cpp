#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int index = 0;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i=0; i < completion.size(); i++) {
        if (participant[i].compare(completion[i])) {
            return participant[i];
        }
    }
    return participant[participant.size()-1];
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        
        if (target < 0)
            return result;

        sort(candidates.begin(), candidates.end());

        for (int pos = candidates.size()-1; pos >= 0; --pos){
            int elem = candidates[pos];

            vector<int> cands(candidates.begin(), candidates.begin() + pos);
            
            int multiples = 1;
            while (elem * multiples <= target){
                int rem = target - elem * multiples;
                vector<vector<int>> subResult;

                if (rem > 0){                
                    subResult = combinationSum(cands, rem);
                    for (auto &subRes : subResult){
                        for (int i=0; i < multiples; ++i){
                            subRes.push_back(elem);    
                        }
                    }
                }
                else if (rem == 0 ) {
                    subResult.push_back({});
                    for (int i=0; i < multiples; ++i){
                        subResult[0].push_back(elem);    
                    }
                }
                result.insert(result.end(), subResult.begin(), subResult.end());
                ++multiples;
            }
        }
        return result;        
    }
};

int main(int argc, char** argv){
    vector<int> candidates =  {2,3,6,7}; // {2,3,5}; //
    int target = 7; // 8 ;//

    Solution s;
    auto result  = s.combinationSum(candidates, target);
    for (int i=0; i < result.size(); ++i){
            for (int j=0; j < result[i].size(); ++j){
                cout << result[i][j] << " ";
            }
            cout << "\n";
    }
    //cout << "\n";

    return 0;
}
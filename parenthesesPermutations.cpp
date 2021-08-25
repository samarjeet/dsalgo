#include<iostream>
#include<vector>
#include<string>


using namespace std;

class Solution {
private:
    class Node{
        string left, right;
        vector<Node> children;
    };
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;


        return result;
    }
};

int main(int argc, char** argv){
    Solution s;
    std::string expression{"2-1-1"};

    auto result = s.diffWaysToCompute(expression);
    for (auto sum : result)
        std::cout << sum;
    return 0;
}

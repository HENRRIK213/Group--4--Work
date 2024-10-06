#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> s; // Declare an empty vector
        int i = 0, count = 1;
        while (count <= n && i < target.size()) {
            s.push_back("Push");
            if (count == target[i]) {
                i++;
            } else {
                s.push_back("Pop");
            }
            count++;
        }
        return s;
    }
};

// Example usage
int main() {
    Solution solution;
    // Initialize the target vector without using '{...}'
    vector<int> target;
    target.push_back(1);
    target.push_back(3);
    // target.push_back(2); // Uncomment to add more numbers

    int n = 3;
    
    vector<string> result = solution.buildArray(target, n);
    
    // Output the result
    for (size_t j = 0; j < result.size(); ++j) {
        cout << result[j] << " ";
    }
    cout << endl;

    return 0;
}

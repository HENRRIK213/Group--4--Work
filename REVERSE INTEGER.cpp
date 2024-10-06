#include <climits> // for INT_MAX and INT_MIN

class Solution {
public:
    int reverse(int x) {
        long long reverse = 0; // Use long long to handle overflow
        while(x != 0) {
            int temp = x % 10;  // Get the last digit
            x /= 10;            // Remove the last digit from x
            
            reverse = reverse * 10 + temp; // Build the reversed number
        }
        
        // Check for overflow and underflow
        if(reverse > INT_MAX || reverse < INT_MIN) {
            return 0; // Return 0 in case of overflow
        }
        
        return static_cast<int>(reverse); // Return the reversed number
    }
};

// Example usage
#include <iostream>

int main() {
    Solution solution;
    int number = 12345; // Change this value to test
    int reversedNumber = solution.reverse(number);
    std::cout << "Reversed number: " << reversedNumber << std::endl;
    return 0;
}

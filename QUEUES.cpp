#include <iostream>
#include <queue>

class MyStack {
public:
    std::queue<int> q1;
    std::queue<int> q2;

    MyStack() {
        // Constructor is empty, queues are initialized automatically
    }
    
    void push(int x) {
        // If queue1 is empty simply push the element
        if (q1.empty()) {
            q1.push(x);
        } else {
            // Transfer all elements of q1 to q2
            while (!q1.empty()) {
                int data = q1.front();
                q1.pop();
                q2.push(data);
            }
            // Push the element in q1
            q1.push(x);
            // Transfer all elements from q2 to q1
            while (!q2.empty()) {
                int val = q2.front();
                q2.pop();
                q1.push(val);
            }
        }
    }
    
    int pop() {
        // Element at front is the element to be popped
        int element = q1.front();
        q1.pop();
        return element;
    }
    
    int top() {
        // Return the element at the front without popping
        return q1.front();
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};

int main() {
    MyStack* obj = new MyStack();
    
    // Test the stack operations
    obj->push(1);
    obj->push(2);
    std::cout << "Top element: " << obj->top() << std::endl; // Should print 2
    std::cout << "Popped element: " << obj->pop() << std::endl; // Should print 2
    std::cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << std::endl; // Should print No
    std::cout << "Popped element: " << obj->pop() << std::endl; // Should print 1
    std::cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << std::endl; // Should print Yes

    // Cleanup
    delete obj;
    return 0;
}

#include <iostream>
#include <vector>

struct ListNode {
    int val;            // Value of the node
    ListNode* next;    // Pointer to the next node

    // Constructor for ease of node creation
    ListNode(int x, ListNode* nextNode = NULL) : val(x), next(nextNode) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Handle edge cases where the list is empty or has only one node
        if (head == NULL || head->next == NULL) {
            return head;  // No duplicates to remove, return the list as is
        }

        // Create a dummy node that points to the head of the list
        ListNode* dummy = new ListNode(0, head);
        
        // Initialize 'prev' to point to the dummy node
        ListNode* prev = dummy;
        
        // Initialize 'curr' to start at the head of the list
        ListNode* curr = head;

        // Traverse through the list until the end
        while (curr != NULL) {
            // Check if the current node has a duplicate
            if (curr->next != NULL && curr->val == curr->next->val) {
                // Skip all nodes that have the same value as 'curr'
                while (curr->next != NULL && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                // Link 'prev->next' to the node after the last duplicate
                prev->next = curr->next;
            } else {
                // If no duplicate is found, move 'prev' to the current node
                prev = curr;
            }
            // Move 'curr' to the next node in the list
            curr = curr->next;
        }

        // Return the modified list, starting from 'dummy->next'
        return dummy->next;
    }
};

// Helper function to create a linked list from an array
ListNode* createList(const std::vector<int>& values) {
    ListNode* head = NULL;
    ListNode** current = &head;

    for (size_t i = 0; i < values.size(); ++i) {
        *current = new ListNode(values[i]);
        current = &((*current)->next);
    }

    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "null" << std::endl;
}

// Main function to test the deleteDuplicates method
int main() {
    Solution solution;

    // Create a linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = createList(std::vector<int>(1, 1)); // Change this to create the list as needed
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    
    std::cout << "Original list: ";
    printList(head);
    
    // Remove duplicates
    head = solution.deleteDuplicates(head);
    
    std::cout << "List after removing duplicates: ";
    printList(head);
    
    // Cleanup: Free allocated memory (not shown here)
    return 0;
}





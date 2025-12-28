// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]



#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> first;
        vector<int> second;
        
        ListNode* p1 = l1;
        while(p1 != nullptr) {
            first.push_back(p1-> val);
            p1 = p1-> next;
        }

        ListNode* p2 = l2;
        while(p2 != nullptr) {
            second.push_back(p2-> val);
            p2 = p2-> next;
        }
        
        vector<int> result;
        int i=0, j=0;
        int carry = 0;

        while((i != first.size()) && (j != second.size())) {
            int a = first[i], b = second[j];
            int temp = a+b+carry;
            
            if(temp < 10) {
                result.push_back(temp);
                carry = 0; //update carry back to zero
            }
            else {
                int ptr1 = temp%10;
                result.push_back(ptr1);
                carry = temp/10;
            }
            i++;
            j++;
        }

        while(i != first.size()) {
            int x = first[i]+carry;
            if(x < 10) {
                result.push_back(x);
                carry = 0;
            }
            else {
                int ptr2 = x%10;
                result.push_back(ptr2);
                carry = x/10;
            }
            i++;
        } 

        while(j != second.size()) {
            int y = second[j]+carry;
            if(y < 10) {
                result.push_back(y);
                carry = 0;
            }
            else {
                int ptr3 = y%10;
                result.push_back(ptr3);
                carry = y/10;
            }
            j++;

        } 
        // Handle remaining carry
        if (carry > 0) result.push_back(carry); 

        //converting vector back to linked list 
        ListNode* head = new ListNode(result[0]);
        ListNode* curr = head;
        for(int i=1; i<result.size(); i++) {
            curr-> next = new ListNode(result[i]);
            curr = curr-> next;
        }

        return head;
    }
};


//Another approach 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(); // Dummy node to simplify list construction
        ListNode* curr = dummy;          // Pointer to build the result list
        int carry = 0;                   // Variable to store the carry

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with the carry from the previous step

            // Add the value from l1 if it exists
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add the value from l2 if it exists
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Update carry for the next step
            carry = sum / 10;

            // Add the current digit to the result list
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy->next; // Skip the dummy node and return the result list
    }
};

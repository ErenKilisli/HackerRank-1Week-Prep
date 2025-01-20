#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};


ListNode* insertNode(ListNode* head, int value)
{
    if (head == nullptr) return new ListNode(value);
    
    ListNode* temporary = head;
    while (temporary->next != nullptr) 
    {
        temporary = temporary->next;
    }
    
    temporary->next = new ListNode(value);
    return head;
}

void printList(ListNode *head)
{
    while (head != nullptr) 
    {
        std::cout << head->val << " ";
        head = head->next;
    }
        std::cout << endl;
}

ListNode* mergeTwoList(ListNode* l1, ListNode* l2)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;
    
    while (l1 != nullptr && l2 != nullptr) {
        if(l1->val < l2->val)
        {
            current->next = l1;
            l1 = l1->next;
        }
        else
        {
            current->next = l2;
            l2 = l2 ->next;
        }
        
        current = current->next;
    }
    
    current->next = (l1 == nullptr) ? l2:l1;
    
    return dummy->next;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int input;
    std::cin >> input;
    
    while (input--)
    {
        int n, m, value;
        cin >> n;
        
        ListNode* l1 = nullptr;
        for (int i = 0; i < n; i++) {
            cin >> value;
            l1 = insertNode(l1, value);
        }
        

        cin >> m;
        ListNode* l2 = nullptr;
        for (int i = 0; i < m; i++) {
            cin >> value;
            l2 = insertNode(l2, value);
        }
        
        printList(mergeTwoList(l1, l2));
        
    }
    return 0;
}

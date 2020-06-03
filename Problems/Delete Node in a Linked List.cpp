#include <bits/stdc++.h>

using namespace std;

 struct ListNode {
 	int val;
 	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* node) {
    
    while (node) {
    	cout<<node->val;
        node = node->next;
        if (node) {
        	cout<<"-->";
		}
    }
}

void deleteNode(ListNode* node) {
        
    node->val = node->next->val;
    node->next = node->next->next;
        
}

ListNode* makeList(vector<int> values) {
	
	ListNode* head = new ListNode(0);

    ListNode* ptr = head;
    
    for(int item : values) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = head->next;
    delete head;
    return ptr;
}

ListNode* getNode(ListNode* head, int val) {
	
	ListNode* node = head;
	
	while (node->val != val) {
		node = node->next;
	}
	
	return node;
}
    
int main() {
    
    vector<int> values = {9, 3, 5, 10, 12, 6};
    
    ListNode* head = makeList(values);
    
    cout<<"Original list: ";
    printList(head);
    cout<<endl;
    
    deleteNode(getNode(head, 10));
    
    cout<<"List after deleting (10): ";
    printList(head);
    
    
}

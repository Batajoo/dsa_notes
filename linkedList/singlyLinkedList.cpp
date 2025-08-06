#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};


void traverseList(Node *head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void traverseListRecursive(Node * head){
    if(head == nullptr){
        cout << endl;
        return;
    }
    
    cout << head->data << " ";
    traverseListRecursive(head->next);
}

bool searchKey(Node * head, int key){
    while(head != nullptr){
        if(head->data == key) return true;
        head = head->next;
    }
    return false;
}

bool searchKeyRecursive(Node * head, int key){
    if(head->data == key) return true;
    else if(head == nullptr) return false;

    return searchKeyRecursive(head->next, key);
}

int countNodes(Node * head){
    int count = 0;

    while(head != nullptr){
        count++;
        head = head->next;
    }

    return count;
}

int countNodesRecurssive(Node * head){
    if(head == nullptr) return 0;

    return 1 + countNodesRecurssive(head->next);
}
int main() {
    Node * head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    traverseListRecursive(head);
    cout << boolalpha << searchKey(head,40) << endl;
    cout << searchKeyRecursive(head, 40) << endl;
    cout << countNodes(head) << endl;
    cout << countNodesRecurssive(head) << endl;
    return 0;
}
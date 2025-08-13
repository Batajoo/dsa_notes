#include <iostream>

using namespace std;

void insertFrontProgram();
void insertBackProgram();
void insertAtPosProgram();

struct Node {
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

void printList(Node* head)
{
    // Start from the head of the list
    Node* curr = head;

    // Traverse the list
    while (curr != nullptr) {
        // Print the current node's data
        cout << " " << curr->data;

        // Move to the next node
        curr = curr->next;
    }

    // Print a newline at the end
    cout << endl;
}

Node * insertAtFront(Node * head, int data){
    Node * node = new Node(data);

    node->next = head;
    head = node;

    return head;
}

void insertAtEnd(Node * head, int data){
    Node * node = new Node(data);
    
    while(head->next != nullptr){
        head = head->next;
    }

    head->next = node;
}

Node * insertAtPos(Node * head, int pos, int data){
    if(pos < 1) return head;
    if(pos == 1){
        Node * newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node * curr = head;

    for(int index = 1; index < pos - 1; index++){
        curr = curr->next;
        if(curr == nullptr) return head;
    }


    Node * newNode = new Node(data);
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}


int main()
{
    // insertFrontProgram();
    
    // insertBackProgram();

    insertAtPosProgram();
    return 0;
}

void insertFrontProgram(){
    
    // Create the linked list 2->3->4->5
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    // Print the original list
    cout << "Original Linked List:";
    printList(head);

    // Insert a new node at the front of the list
    cout << "After inserting Nodes at the front:";
    int data = 1;
    head = insertAtFront(head, data);

    // Print the updated list
    printList(head);
}

void insertBackProgram(){
    Node * head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(6);

    cout << "Created Linked list is: ";
    printList(head);
    insertAtEnd(head,1);

    cout << "\nAfter inserting 1 at the end:";
    printList(head);
}

void insertAtPosProgram(){
    Node * head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(10);

    cout << "Before inserting:\n";
    printList(head);

    int data = 12, pos = 3;
    head = insertAtPos(head, pos, data);
    printList(head);
}
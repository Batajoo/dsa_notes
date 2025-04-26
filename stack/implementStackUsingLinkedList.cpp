#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int value){
        this->data = value;
        this->next = nullptr;
    }
};

class Stack{
    Node * head;
public:
    Stack(){
        this->head = nullptr;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void push(int new_data){
        Node * new_node = new Node(new_data);
        if(!new_node){
            cout << "Stack Overflow" << endl;
        }else {
            new_node->next = head;
            head = new_node;
        }
    }

    void pop(){
        if(this->isEmpty()){
            cout << "Stack underflow" << endl;
        } else {
            Node * temp = head;
            head = head->next;
            delete temp;
        }
    }

    int peek(){
        if(this->isEmpty()){
            cout << "Stack is empty" << endl;
            return INT_MIN;
        } else {
            return head->data;
        }
    }

};

int main() {
    Stack st;

    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    cout << "Top element is " << st.peek() << endl;

    cout << "Removing two elements..." << endl;
    st.pop();
    st.pop();

    cout << "Top element is " << st.peek() << endl;

    return 0;
    return 0;
}
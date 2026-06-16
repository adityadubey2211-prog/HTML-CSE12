#include <bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node*next;
    node(int val){
        data = val;
        next = NULL;
    }
};
class List {
    node*head;
    node*tail;
    public:
    List(){
        head = NULL;
        tail = NULL;
    }
    void push_front(int val){
        node*newnode = new node(val);
        if(head == NULL){
            head = tail = newnode;
            return;
        }
        newnode -> next = head;
        head = newnode;
    }
    void push_back(int val){
        node*newnode = new node(val);
        if(head == NULL){
            head = tail = newnode;
        }
        tail -> next = newnode;
        tail = newnode;
    }
    void pop_front(){
        if(head == NULL){
            cout<<"list is empty"<<endl;
        }
        node*temp = head;
        head = temp -> next;
        delete temp;
    }
    void pop_back(){
        if(head == NULL){
            cout<<"list is empty"<<endl;
        }
        node*temp = head;
        while(temp != NULL){
            temp = temp -> next;
        }
        delete tail;
        tail = temp;
        tail -> next = NULL;
    }
    void printll(){
        node*temp = head;
        while(temp != NULL){
            cout<<temp -> data<<"->";
            temp = temp -> next;
        }
        cout<<"null"<<endl;
    }
};
int main(){
    List ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_back(40);
    ll.pop_front();
    ll.pop_back();
    ll.printll();
    return 0;
}
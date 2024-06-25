//https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0
#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node *next;

    Node(int data1, Node *next1){
        data = data1;
        next = next1;
    } 
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node * convertArrToLL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for(int i = 1; i < arr.size();i++){
        Node *temp=new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int CheckIfPresent(Node *head, int value){
    Node *temp = head;
    while(temp){
        if(temp->data == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}


//calculating the size of the linkedlist:
int Length(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}

int main(){
    vector<int> arr = {12, 2,3 , 4, 5};
    Node *head=convertArrToLL(arr);
    // cout << head->data<<endl;
    // cout << head->next << endl;

    //traversing through the LL:
    Node *temp = head;
    // while(temp){
    //     cout << temp->data << " ";
    //     temp=temp->next;
    // }

    int count=Length(head);
    // cout<<count<<endl;
    cout << CheckIfPresent(head, 3);
}


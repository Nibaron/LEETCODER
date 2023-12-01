#include <bits/stdc++.h>
using namespace std;

struct Node{
     int data;
     Node* prev;
     Node* next;
     Node(int x): data(x),prev(nullptr),next(nullptr) {}
};


class solution{
public:
    void getPrint(Node* head)
    {
        cout<<"Given Linked List: (head to tail)"<<endl;
        while( head->next != nullptr )
        {
            cout<< head->data <<" -> ";
            head= head->next;
        }
        cout<<head->data<<endl;

        cout<<"Given Linked List: (tail to head)"<<endl;
        while ( head->prev != nullptr)
        {
            cout<< head->data <<" -> ";
            head= head->prev;
        }
        cout<<head->data<<endl;
        
    }
};

int main()
{
    vector<int> nums={1,2,4,6,8};

    Node* head= new Node(nums[0]);
    head->prev= nullptr;

    Node* temp= head;

    for(int i=1; i<nums.size(); i++)
    {
        Node* newNode= new Node(nums[i]);
        temp->next = newNode;
        newNode->prev= temp;

        temp= temp->next;
    }

    solution ob;
    ob.getPrint(head);

    return 0;
}
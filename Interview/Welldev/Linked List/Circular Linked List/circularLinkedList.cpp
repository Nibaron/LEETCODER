#include <bits/stdc++.h>
using namespace std;

struct Node{
     int data;
     Node* next;
     Node(int x): data(x), next(nullptr) {}
};


class solution{
public:
    void getPrint(Node* head)
    {
        cout<<"Given Linked List: "<<endl;
        Node* temp= head;

        while(temp->next != head)
        {
            cout<< temp->data<<" -> ";
            temp= temp->next;
        }
        cout<<temp->data<<endl;

    }

    Node* getLast(Node* head)
    {
        Node* temp= head;

        while(temp->next != head)
        {
            temp= temp->next;
        }
        return temp;
    }
};

int main()
{
    vector<int> nums={1,2,3,4,5};

    Node* head= new Node(nums[0]);
    Node* temp= head;

    for(int i=1; i<nums.size(); i++)
    {
        temp->next= new Node(nums[i]);
        temp= temp->next;
    }
    temp->next = head;

    solution obj;
    obj.getPrint(head);

    cout<<"The Last Node is: ";
    Node* last= obj.getLast(head);
    cout<<last->data<<endl;

    return 0;
}
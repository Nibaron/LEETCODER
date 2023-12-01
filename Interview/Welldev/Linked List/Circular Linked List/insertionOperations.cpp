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

    Node* inserAtHead(Node* head, int num)
    {
        Node* last= getLast(head);
        
        Node* temp= new Node(num);
        last->next= temp;
        temp->next= head;

        return temp;
    }

    void inserAtTail(Node* head, int num)
    {
        Node* last= getLast(head);
        
        Node* temp= new Node(num);
        last->next= temp;
        temp->next= head;
    }

    void insertAtIndex(Node* head, int num, int idx)
    {
        Node* prev= nullptr;
        Node* curr= head;

        while(idx--)
        {
            prev= curr;
            curr= curr->next; 
        }

        Node* temp= new Node(num);
        temp->next= curr;
        prev->next= temp;
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
    cout<<"Given Linked List: "<<endl;
    obj.getPrint(head);

    cout<<endl<<"The Last Node is: ";
    Node* last= obj.getLast(head);
    cout<<last->data<<endl;

    cout<<endl<<"After inserting 0 at head: ";
    head= obj.inserAtHead(head, 0);
    obj.getPrint(head);

    cout<<endl<<"After inserting 6 at Tail: ";
    obj.inserAtTail(head,6);
    obj.getPrint(head);

    cout<<endl<<"After inserting 99 at 4th position( 0 based indexing): ";
    obj.insertAtIndex(head, 99, 4);
    obj.getPrint(head);

    return 0;
}
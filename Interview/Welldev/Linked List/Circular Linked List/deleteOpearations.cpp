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

    Node* deleteAtHead(Node* head)
    {
        Node* last= getLast(head);
        last->next= head->next;

        return head->next;
    }

    void deleteAtTail(Node* head)
    {
        Node* prev= nullptr;
        Node* curr= head;

        while( curr->next != head)
        {
            prev= curr;
            curr= curr->next;
        }
        prev->next= head;
    }

    void deleteAtIndex(Node* head, int idx)
    {
        Node* prev= nullptr;
        Node* curr= head;

        while(idx--)
        {
            prev= curr;
            curr= curr->next; 
        }

        prev->next= prev->next->next;
    }
};

int main()
{
    vector<int> nums={1,2,3,4,5,6};

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

    cout<<endl<<"After deleting Head Node: "<<endl;
    head= obj.deleteAtHead(head);
    obj.getPrint(head);

    cout<<endl<<"After deleting Tail Node: "<<endl;
    obj.deleteAtTail(head);
    obj.getPrint(head);

    cout<<endl<<"AfterDeleting 9th( 0-based indexing) Node: "<<endl;
    obj.deleteAtIndex(head,9);
    obj.getPrint(head);

    return 0;
}
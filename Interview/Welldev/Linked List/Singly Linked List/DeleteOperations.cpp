#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(): data(0), next(nullptr){};
    Node(int x): data(x), next(nullptr){};
    Node(int x, Node* next): data(x), next(next){};
};


class solution{
    public:
        void getPrint(Node* head)
        {
            if(head == nullptr) cout<<"NULL";

            while( head != nullptr)
            {
                cout<< head->data<< " -> ";
                head= head->next;
            }
            cout<<"NULL"<< endl;
        }

        int getSize(Node* head)
        {
            int count=0;
            while(head != nullptr)
            {
                count++;
                head= head->next;
            }
            return count;
        }

        Node* deleteAtHead(Node* head)
        {   
            return head->next;
        }

        void deleteAtEnd(Node* head)
        {
            Node* fast= head->next;
            Node* slow= head;

            while( fast->next != nullptr)
            {
                fast= fast->next;
                slow= slow->next;
            }
            slow->next= nullptr;
        }

        void deleteAtIndex(Node* head, int idx)
        {
            int n= getSize(head);

            if( idx == 0) deleteAtHead(head);
            else if( idx>n ) cout<<"index is greater than List Size."<<endl;
            else if( idx == n ) deleteAtEnd(head);

            for(int i=0; i<idx-1; i++)
            {
                head= head->next; //previos of idx position
            }
            head->next= head->next->next;
        }
};

int main()
{
    vector<int> nums={0,1,2,3,4,5,6,7};
    
    //creating the head Node
    struct Node* head = new Node(nums[0]);
    
    // creating the linked List
    struct Node* temp = head;
    for(int i=1; i<nums.size(); i++)
    {
        temp->next = new Node(nums[i]);
        temp= temp->next;
    }

    solution obj;
    cout<<"Given Linked List :"<<endl;
    obj.getPrint(head);
    cout<<"The Size of Linked List is: "<<obj.getSize(head)<<endl;

    head= obj.deleteAtHead(head);
    cout<<"After Deleting Head Node: "<<endl;
    obj.getPrint(head);

    obj.deleteAtEnd(head);
    cout<<"After Deleting Tail Node: "<<endl;
    obj.getPrint(head);


    obj.deleteAtIndex(head, 3);
    cout<<"After Deleting 3rd( 0-indexing) Node: "<<endl;
    obj.getPrint(head);

    return 0;
}
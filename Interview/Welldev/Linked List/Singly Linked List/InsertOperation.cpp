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
            cout<<"Given Linked List: "<<endl;
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

        Node* insertAtHead(Node* head, int num)
        {
            Node* temp = new Node(num);
            temp->next= head;
            
            return temp;
        }

        void insertAtEnd(Node* head, int num)
        {
            while( head->next != nullptr)
            {
                head= head->next;
            }

            Node* temp= new Node(num);
            head->next= temp;

        }

        void insertAtIndex(Node* head, int idx, int num)
        {
            int n= getSize(head);

            if( idx == 0) insertAtHead(head, num);
            else if( idx>n ) cout<<"index is greater than List Size"<<endl;
            else if( idx == n ) insertAtEnd(head,num);

            for(int i=0; i<idx-1; i++)
            {
                head= head->next;
            }
            Node* temp = new Node(num);
            temp->next= head->next;
            head->next= temp;
        }
};

int main()
{
    vector<int> nums={1,2,3,4,6,7};
    
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
    obj.getPrint(head);
    cout<<"The Size of Linked List is: "<<obj.getSize(head)<<endl;

    head= obj.insertAtHead(head, 0);
    obj.getPrint(head);

    obj.insertAtEnd(head,8);
    obj.getPrint(head);

    obj.insertAtIndex(head, 5, 5);
    obj.getPrint(head);

    return 0;
}
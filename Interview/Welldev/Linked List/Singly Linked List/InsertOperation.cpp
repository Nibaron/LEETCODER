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


};

int main()
{
    vector<int> nums={1,2,3,4,5,6,7};
    
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

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct node{
     int data;
     node* next;
     node(): data(0), next(nullptr) {}
     node(int x): data(x), next(nullptr) {}
     node(int x, node* next): data(x), next(next) {}
};


class solution{
public:
    void getPrint(node* head)
    {
        cout<<"Given Linked List: "<<endl;
        while(head != NULL)
        {
            cout<< head->data <<"->";
            head= head->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    vector<int> nums={9,7,5,6,1,2,4,6,8};

    struct node* head= new node(nums[0]);
    struct node* temp= head;

    for(int i=1; i<nums.size(); i++)
    {
        temp->next= new node(nums[i]);
        temp= temp->next;
    }

    solution ob;
    ob.getPrint(head);

    return 0;
}
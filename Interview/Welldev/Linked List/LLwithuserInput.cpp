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
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        int data;
        cin>> data;

        struct node* head= new node(data);
        struct node* temp= head;

        for(int i=0; i<n-1; i++)
        {
            cin>> data;
            temp->next= new node(data);
            temp= temp->next;
        }

        solution ob;
        ob.getPrint(head);
    }

    return 0;
}
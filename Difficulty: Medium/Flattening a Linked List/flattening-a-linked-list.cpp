/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  public:
  
    Node* convert(vector<int> &arr)
    {
        int n = arr.size();
        if(n==0)return NULL;
        
        Node* head = new Node(arr[0]);
        Node* temp = head;
        
        for(int i =1;i<n;i++)
        {
            Node* newNode = new Node(arr[i]);
            temp->bottom = newNode;
            temp = newNode;
        }
        return head;
    }
  
    Node* flatten(Node* head) {
        // code here
        Node* temp = head;
        Node* t2 =NULL;
        
        vector<int> arr;
        
        while(temp!=NULL)
        {
            t2 = temp;
            
            while(t2!=NULL)
            {
                arr.push_back(t2->data);
                t2 = t2->bottom;
            }
            temp = temp->next;
        }
        // sorting the array
        sort(arr.begin(),arr.end());
        // converting the sorted array into the linked list
        return convert(arr);
        
    }
};
class Solution
{
    public:
    //here first we are taking whole node into vector then apply insertion sort and then add create a all node again
    Node* insertionSort(struct Node* head)
    {
        //code here
        Node* temp=head;
        vector<int>v;
        while(temp!=NULL){
            v.push_back(temp->data);
            temp=temp->next;
        }
        for(int i=1;i<v.size();i++){
            int temp=v[i],j=i-1;
            while(j>=0 &&  v[j]>temp ){
                v[j+1]=v[j];
                j--;
            }
            v[j+1]=temp;
        }
        Node* dummy= new Node(-1);
        temp=dummy;
        for(auto i : v){
            temp->next=new Node(i);
            temp=temp->next;
        }
        return dummy->next;
    }
    
};
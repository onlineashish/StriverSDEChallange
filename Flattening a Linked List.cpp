/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *merge(Node *first, Node * sec){
    if(sec == NULL) return first;
    if(first == NULL) return sec;
    
    Node *dumy =  new Node(0);
    Node *temp = dumy;
    while(first!=NULL && sec != NULL){
        if(first->data <= sec->data){
            temp->bottom = first;
            temp = temp->bottom;
            first = first->bottom;
        }
        else{
            temp->bottom = sec;
            temp = temp->bottom;
            sec= sec->bottom;
        }
    }
    if(first) temp->bottom = first;
    else temp->bottom = sec;
    
    return dumy->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root->next == NULL) return root;
   
   root->next = flatten(root->next);
   
   Node *node = merge(root , root->next);
   
   return node;
}

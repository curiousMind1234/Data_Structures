Node *reverseNode(Node *head, int n, int b[],int i) {
	//base case
	if( n < 1 && head == NULL){
		return head;
	}
	Node *prev = NULL;
	Node *curr  = head;
	Node *next = NULL;
	int count =0;

	while(b[i]==0 && i<n)i++;

	// reverse the nodes
	while (curr != NULL && count < b[i] && i<n) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	if(i>=n && curr!=NULL)return head;

    //recursive call to reverse nodes
	if(curr!=NULL){
		head->next = reverseNode(next, n,b,i+1);
	}

	return prev;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    return reverseNode(head,n,b,0);
}

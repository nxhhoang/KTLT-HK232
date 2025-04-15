void replace(node* head, int position, int value)
{
//TODO
	if (position < 0) return;
	if (position==0) {
		head->data = value;
	}
	int n=0;
	node* current = head;
	while(current!=nullptr) {
		current = current->next;
		n++;
	}
	if (position>=n-1) return;
	current = head;
	n = 0;
	while(current!=nullptr) {
		if (n==position) current->data=value;
		current = current->next;
		n++;
	}
}

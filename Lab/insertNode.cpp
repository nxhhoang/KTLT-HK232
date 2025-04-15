node *insertNode(node *head, node *newNode, int position)
{
// TO DO
	if (position<=0) {
		return head;
	}
	if (
	    position == 1) {
		newNode->next = head->next;
		head= newNode;
		return head;
	}
	int n = 2;
	node* current = head;
	node* prev = nullptr;
	while(current != nullptr) {
		if (n == position) {
			newNode->next = current->next;
			current->next = newNode;
			return head;
		}
		prev = current;
		current = current->next;
		n++;
	}
	prev->next = newNode;
	return head;
}

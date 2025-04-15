int searchLinkedList(node* head, int key)
{
// TODO
	node* current = head;
	int n = 0;
	while (current!=nullptr) {
		if (current->data==key) return n;
		current=current->next;
		n++;
	}
	return -1;
}

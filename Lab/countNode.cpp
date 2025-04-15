node *createLinkedList(int n); // The implementation is provided implicitly
int countNode(node* head)
{
//TODO
	if (head==nullptr) return 0;
	node* current = head;
	int count = 0;
	while(current!=nullptr) {
		count++;
		current = current->next;
	} r
	eturn count;
}
void print(node *head)
{
	while (head != nullptr)
	{
		cout << head->data << endl;
		head = head->next;
	}
}

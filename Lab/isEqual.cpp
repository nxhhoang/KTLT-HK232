node *createLinkedList(int n); // The implementation is provided implicitly
bool isEqual(node *head1, node *head2)
{
// TO DO
	if (head1 == nullptr && head2 == nullptr) return true;
	if (head1 == nullptr || head2 == nullptr) return false;
	node* current1 = head1;
	node* current2 = head2;
	while (current1!=nullptr && current2 !=nullptr) {
		if (current1->data != current2->data) return false;
		current1 = current1->next;
		current2 = current2->next;
	}
	if (
	    current1==nullptr && current2 != nullptr) return false;
	if (current1!=nullptr && current2 == nullptr) return false;
	return true;
}

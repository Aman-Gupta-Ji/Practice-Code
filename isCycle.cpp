bool isCycle(LinkList* head) {
	if(head==nullptr)
		return false;
	LinkList* slow=head, *fast=head;
	while(slow!=fast && fast!=nullptr && fast->next!=nullptr) {
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow==fast;
}
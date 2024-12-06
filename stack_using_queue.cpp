queue<int> q;
int size = 0;

void push(int n) {
	q.enququ(n);
	size++;
}


int pop() {
	size--;
	int k = size;
	whiel(k--) {
		q.enqueue(q.front());
		q.dqueuq();
	}
	int res = q.front();
	q.dqueue();
	return res;
}
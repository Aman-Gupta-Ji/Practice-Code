
stack<int> s1, s2;

void enqueu (int n) {
	s2.push(n);
}

int dqueue() {
	if(s1.empty()) {
		while(!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}
	int ret = s1.top();
	s1.pop();
	return ret;
}
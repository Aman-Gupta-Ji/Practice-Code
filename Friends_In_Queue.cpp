#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

void prettyPrintLinkedList(ListNode* node) {
  while (node && node->next) {
      cout << node->val << "->";
      node = node->next;
  }

  if (node) {
    cout << node->val << endl;
  } else {
    cout << "Empty LinkedList" << endl;
  }
}

ListNode* reverseList(ListNode* head) {
    ListNode *nextNode, *prevNode = NULL;
    while (head) {
        nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }
    return prevNode;
}

ListNode* changeQueue(ListNode *A, int B) {
    if(A == nullptr)
        return A;

    vector<ListNode*> group(B, nullptr);
    vector<ListNode*> grouptail(B, nullptr);

    int pos = 0;
    ListNode* next;

    while(A) {
        next = A->next;
        if(group[pos] == nullptr) {
            group[pos] = A;
            grouptail[pos] = A;
        }
        else {
            grouptail[pos]->next = A;
            grouptail[pos] = A;
        }
        A->next = nullptr;
        A = next;
        pos = (pos + 1) % B;
    }

    for(int i = 0; i < B; i++)
        group[i]->next = reverseList(group[i]->next);

    for(int i = 0; i < B - 1; i++)
        grouptail[i]->next = group[i + 1];

    return group[0];
}

int main() {
    string line;
    getline(cin, line);
    ListNode* A = stringToListNode(line);
    int B;
    cin>>B;
    ListNode* res = changeQueue(A, B);
    prettyPrintLinkedList(res);
    return 0;
}
#include "LinkedListNode.h"

using namespace std;

class NX{
public:
	Node<int>* N = NULL;
	bool X = false;
	NX(Node<int>* n, bool x): N(n), X(x){}
	NX(void){}
};

void getSizeandTail(Node<int>* h, int &s, Node<int>* &t){
	s=1;
	while(h->next != NULL){
		h = h->next;
		s++;
	}
	t = h;
}

NX getIntandNode(Node<int>* h1, Node<int>* h2){
	int s1, s2; 
	Node<int> *t1, *t2;
	getSizeandTail(h1, s1, t1);
	getSizeandTail(h2, s2, t2);
	cout << s1 << " " << s2 << endl;
	cout << t1 << " " << t2 << endl;
	if(t1 != t2)
		return *new NX;
	if(s1 > s2)
		for(int i=0; i<(s1-s2); i++)
			h1 = h1->next;
	if(s2>s1)
		for(int i=0; i<(s2-s1); i++)
			h2 = h2->next;
	while(h1 != h2){
		h1 = h1->next;
		h2 = h2->next;
	}
	return *new NX(h1, true);
}

int main(int argc, char* argv[]){
	Node<int>* head1 = new Node<int>(0);
	Node<int>* h = head1;
	for(int i = 1; i<5; i++){
		h -> next = new Node<int>(i);
		h = h-> next;
	}
	Node<int>* head2 = new Node<int>(0);
	h = head2;
	for(int i = 1; i<3; i++){
		h -> next = new Node<int>(i);
		h = h-> next;
	}
	h->next = head1->next;
	cout << "l1 = " << head1 << " l2 = " << head2 << endl; 
	NX intersect = getIntandNode(head1, head2);
	cout << intersect.X << " " << intersect.N << endl;
	if(intersect.X == true)
		cout << "Intersect at value " << intersect.N->val << endl;
}

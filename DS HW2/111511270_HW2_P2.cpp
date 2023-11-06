#include<bits/stdc++.h>
using namespace std;
class LinkedList;
class ListNode{
	public:
	    int data;
	    ListNode *next;
	    ListNode():data(0),next(0){};
	    ListNode(int a):data(a),next(0){};
	    friend class LinkedList;
};
class LinkedList{
	public:
		ListNode *first;
	    LinkedList():first(0){};          
	    void Push_front(int x);     
	    void pop_front();
		void pop_back();
	    void Delete(int x);                    
};

void LinkedList::pop_front(){
	first = first -> next;
	return;
}

void LinkedList::pop_back(){
	ListNode *current = first;
	ListNode *Next = 0;
    if (current->next!=NULL){
        Next = current->next;
    }
	else{
        first = 0;
        return;
    }
	while(Next -> next != 0){
		Next = Next -> next;
        current = current -> next;
	}
	current -> next = 0;
	return;
}

void LinkedList::Push_front(int x){
    ListNode *newNode = new ListNode(x);
    newNode->next = first;
    first = newNode;
    return;
}

void LinkedList::Delete(int x){
    ListNode *current = first;      
    ListNode *previous = 0;
    while (current != 0 && current->data != x) {  
        previous = current;                       
        current = current->next;                  
    }                                            
    if (current == 0) { 
        return;
    }
    else if (current == first) {
    	first = current->next;
        current = 0;                     
    }
    else {                              
        previous->next = current->next;
        current = 0;
    }
    return;
}

int main() {
	string str;
	string x;
	int n,xi;
	ifstream in("input2.txt");
	in >> n;
	LinkedList li;
	for(int i = 0;i < n;i++){
		in >> str;
		if(str == "truncateFirst"){
			li.pop_front();
		}
		else if(str == "truncateLast"){
			li.pop_back();
		}
		else{
			in >> x;
			if (x == "J"){
				xi = 11;
			}
			else if(x == "Q"){
				xi = 12;
			}
			else if(x == "K"){
				xi = 13;
			}
			else{
				xi = stoi(x);
			}
			if(str == "add"){
				li.Push_front(xi);
			}
			else{
				li.Delete(xi);
			}
		}
	}
	ListNode* temp = li.first;
	bool b = true;
	while(temp != NULL){
		if(b == true){
			b = false;
		}
		else{
			cout << " "; 
		}
		if(temp -> data > 10){
			if(temp -> data == 11){
				cout << "J";
			}
			else if(temp -> data == 12){
				cout << "Q";
			}
			else{
				cout << "K";
			}
		}
		else{
			cout << temp -> data;
		}
		temp = temp -> next;
	}
    return 0;
}

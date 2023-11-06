#include<bits/stdc++.h>
using namespace std;
class Node{
	friend class List;
	int exp;
	int coef;
	Node* link;
	public:
		Node(int x,int y):coef(x),exp(y),link(0){};
};
class List{
	Node* first;
	Node* pre;
	Node* cu;
	public:
		List():first(0){};
		void insert(int x, int y);
		void print();
};
void List::insert(int x, int y){
	Node*t  = new Node(x,y); 
	cu = first;
	if(first == 0){
		first = t;
		return;
	}
	else if(y == first -> exp){
		first -> coef += t -> coef;
		return;
	}
	else if(y >= first -> exp){
		t -> link = first;
		first = t;
		return;
	}
	else{
		while(y <= (cu -> exp)){
			if(y == cu -> exp){
				cu -> coef += t -> coef;
				return;
			}
			pre = cu;
			cu = cu -> link;
			if(cu == 0){
				break;
			}
		}
		if(cu == 0){
			pre -> link = t;
			t -> link = 0;
		}
		else{
			t -> link = cu;
			pre -> link = t;
		}
		return;
	}
}
void List::print(){
	Node* t = first;
	bool fir = true;
	while(t != 0){
		if(t -> coef == 0){
			//continue;
			//t = t -> link;
		}
		else{
			if(t -> coef > 0 && fir == false){
				cout << "+";
			}
			if(t -> coef != 1){
				cout << t -> coef;
			}
			if(t -> exp == 0){
				//continue;
			}
			else if(t -> exp == 1){
				cout << "x";
			}
			else{
				cout << "x^" << t -> exp;
			}
			fir = false;
		}
		//cout << t ->coef << " " << t->exp << " ";
		t = t -> link;
	}
}
int main()
{
	string str1,str2;
	List li;
	char ch;
	bool neg = false;
	queue<int> q;
	int i = 0,co = 0,exp = 0,j = 0;
	cin >> str1 >> str2 >> ch;
	if(str1[0] == '-'){
		neg = true;
		i++;
	}
	while(i <= str1.size()){
		if(str1[i] == 'x'){
			co = 1;
		}
		else{
			while(isdigit(str1[i])){
				q.push(str1[i]);
				i++;
			}
			while(!q.empty()){
				co += (int(q.front()) - 48) * int(pow(10,q.size() - 1));
				q.pop();
			}
		}
		if(neg == true){
			co = -co;
		}
		if(str1[i] == 'x'){
			i++;
			if(str1[i] == '^'){
				i++;
				while(isdigit(str1[i])){
					q.push(str1[i]);
					i++;
				}
				while(!q.empty()){
					exp += (int(q.front()) - 48) * int(pow(10,q.size() - 1));
					q.pop();
				}
			}
			else{
				exp = 1;
				//i++;
			}
		}
		else{
			//i++;
			exp = 0;
		}
		if(str1[i] == '+'){
			neg = false;
		}
		else{
			neg = true;
		}
		i++;
		li.insert(co,exp);
		co = 0;
		exp = 0;	
		j++;
	}
	i = 0;
	j = 0;
	neg = false;
	if(str2[0] == '-'){
		neg = true;
		i++;
	}
	while(i <= str2.size()){
		if(str2[i] == 'x'){
			co = 1;
		}
		else{
			while(isdigit(str2[i])){
				q.push(str2[i]);
				i++;
			}
			while(!q.empty()){
				co += (int(q.front()) - 48) * int(pow(10,q.size() - 1));
				q.pop();
			}
		}
		if(neg == true){
			co = -co;
		}
		if(ch == '-'){
			co = -co;
		}
		if(str2[i] == 'x'){
			i++;
			if(str2[i] == '^'){
				i++;
				while(isdigit(str2[i])){
					q.push(str2[i]);
					i++;
				}
				while(!q.empty()){
					exp += (int(q.front()) - 48) * int(pow(10,q.size() - 1));
					q.pop();
				}
			}
			else{
				exp = 1;
				//i++;
			}
		}
		else{
			//i++;
			exp = 0;
		}
		if(str2[i] == '+'){
			neg = false;
		}
		else{
			neg = true;
		}
		i++;
		li.insert(co,exp);
		co = 0;
		exp = 0;
		j++;
	}
	li.print();
	return 0;
}



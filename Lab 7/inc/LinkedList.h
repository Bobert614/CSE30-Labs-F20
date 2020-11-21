#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <ostream>

struct Node{
	std::string data;
	Node* next;

	Node (){
		data = "";
		next = NULL;
	}

	Node (std::string n){
		data = n;
		next = NULL;
	}
};

struct LinkedList{

	Node* head;
	Node* last;

	LinkedList(){
		head = NULL;
		last = NULL;
	}

	LinkedList(const LinkedList& other){ 
		head = NULL;

		if (other.head != NULL){
			Node* temp = other.head;
			while (temp != NULL){
				append(temp->data);
				temp = temp->next;
			}
		}

		last = other.last;
	}

	void append (std::string n){
		if (head == NULL){
			head = new Node(n);
			last = head;
		}
		else{
			Node* theNode = new Node(n); 
			last->next = theNode;
			last = last->next;
		}
	}

	void prepend(std::string n){
		Node* temp = new Node(n);
		temp->next = head;
		head = temp;
	}

	std::string get(long index){
		Node* temp = head;
		for (long i = 0; i < index; i++){
			if (temp == NULL){
				throw std::out_of_range("List index out of bounds.");
			}
			temp = temp->next;
		}
		return temp->data;
	}

	bool search(std::string str) {
		Node* temp = head;
		while (temp != NULL) {
			if (temp->data == str) return true;
			temp = temp->next;
		}
		return false;
	}

	bool operator==(const LinkedList& other) const {
		Node* ours = head;
		Node* theirs = other.head;

		while (ours != NULL){
			if (theirs == NULL){
				return false;
			}
			if (ours->data != theirs->data){
				return false;
			}
			else{
				ours = ours->next;
				theirs = theirs->next;
			}
		}
		return theirs == NULL;
	}

	~LinkedList(){
		Node* temp = head;
		while (temp != NULL){
			head = head->next;
			delete temp;
			temp = head;
		}
	}

};

std::ostream& operator<< (std::ostream& os, const LinkedList& theList){
	Node* temp = theList.head;
	while (temp != NULL){
		os << temp->data << " ";
		temp = temp->next;
	}
	return os;
}

#endif

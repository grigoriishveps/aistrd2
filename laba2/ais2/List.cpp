#include "List.h"

List::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

List::~List()
{
	this->clear();
}

void List::add_first(int elem) {
	tail = head = new Node(elem);
	size = 1;
}

void List::delete_one() {
	delete tail;
	tail = head = nullptr;
	size = 0;
}

void List::push_back(int elem)
{
	if (head == nullptr)
		add_first(elem);
	else {
		tail = tail->next  = new Node(elem);
		//tail = tail->next;
		size++;
	}
	
}

void List::push_front(int elem) {
	if (head == nullptr)
		add_first(elem);
	else {
		head = new Node(elem, head);
		size++;
	}
	
}

void List::pop_back() {
	Node *�ont = head;
	if (!head)
		throw out_of_range("Error list is Empty");
	else if (tail == head) {
		delete_one();
	}
	else {
		while (�ont->next != tail)
			�ont = �ont->next;
		delete tail;
		tail = �ont;
		tail->next = nullptr;
		size--;
	}
	
}

void List::pop_front() {
	if (!head)
		throw out_of_range("Error list is Empty");
	if (head == tail) {
		delete_one();
	}
	else {
		Node *�ont = head;
		head = head->next;
		delete �ont;
		size--;
	}
	
}

void List::insert(int elem, size_t index) {
	if (index == 0)
		push_front(elem);
	else if (get_size() < index)
		throw out_of_range("List out of range");
	else if (get_size() - 1 < index)
		push_back(11);
	else {
		size_t count = 0;
		Node* �ont = head;
		while (count != index - 1) {
			�ont = �ont->next;
			count++;
		}
		�ont->next = new Node(elem, (�ont->next));
		size++;
	}
	
}


int List::at(size_t index) {
	if (index > get_size()) {
		throw out_of_range("List out of range");
	}
	size_t count = 0;
	Node* �ont = head;
	while (index != count) {
		�ont = �ont->next;
		count++;
	}
	return �ont->data;
}

void List::delete_elem(size_t index) {
	if (index > get_size()) {
		throw out_of_range( "List out of range");
	}
	else if (index == 0)
		pop_front();
	else {
		size_t count = 0;
		Node* cont2, *�ont1 = head;
		while (index - 1 != count) {
			�ont1 = �ont1->next;
			count++;
		}
		cont2 = �ont1->next;
		�ont1->next = �ont1->next->next;
		delete cont2;
		size--;
	}
	
}

size_t List::get_size() {
	return size;
}

void List::print_to_console() {
	Node* �ont = head;
	if (isEmpty())
		cout << "List is empty" << endl;
	else {
		cout << "List: ";
		while (�ont != nullptr) {
			cout << �ont->data << " ";
			�ont = �ont->next;
		}
		cout << endl;
	}
}

void List::clear() {
	Node* �ont = head;
	while (�ont != nullptr) {
		�ont = �ont->next;
		delete head;
		head = �ont;
	}
	size = 0;
	head = nullptr;
	tail = nullptr;
}


void List::set(size_t index, int elem) {
	if (index >= get_size())
		throw out_of_range("List out of range");
	else {
		Node *�ont1 = head, *cont2;

		if (index == 0) {
			head->data = elem;
		}
		else {
			size_t count = 0;
			Node* �ont1 = head;
			while (count != index){
				�ont1 = �ont1->next;
				count++;
			}
			�ont1->data = elem;
		}
	}
}


bool List::isEmpty()
{
	return (head == nullptr);
}

size_t List::find_first(List *list)
{
	size_t count = 0, iterator = 0;
	Node*�ont1 = this->head, *cont2 = list->head;
	while (�ont1 != nullptr && cont2 != nullptr) {
		if (�ont1->data == cont2->data)
			cont2 = cont2->next;
		else {
			cont2 = list->head;
			count = iterator;
			if (�ont1->data == cont2->data)
				cont2 = cont2->next;
			else count++;
		}
		�ont1 = �ont1->next;
		iterator++;
	}
	if (cont2 == nullptr)
		return count;
	throw out_of_range("No sublist");
}




bool List::equal_h(int value)
{
	return (head != nullptr && head->data == value);
}

bool List::equal_t(int value)
{
	return (tail->data == value);
}

bool List::equal_i(size_t index, int value)
{
	int i = 0;
	Node*�ont = head;
	while (�ont && i < index)
	{
		�ont = �ont->next;
		i++;
	}
	return (�ont->data == value && i == index);
}

bool List::equal(List list1, List list2)
{
	Node* �ont1 = list1.head;
	Node* cont2 = list2.head;
	while (�ont1 && cont2) {
		if (�ont1->data != cont2->data)
			return false;
		�ont1 = �ont1->next;
		cont2 = cont2->next;
	} 
	return !(�ont1 || cont2);
	
}



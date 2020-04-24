#include "LinkedList.h"

//1. 템플릿 클래스로 확장해야 함
//2. Stack 형식으로 Delete 함수 재정의해야 함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야 함

//LinkedList class를 상속받음
template <class T> // (1) 템플릿 선언
class Stack : public LinkedList<T>{ // (2) LinkedList 바로 뒤에 <T> 추가
	public: // 아무것도 실행하지 않는 method 생성(method 선언만 생성)
		void Insert (T element); // (3) int를 T로 변경
		virtual bool Delete (T &element); // (4) int를 T로 변경
};

template <class T> // (5) 템플릿 선언
void Stack<T>::Insert(T element){ // Stack.h에서 Insert 정의, (6) Stack 바로 뒤에 <T> 추가, int를 T로 변경
	Node<T> *newnode = new Node<T>(element); // (7) Node 바로 뒤에 <T> 추가 X2

	newnode->link = this->first;
	this->first = newnode;
	this->current_size++;
} // this->first, this->current_size를 사용

template <class T> // (8) 템플릿 선언
bool Stack<T>::Delete(T &element){ // Stack.h에서 Delete 재정의, (9) Stack 바로 뒤에 <T> 추가, int를 T로 변경
	if (this->first == 0)
		return false;

	Node<T> *current = this->first; // first 삭제, (10) Node 바로 뒤에 <T> 추가
	this->first = this->first->link; // 다음 link가 first가 됨
			
	delete current;
	this->current_size--;

	return true;
} // this->first, this->current_size를 사용

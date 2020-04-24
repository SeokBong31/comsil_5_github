.
#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
template <class T> // (1) 템플릿 선언
class Node{
	public:
		T data; // 데이터를 저장할 변수, (2) int를 T로 변경
		Node *link; // 노드 구조체 이용, 다음 노드의 주소를 저장할 포인터

		Node(T element){ // (3) int를 T로 변경 |주의! 이 Node에는 <T> 추가 X|
		  data = element;
		  link = 0;
		}
	};

//LinkedList Class
template <class T> // (4) 템플릿 선언
class LinkedList{
	protected:
		Node<T> *first; // 첫 번째 노드의 주소를 저장할 포인터, (5) Node 다음에 <T> 추가 
		T current_size; // (6) int를 T로 변경
	public:
		LinkedList(){ // 생성자(초기화 역할)
			first = 0;
			current_size = 0;
		};

		T GetSize(){ // 노드 개수를 리턴, (7) int를 T로 변경
			return current_size;
		};

		void Insert(T element); // 맨 앞에 원소를 삽입, LinkedList와 Stack 둘 다 같음, (8) int를 T로 변경
		
		virtual bool Delete(T &element); // 맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제 - LinkedList, 재정의를 위한 virtual 선언 (9) int를 T로 변경

		void Print(); // 리스트 출력
};

template <class T> // 새 노드를 맨 앞에 붙이고 값을 넣음, (10) 템플릿 선언
void LinkedList<T>::Insert(T element){ // (11) LinkedList 바로 뒤에 <T> 추가, int를 T로 변경
	Node<T> *newnode = new Node<T>(element); // Node 생성, (12) Node 바로 뒤에 <T> 추가 X2

	newnode -> link = first; // newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 같은 뜻 
	first = newnode; // 새 노드가 첫 번째 노드를 가리킴
	current_size++;
}

template <class T> // (13) 템플릿 선언
bool LinkedList<T>::Delete(T &element){ // 마지막 노드의 값을 리턴하면서 메모리에서 할당 해제, (14) LinkedList 바로 뒤에 <T> 추가, int를 T로 변경

	if (first == 0)
		return false; // 아무것도 실행하지 않음
	
	Node<T> *current = first; // (15) Node 바로 뒤에 T 추가
	Node<T> *previous = 0; // new Node<int>(0);과 동일한 의미, (16) Node 바로 뒤에 T 추가
	
	while(1){ // 마지막 노드까지 찾아가는 반복문
		if (current->link == 0){  // 마지막 노드를 찾는 것, 현재 링크의 다음 링크가 없다면
			if (previous) // previous 존재하는 경우
				previous -> link = current -> link;
			else // previous 존재하지 않는 경우(즉, 처음부터 연결 리스트가 하나였던 경우)
				first = first -> link;
			break; // while문 탈출
		}
		previous = current;
		current = current -> link;
	}
	element = current -> data;
	delete current;

	current_size--;

	return true;
}

template <class T> // (17) 템플릿 선언
void LinkedList<T>::Print(){ // 리스트를 출력하는 Print 함수, (18) LinkedList 바로 뒤에 <T> 추가
	Node<T> *i; // (19) Node 바로 뒤에 <T> 추가
	T index = 1; // (20) int를 T로 변경

	if (current_size != 0){
		for( i = first; i != NULL; i=i->link){
			if (index == current_size){
				cout << "[" << index << "|";
				cout << i -> data <<"]";
			}
			
			else {
				cout << "[" << index << "|";
				cout << i -> data << "]";
				index++;
			}

			if (i->link != NULL){
				cout << "->";
			}
		}
		cout << endl;
	}
}

#endif // 컴파일 한 번만 하도록 명시

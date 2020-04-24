#include <stdio.h>
#include "Stack.h"

void prnMenu(){
	cout<<"*******************************************"<<endl;
	cout<<"* 1. 삽입    2. 삭제    3. 출력   4. 종료 *"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<endl;
	cout<<"원하시는 메뉴를 골라주세요: ";
}

int main(){ // 고칠 코드 X
	    int mode, selectNumber, tmpItem;
		LinkedList<int> *p;
		bool flag = false;

		cout<<"자료구조 선택(1: Stack, Other: Linked List): ";
		cin>>mode; // 입력받은 숫자를 mode에 저장
						    
		if(mode == 1) // mode가 1이라면, Stack의 정의를 따름
			p = new Stack<int>(); // 정수를 저장하는 스택
			
		else // mode가 1이 아니라면, Queue의 정의를 따름
			p = new LinkedList<int>();


		do{
			prnMenu();
			cin>>selectNumber; // 입력받은 숫자를 selectNumber에 저장
			
			switch(selectNumber){ 
				case 1: // selectNumber가 1인 경우 -> 삽입
					cout<<"원하시는 값을 입력해주세요: ";
					cin>>tmpItem;    p->Insert(tmpItem); // 입력받은 숫자를 tmpItem에 저장 후 삽입
					cout<<tmpItem<<"가 삽입되었습니다."<<endl;
					break;
					
				case 2: // selectNumber가 2인 경우 -> 삭제
					if(p->Delete(tmpItem)==true)
						cout<<tmpItem<<"가 삭제되었습니다."<<endl;
						
					else cout<<"비어있습니다. 삭제 실패"<<endl;
					break;
					
				case 3: // selectNumber가 3인 경우 -> 출력
					cout<<"크기: "<<p->GetSize()<<endl;
					p->Print();
					break;
					
				case 4: // selectNumber가 4인 경우 -> 종료
					flag = true;     break;
					
				default: // selectNumber가 그 외인 경우
					cout<<"잘못 입력하셨습니다."<<endl;
					break;
			
			}
			
			if(flag) break;
			
		} while(1);
		
		return 0;
}

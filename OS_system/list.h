// 기본적인 삽입 삭제가 Queue구조로 작동하는 리스트
// 필요조건 - 이중 링크드 리스트로 만들어야 함.

//// 노드 클래스 ///////////////////////////////////////////////////////////////////////
template<typename Type>
class Node
{
	// 노드와 노드 연산 부분을 분리하여 프로그램=노드 객체의 비대화를 막기위한 방책.
	public:
		inline Node<Type>()
		{
			pFrontLink=0;
			pRearLink=0;
			pData = new Type; // 노드 생성시에 메모리 할당 해준다 : 포인터라서 할당 해줘야 한다
		}
		
		Type *pData;            // 데이터가 저장된 부분의 주소
		Node<Type> *pFrontLink; // 이 노드의 앞 노드 주소
		Node<Type> *pRearLink;  // 이 노드의 뒷 노드 주소
};

//// 리스트 클래스 /////////////////////////////////////////////////////////////////////////
template<typename Type>
class List
{
	// 노드 연산 함수...
	public:

		int m_nLength; // 노드의 길이 저장.

		// 생성자, 새 리스트가 생성되면 그 리스트의 첫 머리 헤드는 Null
		// 노드의 길이도 0.
		inline List<Type>() 
		{

			m_nLength = 0;
		} 
		

		//void ~List<Type>();

		void AddNode(Type);		 // 노드 추가
		
		Type SubNode();			 // 제일 뒷 노드 삭제 
		void Output_Node();		 // 노드 출력

		
	
		Node<Type> *pListHead; // 리스트의 첫 노드 주소에 접근하는 접근 포인터이다.
		Node<Type> *pListTail;

		Node<Type> *pNode; // 현재 참조하고 있는 노드
		
};

//// 리스트에 노드 추가 ///////////////////////////////////////////////////////////////////////////////
// 노드추가는 리스트의 첫 머리부분에서 일어난다.
// 인자값을 받는 부분에서는 노드의 타입만을 추가해 준다...
template<typename Type> void List<Type>::AddNode(Type value)
{
	Node<Type>* new_node;
	new_node = new Node<Type>; // 노드 생성 : 내부의 멤버변수의 생성 문제는 생성자에서 처리.
	
	*new_node->pData = value;

	if(m_nLength == 0) // 리스트에 단 한개의 노드도 없을 때 - ListHead와 ListTail이 하나의 노드 주소로 서로 같다
	{
		//pListHead->pRearLink = new_node; // Head는 첫 노드에 대한 접근 포인터.(첫 노드 주소)
		pListHead = new_node;
		//pListTail->pFrontLink = new_node; // 노드가 하나밖에 없으므로 헤드와 테일이 같다.
		pListTail = new_node;

		//new_node->pFrontLink = pListHead;
		//new_node->pRearLink = pListTail;

	}
	else // 리스트에 노드가 존재 할 때.
	{
		new_node->pRearLink = pListHead;
		pListHead->pFrontLink = new_node;
		pListHead = new_node;

		//pListHead->pRearLink->pFrontLink = new_node; // 제일 첫 노드의 앞노드 주소를 새로 생성한 노드로 셋팅
		//new_node->pRearLink = pListHead->pRearLink;  // 새 노드의 뒷 노드 주소를 이전 첫 노드의 주소로 셋팅

		//pListHead->pRearLink = new_node;  // ListHead의 뒷 노드 주소를 새 노드로
		//new_node->pFrontLink = pListHead; // 새 노드의 앞노드 주소를 ListHead로
	}

	m_nLength++; // 노드갯수 증가.

			
}

//// 리스트에 노드 제거 /////////////////////////////////////////////////////////////////////////////
// 노드들의 값이 유니크 함을 가정함.
// 주의 예외 사항 : 노드가 하나밖에 없을때 - Not Test

template<typename Type> Type List<Type>::SubNode()
{
	Node<Type> *pTemp;
	pTemp = new Node<Type>;
	
	if(m_nLength == 0)
	{
		printf("Node is Empty\n");
	}
	else
	{
		pTemp = pListTail; // 
	
		pListTail = pListTail->pFrontLink;
		
		m_nLength--;

		return *pTemp->pData;
		
	}
}


//// 리스트의 노드 출력 /////////////////////////////////////////////////////////////////////////////

template<typename Type> void List<Type>::Output_Node()
{
	int count=0;

	Node<Type> *pReadNode;

	pReadNode = pListHead; // 읽어야 할 첫 노드지정.

	while(count <= m_nLength-1)
	{
		printf("Node #%d : %d\n", count, *pReadNode->pData);
		
		pReadNode = pReadNode->pRearLink;

		count++;
	}

}


//// 리스트 파괴 - 노드 전부 제거 //////////////////////////////////////////////////////////////////////
/*
template<typename Type> List<Type>::~List()
{
	Node<Type> *del_taget, next_del_target;

	del_target=pListfront;
	
	while((next_del_target->pLink = del_target))
	{
		next_del_target=del_target->pLink;
		delete del_target->pData;
		delete del_target;
		Node<Type> *del_taget;
		del_target=next_del_target;
	}
	delete next_del_taget;
}
*/


// �⺻���� ���� ������ Queue������ �۵��ϴ� ����Ʈ
// �ʿ����� - ���� ��ũ�� ����Ʈ�� ������ ��.

//// ��� Ŭ���� ///////////////////////////////////////////////////////////////////////
template<typename Type>
class Node
{
	// ���� ��� ���� �κ��� �и��Ͽ� ���α׷�=��� ��ü�� ���ȭ�� �������� ��å.
	public:
		inline Node<Type>()
		{
			pFrontLink=0;
			pRearLink=0;
			pData = new Type; // ��� �����ÿ� �޸� �Ҵ� ���ش� : �����Ͷ� �Ҵ� ����� �Ѵ�
		}
		
		Type *pData;            // �����Ͱ� ����� �κ��� �ּ�
		Node<Type> *pFrontLink; // �� ����� �� ��� �ּ�
		Node<Type> *pRearLink;  // �� ����� �� ��� �ּ�
};

//// ����Ʈ Ŭ���� /////////////////////////////////////////////////////////////////////////
template<typename Type>
class List
{
	// ��� ���� �Լ�...
	public:

		int m_nLength; // ����� ���� ����.

		// ������, �� ����Ʈ�� �����Ǹ� �� ����Ʈ�� ù �Ӹ� ���� Null
		// ����� ���̵� 0.
		inline List<Type>() 
		{

			m_nLength = 0;
		} 
		

		//void ~List<Type>();

		void AddNode(Type);		 // ��� �߰�
		
		Type SubNode();			 // ���� �� ��� ���� 
		void Output_Node();		 // ��� ���

		
	
		Node<Type> *pListHead; // ����Ʈ�� ù ��� �ּҿ� �����ϴ� ���� �������̴�.
		Node<Type> *pListTail;

		Node<Type> *pNode; // ���� �����ϰ� �ִ� ���
		
};

//// ����Ʈ�� ��� �߰� ///////////////////////////////////////////////////////////////////////////////
// ����߰��� ����Ʈ�� ù �Ӹ��κп��� �Ͼ��.
// ���ڰ��� �޴� �κп����� ����� Ÿ�Ը��� �߰��� �ش�...
template<typename Type> void List<Type>::AddNode(Type value)
{
	Node<Type>* new_node;
	new_node = new Node<Type>; // ��� ���� : ������ ��������� ���� ������ �����ڿ��� ó��.
	
	*new_node->pData = value;

	if(m_nLength == 0) // ����Ʈ�� �� �Ѱ��� ��嵵 ���� �� - ListHead�� ListTail�� �ϳ��� ��� �ּҷ� ���� ����
	{
		//pListHead->pRearLink = new_node; // Head�� ù ��忡 ���� ���� ������.(ù ��� �ּ�)
		pListHead = new_node;
		//pListTail->pFrontLink = new_node; // ��尡 �ϳ��ۿ� �����Ƿ� ���� ������ ����.
		pListTail = new_node;

		//new_node->pFrontLink = pListHead;
		//new_node->pRearLink = pListTail;

	}
	else // ����Ʈ�� ��尡 ���� �� ��.
	{
		new_node->pRearLink = pListHead;
		pListHead->pFrontLink = new_node;
		pListHead = new_node;

		//pListHead->pRearLink->pFrontLink = new_node; // ���� ù ����� �ճ�� �ּҸ� ���� ������ ���� ����
		//new_node->pRearLink = pListHead->pRearLink;  // �� ����� �� ��� �ּҸ� ���� ù ����� �ּҷ� ����

		//pListHead->pRearLink = new_node;  // ListHead�� �� ��� �ּҸ� �� ����
		//new_node->pFrontLink = pListHead; // �� ����� �ճ�� �ּҸ� ListHead��
	}

	m_nLength++; // ��尹�� ����.

			
}

//// ����Ʈ�� ��� ���� /////////////////////////////////////////////////////////////////////////////
// ������ ���� ����ũ ���� ������.
// ���� ���� ���� : ��尡 �ϳ��ۿ� ������ - Not Test

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


//// ����Ʈ�� ��� ��� /////////////////////////////////////////////////////////////////////////////

template<typename Type> void List<Type>::Output_Node()
{
	int count=0;

	Node<Type> *pReadNode;

	pReadNode = pListHead; // �о�� �� ù �������.

	while(count <= m_nLength-1)
	{
		printf("Node #%d : %d\n", count, *pReadNode->pData);
		
		pReadNode = pReadNode->pRearLink;

		count++;
	}

}


//// ����Ʈ �ı� - ��� ���� ���� //////////////////////////////////////////////////////////////////////
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


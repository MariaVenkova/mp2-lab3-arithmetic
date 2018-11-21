#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

template <class T>
class TStack
{
	T*pMem; //��������� �� ������ ���������
	int size; // ������ ������ ��� �����
	int top; // ��������� �� ������� �����
	int DataCount; // ���������� ��������� � �����
public:

	TStack(int _size)
	{
		DataCount = 0;
		size = _size;
		top = -1;
		if ((size < 1) || (size > MaxStackSize))
			throw "size";
		pMem = new T[size];
	}
	TStack(const TStack & st) //�����������
	{
		DataCount = 0;
		size = st.size;
		pMem = new T[size];
		for (int i = 0; i < size; i++) {
			pMem[i] = st.pMem[i];
		}
	}
	~TStack()
	{
		delete[] pMem;
	}
	int GetNextIndex(int index)// �������� ��������� ������
	{
		int res = index + 1;
		if (res > size)
			throw "error";
		return res;
	}
	void Put(const T&val) //���������� ��������
	{
		if (!IsFull())
		{
			top = GetNextIndex(top);
			pMem[top] = val;
			DataCount++;
		}
		else
			throw "error";
	}
	T Get(void) // �������� ��������
	{
		if (!IsEmpty())
		{
			DataCount--;
			return pMem[top--];
		}
		else
			throw"error";
	}
	bool IsEmpty() //�������� �� �������
	{
		if (DataCount == 0)
			return true;
		else
			return false;
	}
	bool IsFull() //�������� �� �������
	{
		if (DataCount == MaxStackSize)
			return true;
		else
			return false;
	}
	void Print(void) //�����
	{
		for (int i = 0; i < MemSize; i++)
			cout << "Stack[" << i << "]= " << pMem[i] << endl;
	}
};

#endif
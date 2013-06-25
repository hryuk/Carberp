#pragma once
//#include <iostream>
//using namespace std;

template <class T> class TREE
{
public:
	struct Node
	{
		T data;	//информационное поле, данные, любой порядковый тип
		Node *next; 	//указатель на следующий элемент
		Node *child;
	};
	typedef Node * PNode;
	Node* root;

	TREE()
	{
		root=NULL;
	}
	~TREE()
	{
	}

	PNode Insert_end (T dat)
	{
		PNode temp_p;
		temp_p = new Node();	//выделение области памяти
		temp_p-> data = dat;	//заполнение информационного поля
		temp_p-> next = NULL;
		temp_p-> child = NULL;
		if(root==NULL)
		{
			root=temp_p;
			return temp_p;
		}
		else
		{
			PNode fnd;
			for(fnd = root;fnd->next!=NULL;fnd=fnd->next){}
			fnd->next=temp_p;
		}
		return temp_p;
	}	//Insert_end

	PNode Insert (T dat, PNode after)
	{
		PNode temp_p;
		temp_p = new Node();	//выделение области памяти
		temp_p-> data = dat;	//заполнение информационного поля
		temp_p-> next = NULL;
		temp_p-> child = NULL;
		if(root==NULL)
		{
			root=temp_p;
			return temp_p;
		}
		else
		{
			PNode old_next = after->next;
			after->next = temp_p;
			temp_p->next = old_next;
		}
		return temp_p;
	}	//Insert_end

	/*
	PNode Insert_child_end (T dat)
	{
		PNode temp_p;
		temp_p = new Node();	//выделение области памяти
		temp_p-> data = dat;	//заполнение информационного поля
		temp_p-> next = NULL;
		temp_p-> child = NULL;
		if(root==NULL)
		{
			root=temp_p;
			return temp_p;
		}
		else
		{
			PNode fnd;
			for(fnd = root;fnd->next!=NULL;fnd=fnd->next){}
			for(;fnd->child!=NULL;fnd=fnd->child){}
			fnd->child=temp_p;
		}
		return temp_p;
	}	//Insert_child_end
	*/

	PNode Insert_child (T dat, PNode to)
	{
		PNode temp_p;
		temp_p = new Node();	//выделение области памяти
		temp_p-> data = dat;	//заполнение информационного поля
		temp_p-> next = NULL;
		temp_p-> child = NULL;
		if(root==NULL)
		{
			root=temp_p;
			return temp_p;
		}
		else
		{
			if(to->child == NULL) to->child = temp_p;
			else
			{
				for(to=to->child;to->next!=NULL;to=to->next){}
				to->next=temp_p;
			}
		}
		return temp_p;
	}	//Insert_child_end

	int GetCount()
	{
		int count=0;
		PNode fnd = root;
		while(fnd!=NULL)
		{
			count++;
			fnd=fnd->next;
		}
		return count;
	}
	bool foundN(int dat)
	{
		PNode fnd = root;
		while(fnd!=NULL)
		{
			if(fnd->data==dat) return true;
			fnd=fnd->next;
		}
		return false;
	}
	void Clear()
	{
		root=NULL;
		PNode fnd = root;
	}
};

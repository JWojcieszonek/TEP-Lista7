#pragma once
#include "CRefCounter.h"

template< typename T> class CMySmartPointer
{
public:
	CMySmartPointer(T *pcPointer);
	CMySmartPointer(const CMySmartPointer<T> &pcOther);
	~CMySmartPointer();
	T& operator*() { return(*pc_pointer); }
	T* operator->() { return(pc_pointer); }
	CMySmartPointer<T>& operator=(const CMySmartPointer<T> &pcOther);
private:
	T *pc_pointer;
	CRefCounter *pc_counter;
};

template <typename T>
CMySmartPointer<T>::CMySmartPointer(T* pcPointer)
{
	pc_pointer = pcPointer;
	pc_counter = new CRefCounter();
	pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer<T> &pcOther)
{
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::~CMySmartPointer()
{
	if (pc_counter->iDec() == 0)
	{
		delete pc_pointer;
		delete pc_counter;
	}
}

template<typename T>
CMySmartPointer<T>& CMySmartPointer<T>::operator=(const CMySmartPointer<T>& pcOther)
{
	if (this != &pcOther)
	{
		if (pc_counter->iDec() == 0)
		{
			delete pc_pointer;
			delete pc_counter;
		}

		pc_pointer = pcOther.pc_pointer;
		pc_counter = pcOther.pc_counter;
		pc_counter->iAdd();
	}
	return *this;
}
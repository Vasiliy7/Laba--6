#include <stdio.h>
#include <math.h>
#include <iostream>
#include <time.h>
#define NUM 20


//Классы данных
class A
{
private:
	int _value;
public:
	A()
	{

	}
	A(int value)
	{
		this->_value = value;
	}
	void swap(A & changer1, A & changer2)
	{
		A p(changer1._value);
		changer1._value = changer2._value;
		changer2._value = p._value;
	}
	bool operator ==(A const & b)
	{
		return (this->_value == b._value);
	}

	bool operator !=(A const & b)
	{
		return !(*this == b);
	}

	bool operator <(A const & b)
	{
		return (this->_value < b._value);
	}

	bool operator >(A const & b)
	{
		return (this->_value > b._value);
	}

	bool operator <=(A const & b)
	{
		return !(*this > b);
	}

	bool operator >=(A const & b)
	{
		return !(*this < b);
	}
	void print()
	{
		std::cout << this->_value << " ";
	}
};
class B
{
private:
	int _value;
public:
	B()
	{

	}
	B(int value)
	{
		this->_value = value;
	}
	void swap(B & changer1, B & changer2)
	{
		changer1._value = changer1._value + changer2._value;
		changer2._value = changer1._value - changer2._value;
		changer1._value = changer1._value - changer2._value;
	}
	bool operator ==(B const & b)
	{
		return (this->_value == b._value);
	}

	bool operator !=(B const & b)
	{
		return !(*this == b);
	}

	bool operator <(B const & b)
	{
		return (this->_value < b._value);
	}

	bool operator >(B const & b)
	{
		return !(*this < b);
	}

	bool operator <=(B const & b)
	{
		return !(*this > b);
	}

	bool operator >=(B const & b)
	{
		return !(*this < b);
	}
	void print()
	{
		std::cout << this->_value << " ";
	}
};

//шаблонные функции сортировки
template< class T >
void downHeap(T a[], long k, long n)
{
	//  процедура просеивания следующего элемента 
	//  До процедуры: a[k+1]...a[n]  - пирамида 
	//  После:  a[k]...a[n]  - пирамида 
	T new_elem;
	long child;
	new_elem = a[k];

	while (k <= n / 2) // пока у a[k] есть дети 
	{
		child = 2 * k;

		if (child < n && a[child] < a[child + 1]) //  выбираем большего сына 
			child++;
		if (new_elem >= a[child])
			break;
		// иначе 
		a[k] = a[child];    // переносим сына наверх 
		k = child;
	}
	a[k] = new_elem;
}
template< class T >
void heapSort(T a[], long size)
{
	long i;
	
	// строим пирамиду 
	for (i = size / 2 - 1; i >= 0; --i)
		downHeap(a, i, size - 1);

	// теперь a[0]...a[size-1] пирамида 

	for (i = size - 1; i > 0; --i)
	{
		// меняем первый с последним
		a[0].swap(a[i], a[0]);
		
		// восстанавливаем пирамидальность a[0]...a[i-1] 
		downHeap(a, 0, i - 1);
	}
}

void main()
{
	srand(time(NULL));
	A *infA = new A[NUM];
	B *infB = new B[NUM];
	for (int i = 0; i < NUM; i++)
	{
		infA[i] = A(rand() % 101);
		infB[i] = B(rand() % 10001);
	}
	
	heapSort<A>(infA, NUM);
	heapSort<B>(infB, NUM);
	for (int i = 0; i < NUM; i++)
	{
		infA[i].print();
	}
	std::cout << std::endl << std::endl;
	for (int i = 0; i < NUM; i++)
	{
		infB[i].print();
	}
	std::cout << std::endl << std::endl;
}
#include <iostream.h>

const int DefaultSize = 10;

class Animal
{
	public:
		Animal(int);
		Animal();
		~Animal() {}
		int GetWeight() const { return itsWeight; }
		void Display() const { cout << itsWeight; }
	private:
		int itsWeight;
};

Animal::Animal(int weight):
itsWeight(weight)
{}

Animal::Animal():
itsWeight(0)
{}

template <class T>
class Array
{
	public:
		Array(int itsSize = DefaultSize);
		Array(const Array &rhs);
		~Array() { delete [] pType; }

		Array& operator=(const Array&);
		T& operator[](int offset) { return pType[offset]; }

		int GetSize() { return itsSize; }

	private:
		T *pType;
		int itsSize;
};

template <class T>
Array<T>::Array(int size = DefaultSize):
itsSize(size)
{
	pType = new T[size];
	for (int i=0 ; i<size ; i++)
		pType[i]=0;
}

template <class T>
Array<T>::Array(const Array &rhs)
{
	itsSize = rhs.GetSize();
	pType = new T[itsSize];
	for (int i=0 ; i<itsSize ; i++)
		pType[i] = rhs[i];
}

template <class T>
Array<T>& Array<T>::operator =(const Array &rhs)
{
	if (this==&rhs)
		return *this;
	delete [] pType;
	itsSize = rhs.GetSize();
	pType = new T[itsSize];
	for(int i=0 ; i<itsSize ; i++)
		pType[i] = rhs[i];
	return *this;
}

int main()
{
	Array<int> theArray;
	Array<Animal> theZoo;
	Animal *pAnimal;
	
	for(int i=0 ; i<theArray.GetSize(); i++)
	{
		theArray[i] = i*2;
		pAnimal = new Animal(i*3);
		theZoo[i] = *pAnimal;
		delete pAnimal;
	}

	for(int j=0 ; i<theArray.GetSize(); j++)
	{
		cout << "theArray[" << j << "]: \t";
		cout << theArray[j] << "\t\t";
		cout << "theZoo[ " << j << "]: \t";
		theZoo[j].Display();
		cout << endl;
	}

	for(int k=0 ; k < theArray.GetSize() ; k++)
		delete &theZoo[j];
	return 0;

}

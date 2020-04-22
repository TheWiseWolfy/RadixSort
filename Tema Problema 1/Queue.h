#pragma once

#define DIMMAX 16

template <typename Atom>
class Queue {
	Atom* vec;			           //vector stocare elemente
	int capacity;		          //marimea actuala a cozii
	int head, tail;		         // pozitii relevante
	int count;      			//spatii ocupate
public:
	Queue(int size = DIMMAX);   //constructor
	~Queue();					//destructor
	void put(Atom n);
	void skip();
	Atom peek();
	int size();
	bool isFull();
	bool isEmpty();
private:
	void resize(int n);
};

//Constructor
template<typename Atom>
inline Queue<Atom>::Queue(int size) {
	vec = new Atom[size];
	capacity = size;
	head = 0;
	tail = -1;
	count = 0;
}

//Destructor 
template<typename Atom>
inline Queue<Atom>::~Queue() {
	delete[] vec;
}

//Important
template<typename Atom>
void Queue<Atom>::put(Atom n) {
	// verifica daca mai ai spatiu

	if (isFull()) {
		//Daca nu mai ai, fa mai mult ,exponential
		capacity *= 2;
		resize(capacity);
	}
	tail = (tail + 1) % capacity;
	vec[tail] = n;
	count++;
}

template<typename Atom>
void Queue<Atom>::skip(){
	// check for queue underflow

	if (isEmpty())
	{
		std::cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	//std::cout << "Removing " << vec[head] << '\n';

	head = (head + 1) % capacity;
	count--;
}

template<typename Atom>
void Queue<Atom>::resize(int n)
{
	int toTransfer = count, i =0 , j = head ;
	Atom* temp = nullptr;
	Atom* newVec = new Atom[n];

	while (i < toTransfer) {
		newVec[i] = vec[j];
		++j;
		++i;
		if (j >= count) {
			j = 0;
		}
	}

	temp = vec;
	vec = newVec;
	delete(temp);

	//Important 
	head = 0;
	tail = i -1;
	capacity = n;
}

template<typename Atom>
Atom Queue<Atom>::peek(){

	if (isEmpty()){
		std::cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return vec[head];
}

//Utility
template<typename Atom>
inline int Queue<Atom>::size(){
	return count;
}

template<typename Atom>
bool Queue<Atom>::isFull() {
	return capacity == count;
}

template<typename Atom>
bool Queue<Atom>::isEmpty(){
	return (count == 0);
}

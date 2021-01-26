#include <iostream>

using namespace std;

/* Abstract of observer */
class Observer {
public:
	virtual void HandleLimitReached() = 0;
};

/* Counter abstract class */
class Counter {
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};

/* OverflowCounter derived from Counter abstract class */
class OverflowCounter : public Counter {
public:
	OverflowCounter(int initCtr = 0, int limit0 = 10);
	virtual void inc();
	virtual void dec();
	virtual operator int();
	void SetObserver(Observer* observer);
private:
	void Notify();
	int counter;
	int limit;
	Observer* obs;
};

/* Sample class that implements observer interface */
class CounterUser : public Observer {
public:
	// Constructor. Initialize overflow counter subject and make it pointer to the current CounterUser observer.
	CounterUser(int limit0 = 5) {
		subject = OverflowCounter(0, limit0);
		subject.SetObserver(this);
	}
	void incrementBy(int value) {
		for (int i = 0; i < value; i++) subject.inc();
	}
	virtual void HandleLimitReached() {
		cout << "Limit has been reached" << endl;
	}
private:
	OverflowCounter subject;
};

int main(int argc, char** argv) {
	CounterUser cu(5);
	cu.incrementBy(12); //OUTPUT: two times "Limit has been reached"
	CounterUser cu2(9);
	cu2.incrementBy(9);
	cout << "Just passing time" << endl;
	cu2.incrementBy(1); //OUTPUT: "Limit has been reached"
	
	return 0;
}

/* OverfloweCounter implementation */
// Constructor
OverflowCounter::OverflowCounter(int initCtr, int limit0) : obs(nullptr)
{
	if (limit0 < 0) {
		limit = 0;
	}
	else {
		limit = limit0;
	}

	if (initCtr > limit) {
		counter = limit;
	}
	else if (initCtr < 0) {
		counter = 0;
	}
	else {
		counter = initCtr;
	}
}

void OverflowCounter::inc()
{
	if (counter < limit) {
		counter++;
	}
	else {
		Notify();
		counter = 0;
	}
}

void OverflowCounter::dec()
{
	if (counter > 0) {
		counter--;
	}
	else {
		Notify();
		counter = limit;
	}
}

OverflowCounter::operator int()
{
	return counter;
}

/* Observer pattern related function */
void OverflowCounter::SetObserver(Observer *observer)
{
	obs = observer;
}

void OverflowCounter::Notify()
{
	obs->HandleLimitReached();
}
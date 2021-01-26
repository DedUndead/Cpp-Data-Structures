#include <iostream>

using namespace std;

class Counter {
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};

class LimitedCounter : public Counter {
public:
	LimitedCounter(int initCtr = 0, int limit0 = 10);
	virtual void inc();
	virtual void dec();
	virtual operator int();
private:
	int counter;
	int limit;
};

class OverflowCounter : public Counter {
public:
	OverflowCounter(int initCtr = 0, int limit0 = 10);
	virtual void inc();
	virtual void dec();
	virtual operator int();
private:
	int counter;
	int limit;
};

void UseCounter(Counter& ctr, int num);

int main(int argc, char** argv) {
	LimitedCounter lc(0, 5);
	OverflowCounter oc(5, 9);

	cout << oc << endl;
	UseCounter(oc, 5);
	cout << oc << endl; // should display zero
	UseCounter(oc, -1);
	cout << oc << endl; // should display 9
	oc.dec();
	cout << oc << endl; // should display 8

	cout << lc << endl;
	lc.inc();
	cout << lc << endl;
	lc.dec();
	cout << lc << endl;
	for(int i = 0; i < 10; ++i) lc.inc();
	cout << lc << endl;
	UseCounter(lc, -9);
	cout << lc << endl;

	return 0;
}

void UseCounter(Counter& ctr, int num)
{
	// Occures for positive
	for (int i = 0; i < num; i++) {
		ctr.inc();
	}

	// Occures for negative
	for (int i = num; i < 0; i++) {
		ctr.dec();
	}

}

/* LimitedCounter implementation */
// Constructor
LimitedCounter::LimitedCounter(int initCtr, int limit0) 
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

void LimitedCounter::inc()
{
	if (counter < limit) {
		counter++;
	}
}

void LimitedCounter::dec()
{
	if (counter > 0) {
		counter--;
	}
}

LimitedCounter::operator int()
{
	return counter;
}

/* OverfloweCounter implementation */
// Constructor
OverflowCounter::OverflowCounter(int initCtr, int limit0)
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
		counter = 0;
	}
}

void OverflowCounter::dec()
{
	if (counter > 0) {
		counter--;
	}
	else {
		counter = limit;
	}
}

OverflowCounter::operator int()
{
	return counter;
}

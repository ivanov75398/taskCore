#pragma once

#include <iostream>

using namespace std;


class TASK
{
	int id;
	int time;
public:
	TASK() { id = rand() % 100; time = (rand() % 15) + 1; }
	TASK(int _Id, int _Time) { id = _Id; time = _Time; if (time <= 0) throw - 1; }
	int GetId() { return id; }
	int GetTime() { return time; }
	void TimeStep() { time = time - 1; }
	TASK &operator=(const TASK &b);
	friend istream& operator >> (istream &in, TASK &v)
	{
			in >> v.id;
		return in;
	}
	friend ostream& operator<<(ostream &out, const TASK &v)
	{
			out << "id: " << v.id << " time: " << v.time << ' ';
		return out;
	}
};

class TURN
{
	TASK *mem;
	int size, top, end;
public:
	//int GetSize() { return size; }
	TURN();
	TURN(int _size);
	bool isempty();
	bool isfull();
	void push(TASK a);
	TASK pop();
};

// TASK;

TASK &TASK:: operator=(const TASK &b)
{
	if (this == &b) return *this;
	id = b.id;
	time = b.time;
	return *this;
}

// TURN;

TURN::TURN()
{
	size = 10;
	mem = new TASK[size];
	end = size - 1;
	top = 0;
}


TURN::TURN(int _size)
{
	if (_size <= 0) { throw - 3; }
	size = _size;
	mem = new TASK[size];
	end = size - 1;
	top = 0;
}

bool TURN::isempty()
{
	return (top == (end + 1) % size);
}

bool TURN::isfull()
{
	return (top == (end + 2) % size);
}

void TURN::push(TASK a)
{
	if (isfull()) throw - 1;
	end = (end + 1) % size;
	mem[end] = a;
}

TASK TURN::pop()
{
	if (isempty()) throw - 2;
	TASK a = mem[top];
	top = (top + 1) % size;
	return a;
}
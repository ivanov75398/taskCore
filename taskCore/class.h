#pragma once

#include <iostream>

int p = 1;
class TASK
{
	int id;
	int time;
public:
	int GetId() { return id; }
	int GetTime() { return time; }
	void TimeStep() { time = time - 1; }
	TASK &operator=(const TASK &b);
	TASK() { id = p; p++; time = rand() % 5; }
	TASK(int _Id, int _Time) { id = _Id; time = _Time; }
};

class TURN
{
	TASK *mem;
	int size, top, end;
public:
	int GetSize() { return size; }
	TURN(int _size);
	bool isempty();
	bool isfull();
	void push(TASK a);
	TASK pop();
};

class CORE
{
	TASK c1;
	TASK c2;
public:
	void step(TURN t);
};

// TASK;

TASK &TASK:: operator=(const TASK &b)
{
	id = b.id;
	time = b.time;
	return *this;
}

// TURN;

TURN::TURN(int _size)
{
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

// CORE;

void CORE::step(TURN t)
{
	while (t.isempty == false)
	{
		c1.TimeStep();
		c2.TimeStep();
		if (c1.GetTime == 0) { c1 = t.pop(); }
		if (c2.GetTime == 0) { c2 = t.pop(); }
	}
}


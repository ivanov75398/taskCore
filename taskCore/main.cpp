#include "class.h"

int const SIZEoch = 10;

int main()
{
	TURN och(SIZEoch);

	TASK t1(1, 3);
	TASK t2(2, 3);
	TASK t3(3, 1);
	TASK t4(4, 2);

	och.push(t1);
	och.push(t2);
	och.push(t3);
	och.push(t4);

	int CORE0[100];
	int CORE1[100];
	int i = 0;
	int j = 0;

	TASK A = och.pop();
	int t;
	t = A.GetTime();
	for (int k = 0; k < t; k++)
	{
		CORE0[k] = A.GetId();
	}
	i = t - 1;

	A = och.pop();
	t = A.GetTime();
	for (int k = 0; k < t; k++)
	{
		CORE1[k] = A.GetId();
	}
	j = t - 1;

	int k = 0;
	while (och.isempty() == false)
	{
		A = och.pop();
		t = A.GetTime();
		if (i > j)
		{
			j++;
			for (k = j; k < (j + t); k++)
			{
				CORE1[k] = A.GetId();
			}
			j = k - 1;
		}
		else
		{
			i++;
			for (k = i; k < (i + t); k++)
			{
				CORE0[k] = A.GetId();
			}
			i = k - 1;
		}
	}

	cout << "core0: ";
	for (int h = 0; h <= i; h++)
	{
		cout << "t" << CORE0[h] << " ";
	}
	cout << endl << "core1: ";
	for (int h = 0; h <= j; h++)
	{
		cout << "t" << CORE1[h] << " ";
	}
	cout << endl;


/*	while (SIZEoch == 10)
	{
		cout << "t" << c0.GetId() << "  /  " << "t" << c0.GetId() << endl;
		c0.TimeStep();
		c1.TimeStep();
		if ((c1.GetTime() == 0)&&(och.isempty() != false)) c1 = och.pop();
		if ((c2.GetTime() == 0)&&(och.isempty() != false)) c2 = och.pop();
	}	*/

/*	TASK task[2];
	//task = new TASK[SIZE];
	TURN turn(20);

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (task[j].GetTime() == j)
				{
					task[j] = turn.pop();
				}
				cout << "c" << j << ": " << task[j] << "     ";
				task[j].TimeStep();
			}
			cout << endl;
		}	*/

	return 0;
}
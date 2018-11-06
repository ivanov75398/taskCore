#include "class.h"

int SIZE = 2;

int main()
{
	TASK task[2];
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
		}
		

	return 0;
}
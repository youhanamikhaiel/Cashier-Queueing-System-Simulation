#include "pch.h"
#include <iostream>
#include <random>
#include <fstream>
#include <iomanip>
using namespace std;


int main()
{
	int nserv = 0 , maxt, rseed, dur, s, sum=0, avg;
	double prob;
	int countout=0, remain=0, beek;
	cout << "Enter these parameters of the simulation: " << endl;
	while (nserv < 1 || nserv>10)
	{
		cout << "The number of queue/server pairs: ";
		cin >> nserv;
	}
	cout << "The probability that a customer arrives in one tick (%): ";
	cin >> prob;
	cout << "The maximum duration of a transaction in ticks: ";
	cin >> maxt;
	cout << "The duration of the simulation in ticks: ";
	cin >> dur;
	cout << "Enter a random number seed: ";
	cin >> rseed;


	///////////////////////////////////////////////////////////////////////////////
	// Generate random binary array containing p ones and 1-p zeros
	int *ran = new int[dur];
	const int nrolls = dur;
	double p = prob / 100;
	std::default_random_engine generator(rseed);
	std::bernoulli_distribution distribution(p);
	for (int j = 0; j < nrolls; j++)
	{
		ran[j] = distribution(generator);
	}
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	// Generate random array from having values from 1 to 12 for transaction time
	//int trantime[120];
	int *trantime = new int[dur];
	srand(rseed);
	for (int j = 0; j < dur; j++)
	{
		trantime[j] = (rand() % maxt) + 1;
	}
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	// Initializing array of queues
	Queue<int> *QuPtr[10];
	for (int k = 0; k < nserv; k++)
	{
		QuPtr[k] = new Queue<int>();
	}
	// Initializing array containing time left for customer on top of single queue
	int *ticktime = new int[nserv];
	for (int k = 0; k < nserv; k++)
	{
		ticktime[k] = maxt;
	}
	//////////////////////////////////////////////////////////////////////////////
	// Initializing array containing time taken to the customer to be out
	int *maxtime = new int[dur];
	for (int k = 0; k < dur; k++)
	{
		maxtime[k] = 0;
	}
	////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < dur; i++)
	{
		if (ran[i])
		{
			Queue<int> *minQ = QuPtr[1];
			for (int j = 0; j < nserv; j++)
			{
				if (QuPtr[j]->getSize() < minQ->getSize())
				{
					minQ = QuPtr[j];
				}
			}
			minQ->enqueue(i);
		} //endif (ran[i])

		for (int r = 0; r < nserv; r++)
		{
			for (int t = 1; t <= QuPtr[r]->getSize(); t++)
			{
				int tuu = QuPtr[r]->accessQu(t);
				maxtime[tuu]++;
			}
		}

		for (int u = 0; u < nserv; u++)
		{
			if (QuPtr[u]->getSize() != 0)
			{
				ticktime[u]--;
			}
			if (ticktime[u] == -1)
			{
				QuPtr[u]->dequeue(s);
				//sum += maxtime[s] - 1;
				countout++;
				QuPtr[u]->peekFront(beek);
				ticktime[u] = trantime[beek];
			}
		}

		/////////////////////////////////////////////////////////////////////
		// Printing the ouput in every tick
		cout << setw(6) << left << i+1 ;
		cout << ticktime[0] << setw(5) << right;
		QuPtr[0]->printQ();
		cout << endl;
		for (int q = 1; q < nserv; q++)
		{
			cout << setw(7) << right << ticktime[q] << setw(5) << right;
			QuPtr[q]->printQ();
			cout << endl;
		}
		cout << endl;
		///////////////////////////////////////////////////////////////////

	}
	for (int r = 0; r < nserv; r++)
	{
		for (int t = 1; t <= QuPtr[r]->getSize(); t++)
		{
			int tu2 = QuPtr[r]->accessQu(t);
			maxtime[tu2] = 0;
		}
	}
	for (int i = 0; i < nserv; i++)
	{
		remain += QuPtr[i]->getSize();
	}
	

	int maxdur = -1;
	for (int i = 0; i < dur; i++)
	{
		if (maxtime[i] > 0)
		{
			maxtime[i]--;
		}
		if (maxtime[i] > maxdur)
		{
			maxdur = maxtime[i];
		}
		sum += maxtime[i];
	}
	if (countout>0)  avg = sum / countout;
	else  avg = 0;
	cout << countout << " customers waited an average of " << avg <<" ticks" << endl;
	cout << "The longest time a customer waited was " << maxdur << " ticks" << endl;
	cout << remain << " customers remain in the line" << endl;

	// Delete all dynamic arrays
	delete[] ran;
	delete[] trantime;
}

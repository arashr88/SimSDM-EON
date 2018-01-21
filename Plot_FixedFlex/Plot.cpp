#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <thread>
#include <mutex>

#define NUMOFSEEDS 30
#define NUMOFTHREADS 3600
#define NUMOFREQUESTS 50

using namespace std;
mutex mtx;

void thread_function (string cmd) {
	mtx.lock ();
	system (cmd.c_str ());
	// cout << cmd << endl;
	mtx.unlock ();
}

int main () {
	vector<int> Core;
	double Number;
	int Seed[NUMOFSEEDS];
	static unsigned int NumofRequests = NUMOFREQUESTS;
	static string Exec = "~/Desktop/Simulator/SimSDM-EON/Sim_FixedFlex"; 
	static string Topo = "~/Desktop/Simulator/SimSDM-EON/Topology/NSF14.txt";
	thread ThreadPointer[NUMOFTHREADS];
	unsigned int cnt = 0;

	ofstream plot ("Plot.txt");

	Core.push_back (1);
	Core.push_back (4);
	Core.push_back (7);

	cout << "Input a number for seed and press enter: " << endl;
	cin >> Number; 
	srand (Number);
	for (int i = 0; i < NUMOFSEEDS; i++) {
		Seed[i] = (double) rand () / 65535;
	}

	for (unsigned int k = 0; k < Core.size (); k++) {
		for (unsigned int lambda = 100; lambda < 491; lambda = lambda + 10) {
			for (unsigned int seed = 0; seed < NUMOFSEEDS; seed++) {
				string Cmd = Exec + ' ' + Topo + ' ' + to_string (NumofRequests) + ' ' + to_string (Core[k]) + ' ' + to_string (lambda * Core[k]) + " 1 " + to_string (Seed[seed]);
				ThreadPointer[cnt] = thread (thread_function, Cmd);
				cnt ++;
			}
		} 
	}

	for (int i = 0; i < NUMOFTHREADS; i++) {
		ThreadPointer[i].join ();
	}

	plot.close ();

	return 1;
}





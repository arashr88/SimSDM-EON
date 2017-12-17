#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <thread>
#include <mutex>

#define NUMOFSEEDS 30
#define NUMOFTHREADS 900 

using namespace std;
mutex mtx;

void thread_function (string cmd) {
	mtx.lock ();
	system (cmd.c_str ());
	// cout << cmd << endl;
	// cout << "The " << cnt << " time" << endl;
	mtx.unlock ();
}

int main () {
	vector<int> Core;
	double Number;
	static unsigned int NumofRequests = 100000;
	static string Exec = "~/Desktop/Simulator/SimSDM-EON/Sim"; 
	static string Topo = "~/Desktop/Simulator/SimSDM-EON/Topology/NSF14.txt";
	thread ThreadPointer[900];
	unsigned int cnt = 0;

	ofstream plot ("Plot.txt");

	Core.push_back (1);
	Core.push_back (2);
	Core.push_back (4);

	cout << "Input a number for seed and press enter: " << endl;
	cin >> Number; 
	srand (Number);


	for (unsigned int k = 0; k < Core.size (); k++) {
		for (unsigned int seed = 0; seed < NUMOFSEEDS; seed++) {
			for (unsigned int lambda = 500; lambda < 1401; lambda = lambda + 100) {
				string Cmd = Exec + ' ' + Topo + ' ' + to_string (NumofRequests) + ' ' + to_string (Core[k]) + ' ' + to_string (lambda * Core[k]) + " 1 " + to_string ((double) rand () / 65535);
				// cout << Cmd << endl;
				ThreadPointer[cnt] = thread (thread_function, Cmd);
				cnt ++;
				// system (Cmd.c_str ());
			}
		} 
	}

	for (int i = 0; i < NUMOFTHREADS; i++) {
		ThreadPointer[i].join ();
	}

	plot.close ();

	return 1;
}





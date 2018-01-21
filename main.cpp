// #define DEBUG_test_routing_component

#include <pthread.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include "Network.h"
#include "RoutingTable.h"


using namespace std;


clock_t StartPoint, EndPoint;
int EndFlag = 0;

static void * timer_thread (void *) {
	StartPoint = clock ();
	while (1) {
		EndPoint = clock ();
		if (EndFlag == 1) {
			pthread_exit (NULL);
		}
	}
}


int main (int argc, char *argv[]) {
	pthread_t timer;
	char ResultFile[500];

	Network * network;
	Network net;
	network = &net;
	

#ifdef DEBUG_test_routing_component
	RoutingTable routinGTable (network);
#endif
	
	if (argc != 8) {
		cout << "Please input arguments in the following order: " << endl;	
		cout << "\tThe file for network topology" << endl; 
		cout << "\tThe file for results" << endl;
		cout << "\tTotal number of requests" << endl;
		cout << "\tThe number of cores" << endl;
		cout << "\tAverage arriving rate of request (Lambda)" << endl;
		cout << "\tAverage holding time (1 / Mu)" << endl;
		cout << "\tSeed for random number generation" << endl;
		cout << endl;
		exit (0);
	}

	strcpy (network->FileName, argv[1]);
	strcpy (ResultFile, argv[2]);
	network->NumofRequests = atol (argv[3]);
	network->NumofCores = atoi (argv[4]);
	network->Lambda = atof (argv[5]); 
	network->Mu = atof (argv[6]);
	srand (atof (argv[7]));
	
	pthread_create (&timer, NULL, timer_thread, NULL);

	network->init ();

	#ifdef DEBUG_test_routing_component
	vector<int> aaa;
	for (int i = 0; i < network->NumofNodes; i++) {
		cout << "No. "<< i << " Node as predecessor" << endl;
		for (int j = 0; j < network->NumofNodes; j++) {
			cout << "No. " << j << " Node as successor" << endl;
			aaa = routinGTable.get_shortest_path (i, j);		
			for (int k = 0; k < aaa.size (); k++) {
				cout << aaa[k] << ' '; 
			}
			cout << endl;
		}
	}
	#endif

	network->simulation ();
	double Erlang = network->Lambda / network->Mu;
	double BlockingProbability = (double) network->NumofFailedRequests / (double) network->NumofRequests;

	fstream fp;
	fp.open (ResultFile, fstream::app);
	string plot = to_string (network->NumofCores) + ' ' + to_string (Erlang) + ' ' + to_string (BlockingProbability) + ' ' + to_string (network->MaxNumofTransponders) + ' ' + to_string (network->AvgCoresUsed) + ' ' + to_string (network->AvgHoldingTime) + ' ' + to_string (network->AvgTranspondersUsed)+ ' ' + to_string (network->AvgGBUsed) + ' ' + to_string (network->AvgIntFrag) + ' ' + to_string (network->AvgExtFrag) + ' ' + to_string (network->AvgHybridFrag) + '\n'; 
	fp << plot;
	fp.close ();

	EndFlag = 1;
	pthread_join (timer, NULL);
	double TimeSpent = (((double)(EndPoint - StartPoint))/ CLOCKS_PER_SEC);
	cout << "Time spent in \"s\" is " << TimeSpent << endl;
	cout << "************************************************************" << endl;

	return 1;
}

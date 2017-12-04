#ifndef _NETWORK_H
#define _NETWORK_H

#include <vector>
// #include "TrafficGenerator.h"
// #include "RoutingTable.h"
#include "EventQueue.h"


#define GB 1 // Guardband
#define NumofSpectralSlots 128
#define MAX_OCCUPIED_SPECTRAL_SLOTS 16 


using namespace std;

class RoutingTable;

class Network {
	public:
		/*** Functions ***/  
		void init ();
		void simulation ();


		/*** VARIABLES ***/ 
		// Inputted Variables   
		char FileName[500];
		double Lambda, Mu;
		long long NumofRequests;
		unsigned int NumofCores;

		// Topology Variables
		unsigned int NumofNodes; 
		vector< vector<double> > NodesWeight;
		vector< vector< vector<int> > > routingTable;

		// Timer and counters 
		long long RequestCounter;
		long long NumofAllocatedRequests;
		long long NumofDoneRequests;
		long long NumofFailedRequests;
		long long NumofTransponders;
		long long MaxNumofTransponders;
		double SystemClock;

		// Resource Variables
		vector< vector< vector< vector<bool> > > > SpectralSlots;

		vector<int> BlockedRequests;
		
		
	private:
};

#endif

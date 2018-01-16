#ifndef _NETWORK_H
#define _NETWORK_H

#include <vector>
// #include "TrafficGenerator.h"
// #include "RoutingTable.h"
#include "EventQueue.h"


#define GB 1 // Guardband
#define NumofSpectralSlots 128
#define MAX_DATASIZE_REQUEST 200 
#define BW_SPECSLOT 12.5

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

		// Metrics per Request
		double TotalHoldingTime;
		long long TotalTranspondersUsed;
		long long TotalCoresUsed;
		long long TotalGBUsed;
		double AvgHoldingTime;
		double AvgTranspondersUsed;
		double AvgGBUsed;
		double AvgCoresUsed;	


		// Metrics to Measure Fregmentation 
		long long TotalDataSize;
		long long TotalSSUsed;
		long long TotalSGsOccupied;

		double AvgIntFrag;
		double AvgExtFrag;
		double AvgHybridFrag;

		// Timer and counters 
		long long RequestCounter; // Generated Number of Requests
		long long NumofAllocatedRequests;
		long long NumofDoneRequests; // Requests which are successfully allocated and released, or blocked will be considered as DoneRequests
		long long NumofFailedRequests; // Number of Requests that are blocked
		long long NumofTransponders; // Number of TranspondersUsed at a Specific Time
		long long MaxNumofTransponders; // For one time simulation, Maximum Number of Transponders Used Simultaneously
		double SystemClock;

		// Resource Variables
		vector< vector< vector< vector<bool> > > > SpectralSlots;

		// Debugging Variables
		vector<int> BlockedRequests;
		
		
	private:
};

#endif

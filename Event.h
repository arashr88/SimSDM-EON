#ifndef _EVENT_H
#define _EVENT_H


#include <iostream>
#include <vector>


using namespace std;

enum Event_t {c_Request, c_Release};

class Event {
	public:
	Event () {}
	~Event () {}

	// unsigned int EventID;
	double EventTime;
	long long EventID;
	Event_t EventType;

	private:
};


class CircuitRequest : public Event {
	public:
		CircuitRequest (unsigned int src, unsigned int dest, double startTime, double duration, unsigned int OccupiedSpectralSlots, long long eventID); 
		~CircuitRequest () {}
		unsigned int Src;
		unsigned int Dest;
		double StartTime;
		double Duration;
		unsigned int OccupiedSpectralSlots; // Only stores head slot and tail slot
};


class CircuitRelease : public Event {
	public:
		CircuitRelease (long long eventID, vector<int> & circuitRoute, vector<int> & occupiedSpectralSection, double releaseTime, unsigned int core);
		~CircuitRelease () {}
		// unsigned int CircuitID;
		vector<int> CircuitRoute;
		vector<int> OccupiedSpectralSection; // Only stores head slot and tail slot
		double ReleaseTime;
		unsigned int Core;
	
};

#endif

#ifndef _MODULATIONFORMAT_H
#define _MODULATIONFORMAT_H

#include "Event.h"
#include "Network.h"

enum MF_t {BPSK, QPSK, QAM8, QAM16};

class ModulationFormats {
	public:
		ModulationFormats (CircuitRequest * cr, Network * net) {request = cr; network = net;}
		~ModulationFormats () {}

		string mf_chosen (vector<int> & shortestPath, unsigned int * occupiedSpectralSlots, unsigned int * dataSize);

		MF_t m_Format;
	private:
		unsigned int spectralslots_computation (unsigned int BitsPerSymbol, unsigned int bm_SpectralSlots);
		unsigned int datasize_computation (unsigned int BitsPerSymbol, unsigned int bm_DataSize);
		double search_link_weight (unsigned int predecessor, unsigned int successor);
		CircuitRequest * request; 
		Network * network;
};

#endif

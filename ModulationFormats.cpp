#include <iostream>
#include <string>
#include "ModulationFormats.h"

using namespace std;

/****************************************
 * Modulation Format VS Reachability:
 * BPSK:       5000km   1bit/symbol
 * QPSK:       2500km   2bits/symbol
 * 8QAM:       1250km   3bits/symbol
 * 16QAM:       625km   4bits/symbol
 ****************************************/


unsigned int ModulationFormats::spectralslots_computation (unsigned int BitsPerSymbol, unsigned int bm_SpectralSlots) {
	unsigned int SpectralSlots;
	// "bm" means before modulation
	if (bm_SpectralSlots % BitsPerSymbol != 0) {
		SpectralSlots = bm_SpectralSlots / BitsPerSymbol + 1;	
	}
	else SpectralSlots = bm_SpectralSlots / BitsPerSymbol;

	return SpectralSlots;
}


double ModulationFormats::search_link_weight (unsigned int predecessor, unsigned int successor) {
	return network->NodesWeight[predecessor][successor];
}



string ModulationFormats::mf_chosen (vector<int> & shortestPath, unsigned int * occupiedSpectralSlots) {
	double MaxDist = 0; 
	double Dist = 0;
	unsigned int am_SpectralSlots;
	string MF;


	for (int i = 1; i < shortestPath.size (); i++) {
		Dist = search_link_weight (shortestPath[i - 1], shortestPath[i]);
		if (MaxDist <= Dist) {
			MaxDist = Dist;	
		}
	}

	if (MaxDist > 2500 && MaxDist <= 5000) {
		m_Format = BPSK;
		am_SpectralSlots = spectralslots_computation (1, *occupiedSpectralSlots);
		MF = "BPSK";
	}
	else if (MaxDist > 1250 && MaxDist <= 2500) {
		m_Format = QPSK;
		am_SpectralSlots = spectralslots_computation (2, *occupiedSpectralSlots);
		MF = "QPSK";
	}
	// else if (MaxDist > 1000 && MaxDist <= 3000) {
	// 	m_Format = DP_QPSK;
	// 	MF = "DP_QPSK";
	// 	am_SpectralSlots = spectralslots_computation (4, *occupiedSpectralSlots);
	// }
	else if (MaxDist > 625 && MaxDist <= 1250) {
		m_Format = QAM8;
		am_SpectralSlots = spectralslots_computation (3, *occupiedSpectralSlots);
		MF = "8QAM";
	}
	else if (MaxDist <= 625) {
		m_Format = QAM16;
		am_SpectralSlots = spectralslots_computation (4, *occupiedSpectralSlots);
		MF = "16QAM";
	}
	// else if (MaxDist > 650 && MaxDist <= 1000) {
	// 	m_Format = DP_8QAM;
	// 	MF = "DP_8QAM";
	// 	am_SpectralSlots = spectralslots_computation (6, *occupiedSpectralSlots);
	// }
	// else if (MaxDist <= 650) {
	// 	m_Format = DP_16QAM;
	// 	MF = "DP_16QAM";
	// 	am_SpectralSlots = spectralslots_computation (8, *occupiedSpectralSlots);
	// }

	// To add 1 for guard band
	*occupiedSpectralSlots = am_SpectralSlots;
	return MF;
}

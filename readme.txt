**************************************************
* Simulator of SDM-EON
* Author: Yue Wang
* Version: 1.1
**************************************************


**************************************************
Global instruction:
1. When compile:
	a. Make sure in Network.cpp, choosing right header of ResourceAssignment
	b. Make sure using right makefile
	c. Make sure in Plot.cpp, choosing right executable of Sim
**************************************************


**************************************************
Version 1.0:
1. Time slot did not considered.
2. First-fit applied.
3. Core continuity constraint applied.
4. Spectral Slot continuity constraint applied.
5. Spectral Slot contiguity constraint applied.
6. Unicast applied.



Version 1.1:
1. Time slot did not considered.
2. First-fit applied.
3. Core continuity constraint applied.
4. Spectral Slot continuity constraint applied.

5. /* Modified from Version 1.0 */
	a. Flex-grid SDM allocation scheme applied
	b. Fully flexible allocation scheme applied
	c. Isolated Core SDM allocation scheme applied 

6. Unicast applied.



Version 1.2:
1. Time slot did not considered.
2. First-fit applied.
3. Core continuity constraint applied.
4. Spectral Slot continuity constraint applied.

5. Allocation Schemes:
	a. Flex-grid SDM allocation scheme implemented. 
	b. Fully Flexible allocation scheme implemented. 
	c. Isolated Core SDM allocation scheme implemented.

	/* Modified from Version 1.1*/
	d. Isolated Core SDM without contiguity constraint applied  alloction scheme implemented.
	e. Fixed Flexible without contiguity constraint alloction scheme implemented.

6. Unicast applied.

7. Metrics Measured /* Modified from Version 1.1 */ 
	a. Tranponders Used per Request
	b. Cores Used per Request
	c. Guardbands Used per Request
	d. HoldingTime per Request
	e. Average Internal Fragmentation
	f. Average External Fragmentation
	g. Average Hybrid Fragmentaion
**************************************************


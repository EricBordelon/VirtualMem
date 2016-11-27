//This is my current solution. Obviously it is still unfinished.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

const int TLB_S = 16;
const int FRAME_S = 256;
const int MEM_S = 256;

struct tlb_entry
{
public:
	unsigned long p_num;
	int f_num;
	int uses;
};

int main()
{
	string input;
	tlb_entry buffer[TLB_S];
	vector<bitset<32>> a;
	int p_table[MEM_S];
	//Need something to represent phys. memory
	
	for (int i = 0; i < MEM_S; i++)
		p_table[i] = -1;

	cout << "This program reads in virtual addresses and translates them into physical"
		<< " addresses to find data in memory." << endl;

	cout << "Please enter the name of the file to read addresses from: ";
	cin >> input;
	cout << endl;

	//
	//Open file and read bits into 'a'
	//Close file
	//

	bitset<32> bitAddress;
	bitset<32> bitOffset;
	unsigned long address, offset;
	
	int frame;
	
	for (size_t i = 0; i < a.size; ++i)
	{
		bitAddress = a[i];
		bitAddress <<= 16;

		bitOffset = bitAddress << 8;
		bitOffset >>= 24;

		bitAddress >>= 24;
		address = bitAddress.to_ulong();
		offset = bitOffset.to_ulong();

		int j = 0;
		bool found = false;
		while (!found && j < TLB_S)
		{
			if (address == buffer[j].p_num)
			{
				frame = buffer[j].f_num;
				found = true;
			}
			++j;
		}

		if (!found)
		{
			frame = p_table[address];
			if (frame == -1)
			{
				//page frame has not yet been loaded
				//open storage and read frame into memory

				//don't forget to update page table
			}
		
		}

		//Now that we have the frame number and the offset,
		// we can read that byte in memory
		
		//Read at (frame * frame_size) + offset and output
		// to file
	}

	//I'll also need a TLB-hit rate counter and a page-fault counter
	return 0;
}

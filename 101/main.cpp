#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef vector<int> Blocks;
int g_num_of_block;
Blocks* g_buffer;

void DisplayAllBlocks(vector<Blocks>& g_block_slot)
{
	for(int i = 0; i < g_num_of_block; ++i)
	{
		cout << i << ':';
		if(g_block_slot[i].empty())
		{
			cout << std::endl;
			continue;
		}
		int times = g_block_slot[i].size();
		for(int j = 0; j < times; ++j)
		{
			cout << ' ' << g_block_slot[i].operator[](j);
		}
		cout << std::endl;
	}
}

void ReturnBlock(int slot, int index, vector<Blocks>& g_block_slot)
{
	Blocks* bp(&g_block_slot[slot]);
	int after(0);
	for(; after < bp->size(); ++after)
		if((*bp)[after] == index) break;
	unsigned int times = bp->size() - after;
	for(int i = 1; i < times; ++i)
		g_block_slot[(*bp)[i + after]].push_back((*bp)[i + after]);
	for(int i = 1; i < times; ++i)
		g_block_slot[slot].pop_back();
}

int FindSlot(int index, vector<Blocks>& g_block_slot)
{
	int slot(-1);
	for(int i = 0; i < g_block_slot.size(); ++i)
	{
		for(int j = 0; j < g_block_slot[i].size(); ++j)
			if(index == g_block_slot[i][j])
			{
				return i;
			}
	}
	return slot;
}

void HandleCommand(string& first_command, string& second_command, int first_target, int second_target, vector<Blocks>& g_block_slot)
{
	if(first_target >= g_num_of_block || second_target >= g_num_of_block || first_target < 0 || second_target < 0)
		return;
	if(first_target == second_target)
		return;

	int first_slot(FindSlot(first_target, g_block_slot));
	int second_slot(FindSlot(second_target, g_block_slot));

	if(first_slot == second_slot)
		return;

	Blocks* ss(&g_block_slot[first_slot]);
	Blocks* ts(&g_block_slot[second_slot]);
	

	if(first_command == "move")
	{
		ReturnBlock(first_slot, first_target, g_block_slot);
		if(second_command == "over")
			ts->push_back(first_target);
		else // onto
		{
			ReturnBlock(second_slot, second_target, g_block_slot);
			ts->push_back(first_target);
		}
		ss->pop_back();
	}
	else // pile
	{
		int after(std::find((ss)->begin(), (ss)->end(), first_target) - (ss)->begin());
		int size(ss->size());
		for(int i = after; i < size; ++i)
			g_buffer->push_back(ss->operator[](i));

		for(int i = after; i < size; ++i)
			ss->pop_back();

		int times = g_buffer->size();

		if(second_command == "over")
		{	
			for(int i = 0; i < times; ++i)
				ts->push_back((*g_buffer)[i]);

		}
		else // onto
		{
			ReturnBlock(second_slot, second_target, g_block_slot);
			for(int i = 0; i < times; ++i)
				ts->push_back((*g_buffer)[i]);
		}
		g_buffer->clear();
	}
}


int main()
{
	g_buffer = new Blocks();
	cin >> g_num_of_block;
	vector<Blocks> g_block_slot(g_num_of_block);
	for(int i = 0; i < g_num_of_block; ++i)
		if(i < g_num_of_block)
			g_block_slot[i].push_back(i);
	string first_command, second_command;
	int first_target, second_target;
	while (cin >> first_command)
	{
		if(first_command[0] == 'q')
		{
			DisplayAllBlocks(g_block_slot);
			break;
		}
		cin >> first_target >> second_command >> second_target;
		HandleCommand(first_command, second_command, first_target, second_target, g_block_slot);
	}
	return 0;
}

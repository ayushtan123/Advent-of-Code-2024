/*
Part 1 (brute force solution, takes about 20 seconds to compute):
- First, we convert the input into pairs, representing the used and unused space.
- Then, we convert the pairs into data blocks.
- Then, we iteratively move the last data block to the first empty space until
  all data blocks are moved.
- Finally, we calculate the checksum of the blocks.

Part 2 (pretty fast, < 1 second):
- First, we convert the input into pairs, representing the used and unused space.
- Then, we convert the pairs into data blocks.
- Then, we iteratively move the last data block to the first empty space until 
  all data blocks are moved.
  - This step is complicated by the fact that we need to first find the first 
    contiguous free space of the given size, and then move the file to the 
    first empty space.
- Finally, we calculate the checksum of the blocks.
*/
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

string readFile( string& filename) {
    ifstream file(filename);
    return string((istreambuf_iterator<char>(file)),
                       istreambuf_iterator<char>());
}

// Converts the inputs into pairs, representing the used and unused space.
vector<pair<int, int>> parseStrToPairs( string& input) {
    vector<pair<int, int>> pairs;
    pair<int, int> pair;
    
    for (size_t i = 0; i < input.length(); i++) {
        int num = input[i] - '0';
        if (i % 2 == 0) {
            pair.first = num;
            if (i == input.length() - 1) {
                pair.second = 0;
                pairs.push_back(pair);
            }
        } else {
            pair.second = num;
            pairs.push_back(pair);
        }
    }
    return pairs;
}

// Assigns the pairs into data blocks. Empty space is represented by -1.
vector<vector<int>> pairsToBlocks( vector<pair<int, int>>& pairs) {
    vector<vector<int>> blocks;
    for (size_t i = 0; i < pairs.size(); i++) {
        vector<int> block;
        for (int j = 0; j < pairs[i].first; j++) {
            block.push_back(i);
        }
        for (int j = 0; j < pairs[i].second; j++) {
            block.push_back(-1);
        }
        blocks.push_back(block);
    }
    return blocks;
}

// Converts the input into a single vector of blocks.
vector<int> expandIntoBlocks( string& input) {
    auto pairs = parseStrToPairs(input);
    auto blocks = pairsToBlocks(pairs);
    
    vector<int> result;
    for ( auto& block : blocks) {
        result.insert(result.end(), block.begin(), block.end());
    }
    return result;
}

// Moves last data block to the first empty space.
vector<int> moveOneBlock( vector<int>& blocks) {
    vector<int> newBlocks(blocks.begin(), blocks.end() - 1);
    auto it = find(newBlocks.begin(), newBlocks.end(), -1);
    if (it != newBlocks.end()) {
        *it = blocks.back();
    }
    return newBlocks;
}

// Calculates the checksum of the blocks. It's important to use unsigned long long
// to avoid overflow.
unsigned long long checksum( vector<int>& blocks) {
    unsigned long long sum = 0;
    for (size_t i = 0; i < blocks.size(); i++) {
        sum += (unsigned long long)blocks[i] * i;
    }
    return sum;
}

// Finds the start and end index of the contiguous file of the given value.
pair<size_t, size_t> findContiguousFile( vector<int>& blocks, int value) {
    size_t start_idx = 0;
    size_t end_idx = 0;
    bool found_start = false;
    
    for (size_t i = 0; i < blocks.size(); i++) {
        if (blocks[i] == value) {
            if (!found_start) {
                start_idx = i;
                found_start = true;
            }
            end_idx = i;
        }
    }
    return {start_idx, end_idx};
}

// Changes the file to None, represented by -1.
vector<int> changeFileToNone(vector<int> blocks, int value) {
    for (auto& block : blocks) {
        if (block == value) {
            block = -1;
        }
    }
    return blocks;
}

// Finds the first contiguous free space of the given size.
size_t findFirstContiguousFreeSpace( vector<int>& blocks, size_t free_space_size) {
    size_t free_space_count = 0;
    for (size_t i = 0; i < blocks.size(); i++) {
        if (blocks[i] == -1) {
            free_space_count++;
        } else {
            free_space_count = 0;
        }
        if (free_space_count == free_space_size) {
            return i - free_space_size + 1;
        }
    }
    return blocks.size();
}

unsigned long long part1( string& input) {
    auto blocks = expandIntoBlocks(input);
    while (find(blocks.begin(), blocks.end(), -1) != blocks.end()) {
        blocks = moveOneBlock(blocks);
    }
    return checksum(blocks);
}

unsigned long long part2(string& input) {
    auto blocks = expandIntoBlocks(input);
    
    int max_value = -1;
    for (int block : blocks) {
        if (block > max_value) max_value = block;
    }
    
    for (int value = max_value; value >= 0; value--) {
        auto [start_idx, end_idx] = findContiguousFile(blocks, value);
        size_t free_space_size = end_idx - start_idx + 1;
        
        vector<int> temp_blocks(blocks.begin(), blocks.begin() + start_idx);
        size_t free_space_idx = findFirstContiguousFreeSpace(temp_blocks, free_space_size);
        
        if (free_space_idx == temp_blocks.size()) continue;
        
        blocks = changeFileToNone(blocks, value);
        for (size_t i = 0; i < free_space_size; i++) {
            blocks[free_space_idx + i] = value;
        }
    }
    
    for (auto& block : blocks) {
        if (block == -1) block = 0;
    }
    
    return checksum(blocks);
}

int main() {
    string s; cin>>s;
    cout << "part2:" << part2(s) << endl;
    return 0;
}
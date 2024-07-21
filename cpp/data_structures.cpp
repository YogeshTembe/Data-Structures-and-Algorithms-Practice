#include <iostream>
#include <vector>
using namespace std;
#define ROW_COUNT 3
#define COLUMN_COUNT 4

//normal array, vector, array, 
//set, multiset, unordered_set, unordered_multiset
//map, multimap, unordered_map, unordered_multimap
//queue, deque, priority_queue 
//list, forward_list
//stack

//study the functions on all these containers at this website = https://cplusplus.com/reference/list/list/
//algorithm library in cpp = https://cplusplus.com/reference/algorithm/

int main(){
    //Vector
    //how to create
    vector<int>nums{1,2,3,4};
    vector nums2{1,2,3,4};
    vector<int> nums3 = {1,2,3,4};
    vector<int> nums4(10,0); //(number of elements, default value)
    vector<vector<int>> matrix(ROW_COUNT,std::vector<int>(COLUMN_COUNT, 4)); // 2D vector with all values as 4
    
    //Functions on it
    return 0;
}
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <vector>
#include <algorithm>
#include "sortedList.h"

using std::vector;

template<typename T>
class hashTable {
	public:
		hashTable();
		~hashTable();
		int size() const;
		
	private:
		vector<sortedList<T> > _vt;
	
};

#endif /*_HASHTABLE_H*/

#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <vector>
#include <algorithm>
#include "sortedList.h"

using std::vector;

template<typename T>
class hashTable {
	public:
		/*default constructor/destructor  */
		hashTable();
		~hashTable();
	
		/*capacity*/
		bool empty() const;
		int size() const; //return container size

		/*modifiers*/
		void insert(T& );
		void clear();

		/*buckets*/
		int bucket(T& ) const;
		int bucket_size() const; //return sortedList size
		int bucket_count() const;
		
		/*hash policy*/
		double load_factor() const;

	private:
		vector<sortedList<T> > _vt;
		typename vector<sortedList<T> >::const_itr itr;
};

#endif /*_HASHTABLE_H*/

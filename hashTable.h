#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <vector>
#include <algorithm>
#include "sortedList.h"

using std::vector;

template<typename T, typename Hash>
class hashTable {
	public:
		/*default constructor/destructor  */
		hashTable();
		~hashTable();
	
		/*capacity*/
		bool empty() const;
		int size() const; //return container size

		/*modifiers*/
		void insert(const T& );
		void clear();

		/*buckets*/
		int bucket(T& ) const;
		int bucket_size() const; //return sortedList size
		int bucket_count() const;
		
		/*hash policy*/
		double load_factor() const;

	private:
		int bucket_num;
		vector<sortedList<T> > _vt;
		typename vector<sortedList<T> >::const_itr itr;
		Hash hashFunc;
};

template<typename T, typename Hash>
hashTable<T,Hash>::hashTable()
:bucket_num(-1){
	_vt.clear();	
}


template<typename T, typename Hash>
hashTable<T,Hash>::~hashTable(){
	bucket_num = -1;
	_vt.clear();
}

template<typename T, typename Hash>
bool hashTable<T,Hash>::empty() const{
	return _vt.empty(); //Need to check		
}

template<typename T, typename Hash>
int hashTable<T,Hash>::size() const{
	int _size = 0;
	itr = _vt.begin();
	while (itr != _vt.end()){
		_size += (*itr).size();
		itr++;
	}
	return _size;	
}

template<typename T, typename Hash>
void hashTable<T,Hash>::insert(const T& _item){
	int _pos = hashFunc(_item);	
	_vt[_pos].insert(_item);	
}

#endif /*_HASHTABLE_H*/

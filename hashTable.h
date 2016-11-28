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
	
		hashTable(int );

		/*capacity*/
		bool empty() const;
		int size() const; //return container size

		/*modifiers*/
		void insert(const T& );
		void clear();
		void erase(T );  

		/*buckets*/
		int bucket(const T& ) const;
		int bucket_size(int ) const; //return sortedList size
		int bucket_count() const;
		
		/*hash policy*/
		double load_factor() const;

		/*element access*/
		T& at (int );
		const T& at (int ) const;
		//access by key

	private:
		int bucket_num; //number of buckets
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
hashTable<T,Hash>::hashTable(int _bkt_num)
:bucket_num(_bkt_num){
	_vt.clear();
	_vt.resize(bucket_num);
}

template<typename T, typename Hash>
bool hashTable<T,Hash>::empty() const{
	return (size() == 0); 
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
	T _elem(_item);
	_vt[_pos].insert(_elem);	
}

template<typename T, typename Hash>
void hashTable<T,Hash>::clear(){
	_vt.clear();		
}

template<typename T, typename Hash>
void hashTable<T,Hash>::erase(T _item){
	_vt.at(hashFunc(_item)).remove(_item);	
    		
}

template<typename T, typename Hash>
int hashTable<T,Hash>::bucket(const T& _item) const{
	return hashFunc(_item);
}

template<typename T, typename Hash>
int hashTable<T,Hash>::bucket_size(int _bkt_num) const{
	return _vt.at(_bkt_num).size();
}

template<typename T, typename Hash>
int hashTable<T,Hash>::bucket_count() const{
	return bucket_num;
}

template<typename T, typename Hash>
double hashTable<T,Hash>::load_factor() const{
	return size()/(double) bucket_num;
}

template<typename T, typename Hash>
T& hashTable<T,Hash>::at(int ){
	
}
#endif /*_HASHTABLE_H*/

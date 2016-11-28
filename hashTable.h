#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <vector>
#include <algorithm>
#include "sortedList.h"
#include <string>

using std::vector;
using std::string;

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
		void insert(const T& , string );
		void clear();
		void erase(string );//Modified by Key  

		/*buckets*/
		int bucket(string ) const;//Find Bucket by Key
		int bucket_size(int ) const; //return sortedList size
		int bucket_count() const;
		
		/*hash policy*/
		double load_factor() const;

		/*element access*/
		sortedList<T>& at (string ) const;
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
void hashTable<T,Hash>::insert(const T& _item, string _str){
	int _pos = hashFunc(_str);	
	T _elem(_item);
	_vt[_pos].insert(_elem);	
}

template<typename T, typename Hash>
void hashTable<T,Hash>::clear(){
	_vt.clear();		
}

template<typename T, typename Hash>
void hashTable<T,Hash>::erase(string _str){
	T _temp(_str); //Create a pseudo object
	_vt.at(hashFunc(_str)).remove(_temp);		
}

template<typename T, typename Hash>
int hashTable<T,Hash>::bucket(string _str) const{
	return hashFunc(_str);
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

/*
template<typename T, typename Hash>
T& hashTable<T,Hash>::at(string _str){
	int _pos = hashFunc(_str);			
}*/

#endif /*_HASHTABLE_H*/

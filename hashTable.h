#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <vector>
#include <algorithm>
#include <string>
#include <list>

using std::vector;
using std::string;
using std::list;

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
		void insert(const T& );//must maintain sorted
		void clear();
		void erase(const T& );//Modified by Key  
		void erase(const string& );

		/*buckets*/
		int bucket(const string& ) const;//Find Bucket by Key
		int bucket_size(int ) const; //return sortedList size
		int bucket_count() const;
		
		/*hash policy*/
		double load_factor() const;

		/*element access*/

		//access by key
		list<T > find(const string& ) const;//if list return is empty than cannot find
		list<T > find(const T& ) const;
		bool canFind(const T& ) const;
		bool canFind(const string& ) const;

	private:

		int bucket_num; //number of buckets
		vector<list<T > > _vt;//lists needed to be sorted by key value`
		typename vector<list<T > >::iterator itr;	
		typename list<T >::const_iterator _itr;
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
	while (itr != _vt.end()){
		_size += (*itr).size();
		itr++;
	}
	return _size;	
}

//This function assume _item has no equivalence in hash
template<typename T, typename Hash>
void hashTable<T,Hash>::insert(const T& _item){
	//Require T to implement getKey()
	int _pos = hashFunc(_item.getKey());	
	const T _elem(_item);
	//Find Position in list and then insert
	typename list<T>::iterator _itr;
	_itr = _vt[_pos].begin();		
	if (_itr != _vt[_pos].end()){
		while(_itr != _vt[_pos].end()){
			//find the position to insert and ensure the list is sorted
			if (_elem < *_itr)
				_itr++;
		}
		//typename list<T >::iterator __temp;	
		//__temp = _itr;	
		_vt.at(_pos).insert(_itr, _elem);
	}	
	else{
		_vt.at(_pos).push_front(_elem);
	}
}

template<typename T, typename Hash>
void hashTable<T,Hash>::clear(){
	_vt.clear();		
}

template<typename T, typename Hash>
void hashTable<T,Hash>::erase(const T& _item){
	//require T to implement getKey() function
	//and remove all that satisty operator=
	_vt.at(hashFunc(_item.getKey())).remove(_item);		
}

template<typename T, typename Hash>
void hashTable<T,Hash>::erase(const string& _str){
	_itr = _vt.at(hashFunc(_str)).begin();			
	
	while(_itr!=_vt[hashFunc(_str)].end()){
		if(_str.compare((*_itr).getKey())==0){
			 const T _temp(*_itr);
			 erase(_temp);	
		}
		_itr++;
	}
}

template<typename T, typename Hash>
int hashTable<T,Hash>::bucket(const string& _str) const{
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

template<typename T, typename Hash>
list<T > hashTable<T,Hash>::find(const string& _str) const{
	int _pos = hashFunc(_str);	
	list<T> temp;
	typename list<T >::const_iterator _itr; 
	_itr = _vt[_pos].begin();	
	while(_itr!=_vt[_pos].end()){
		if(_str.compare((*_itr).getKey())==0){
			T _temp(*_itr);
			temp.push_front(_temp);	
		}
		_itr++;
	}
	return temp;
};

template<typename T, typename Hash>
list<T > hashTable<T, Hash>::find(const T& _item) const{
	int _pos = hashFunc(_item.getKey());	

	list<T > temp;

	_itr = _vt[_pos].begin();	
	while(_itr!=_vt[_pos].end()){
		if(_item == *_itr){
			T _temp(*_itr);
			temp.push_front(_temp);	
		}
		itr++;
	}

	return temp;
}

template<typename T, typename Hash>
bool hashTable<T, Hash>::canFind(const T& _item) const{
	return 	(!find(_item).empty());
}

template<typename T, typename Hash>
bool hashTable<T, Hash>::canFind(const string& _str) const{
	return (!find(_str).empty());
}

#endif /*_HASHTABLE_H*/

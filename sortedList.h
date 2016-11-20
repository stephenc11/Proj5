#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

#include <algorithm>
#include <list>

using std::list;

template<typename T>
class sortedList{
public:
	/*default constructor/destructor*/
	sortedList();
	~sortedList();

	bool empty() const;
	int size() const; 
	void insert(T& );
	void remove(T& );

	void merge(sortedList<T>&);
	void sort();

	sortedList<T>& operator= (const sortedList& );

private:
	list<T> _t_list;
	typename list<T>::iterator _itr;	
};

template<typename T>
sortedList<T>::sortedList() {}

template<typename T>
sortedList<T>::~sortedList() {}

template<typename T>
bool sortedList<T>::empty() const{
	return _t_list.empty();
}

template<typename T>
int sortedList<T>::size() const{
	return _t_list.size();
}

template<typename T>
void sortedList<T>::insert(T& item){
	_itr = _t_list.begin();
	while (!(*_itr < item)){
		_itr++;
	}
	//need to provide operator<
	_t_list.insert(_itr, item);
} //find position and insert

template<typename T>
void sortedList<T>::remove(T& item){
	//remove by value, remove nodes equal to item
	_t_list.remove(item);
}

template<typename T>
void sortedList<T>::merge(sortedList<T>& sl){
	_t_list.merge(sl._t_list);
	//need to provide operator<	
}

template<typename T>
void sortedList<T>::sort(){
	std::sort(_t_list.begin(), _t_list.end());
	//need to provide operator<
}

template<typename T>
sortedList<T>& sortedList<T>::operator=(const sortedList<T>& sl){
	_t_list = sl._t_list;
}

#endif /*_SORTEDLIST_H*/

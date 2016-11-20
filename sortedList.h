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
	void merge(sortedList& );
			
	sortedList& operator= (const sortedList& );

private:
	list<T> _t_list;
	typename list<T>::iterator _itr;	
};


#endif /*_SORTEDLIST_H*/

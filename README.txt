REGISTER
==================================================

Project for COMP2012H, 2016 Fall, HKUST

Course Registration System


AUTHOR
--------------------------------------------------

Name: CHEN, Yau Pun

SID: 20317253


COMPILATION
--------------------------------------------------

>gmake

>./Register


FILES
--------------------------------------------------

Header:

	hashTable.h
	html_utilities.h
	register_entries.h
	register_record_manager.h
	register_menu.h

Source:

	main.cpp
	register_entries.cpp
	register_record_manager.cpp
	register_menu.cpp

Makefile:

	Makefile


DESCRIPTION
---------------------------------------------------
	
	The overall design mostly follow from the sample 
executable. Make use of the Data Structure list from 
standard library and implement hashTable based on 
list and vector containers in standard library. By 
this way, the linked lists used inside the program
are always doubly linked. On the other hand, the order
of the linked lists is maintained within the programs
through the correct use of iterator, less than operators
and sort function provided for the list container in 
standard library. Hash overflow is prevented by using 
long long type for suming and further more the algebraic
properties of modulus.

	The source code architecture is as followed: the high
level codes that dealt with user input, terminal output
and FILE IO are mainly implemented in register_menu which
is reponsible for the control flow and exception handling
of the main program; the lower level codes comprises of 
hashTable which provides the data structure as required 
along with register_entries which contains necessary
registration entries like student, course, course selection
, and student or course indices for lookup; The high level
and low level codes are further supported by registration
record manager which provides both high level and low
level functions like entry existence checking, html report 
generating and database input/output.

	The hashTable design mainly mimic the API of unordered
map in standard library and also provides some other functions
that facilitate the implementation of the program. For 
example, iterator operation are mostly handled internally
and list of object copies will be return if Find()
functions are called.

	The register entries mostly comprise the information for
different entries like student, course, course selection
and also static functions for call to do input validity 
checking. Index classes are implemented with an iterator 
to record container and an key for lookup.

	The register record manager mostly manipulate the data
storage of the runtime. The register menu mostly provide
the Interface and logic flow needed for user input and output
with the help of utilities implemented as members of register 
record manager class. 






























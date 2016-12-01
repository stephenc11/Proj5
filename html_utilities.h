#include "register_entries.h"
#include <cstdio>

void printAllStuHeader(_IO_FILE* );
void printAllCrsHeader(_IO_FILE* );
void printStuHeader(_IO_FILE*, const student& );
void printCrsHeader(_IO_FILE*, const course& );
void printTailer(_IO_FILE* );


void printAllStuHeader(_IO_FILE* f){
	fprintf (f,"<HTML>\n");
	fprintf (f,"<HEAD>\n");
	fprintf (f,"<HEAD>\n");
	fprintf(f,"<TITLE>All Students List</TITLE>\n");
	fprintf(f,"</HEAD>\n");
	fprintf(f,"<BODY bgColor=#ffffcc>\n");
	fprintf(f,"<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>\n");
	fprintf(f,"<H2>All Students List</H2>\n");
	fprintf(f,"<P>\n");
}

void printAllCrsHeader(_IO_FILE* f){
	fprintf (f,"<HTML>\n");
	fprintf (f,"<HEAD>\n");
	fprintf (f,"<HEAD>\n");
	fprintf(f,"<TITLE>All Course List</TITLE>\n");
	fprintf(f,"</HEAD>\n");
	fprintf(f,"<BODY bgColor=#ffffcc>\n");
	fprintf(f,"<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>\n");
	fprintf(f,"<H2>All Course List</H2>\n");
	fprintf(f,"<P>\n");
}

void printTailer(_IO_FILE* f){
	fprintf(f,"</P>\n");
	fprintf(f,"</BODY>\n");
	fprintf(f,"</HTML>\n");
}

void printCrsHeader(_IO_FILE* f, const course& crs){
	fprintf (f,"<HTML>\n");
	fprintf (f,"<HEAD>\n");
	fprintf (f,"<HEAD>\n");
	fprintf(f,"<TITLE>Student Records for Course ");
	fprintf(f,"%s",crs.getCourseCode().c_str());
	fprintf(f,"</TITLE>\n");
	fprintf(f,"</HEAD>\n");
	fprintf(f,"<BODY bgColor=#ffffcc>\n");
	fprintf(f,"<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>\n");
	fprintf(f,"<H2>Student Records for Course: ");
	fprintf(f,"%s",crs.getCourseName().c_str());
	fprintf(f," (");
	fprintf(f,"%s",crs.getCourseCode().c_str());
	fprintf(f,")</H2>\n");
	fprintf(f,"<P>\n");
}

void printStuHeader(_IO_FILE* f, const student& stu){
	fprintf (f,"<HTML>\n");
	fprintf (f,"<HEAD>\n");
	fprintf (f,"<HEAD>\n");
	fprintf(f,"<TITLE>Course Records for Student ");
	fprintf(f,"%s",stu.getStudentID().c_str());
	fprintf(f,"</TITLE>\n");
	fprintf(f,"</HEAD>\n");
	fprintf(f,"<BODY bgColor=#ffffcc>\n");
	fprintf(f,"<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>\n");
	fprintf(f,"<H2>Student Records for Course: ");
	fprintf(f,"%s",stu.getStudentName().c_str());
	fprintf(f," (");
	fprintf(f,"%s",stu.getStudentID().c_str());
	fprintf(f,")</H2>\n");
	fprintf(f,"<P>\n");
}


/******************NODE.H CLASS TO CREATE HEADER FILE OF NODE CLASS***********************/
#ifndef Node_h
#define Node_h
#include <fstream>
using namespace std;
class Cnode
{
	//PRIVATE DATA MEMBER TO HOLDTHE DATA IN THE NODES
	int data;

public:
	//SELF REFERENTIAL POINTER TO POINT TO NEXT NODE
	Cnode *next;

	//NULL CONSTRUCTOR
	Cnode();

	//PARAMETRIC CONSTRUCTOR
	Cnode(int d);

	//PARAMETRIC CONSTRUCTOR TO READ FROM FILE
	Cnode(ifstream &inFile);

	//FUNCTION TO TAKE INPUT FROM FILE
	void readFromFile(ifstream &inFile);

	//FUNCTION TO WRITE INTO THE FILE 
	void writeToFile(ofstream &oFile);

	//FUNCTION TO GET VALUE
	int getData()const;

	//FUNCTION TO SET NODE VALUES
	Cnode &setData(int data);

	//FUNCTION TO PRINT NODES
	void print();
};
#endif

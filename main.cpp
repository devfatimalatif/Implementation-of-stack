/************************MAIN FUNCTION TO TEST THE stack CLASS***********************/
#include <iostream>
#include "Stack.h"

using namespace std;
int main()
{
	Cnode *ptr4 = new Cnode(11);
	//DRIVER TEST CODE FOR NULL CONSTRCTOR
	Cstack s;
	
	if (s.isNotEmpty())
		cout << "\nErrorInEmptyObjectConstructor" << endl;
	else
		cout << "\nEmptyObjectConstructor:OK" << endl;
	if(s.isEmpty())
	s = Cstack(ptr4);
	//DRIVER TEST CODE FOR PARAMETRIC CONSTRCTOR
	Cnode *ptr = new Cnode(2);
	Cnode *ptr3 = new Cnode(56);

	Cstack s1(ptr);
	if (s1.isEmpty())
		cout << "\nErrorInEmptyObjectParmetricConstructor" << endl;
	else
		cout << "\nEmptyObjectParametricConstructor:OK" << endl;


	//DRIVER TEST CODE FOR IS EMPTY FUNCTION
	if (s.isEmpty())
		cout << "\nObjectIsEmptyFunction:OK" << endl;
	else
		cout << "\nErrorInObjectIsEmptyfunction" << endl;


	//DRIVER TEST CODE FOR IS NOT EMPTY FUNCTION
	if (s.isNotEmpty())
		cout << "\nObjectIsNotEmptyFunction:OK" << endl;
	else
		cout << "\nErrorInObjectIsNotEmptyfunction" << endl;


	
	//DRIVER TEST CODE FOR FILE CONSTRUCTOR
	ifstream input;
	ofstream output;
	input.open("cin.bin", ios::binary | ios::in);
	output.open("cout.bin", ios::binary | ios::in);
	if (!input.is_open() && !output.is_open())
	{
		cout << "\nCnode::Constructor:InputFileNotOpen!" << endl;
		cout << "\nCnode::Constructor:OutputFileNotOpen!" << endl;
		exit(1);
	}
	else
	{
		Cstack st(input);
		st.writeToFile(output);
		int siz = output.tellp();
		if (siz == 0)
			cout << "\nErrorInObjectFileConstructor" << endl;
		else
			cout << "\nObjectFileConstructor:OK" << endl;

		//DRIVER TEST CODE WRITE TO FILE
		if (sizeof(output))
			cout << "\nObjectWriteToFileFunction:OK" << endl;
		else
			cout << "\nErrorInObjectWriteToFileFunction" << endl;

		//DRIVER TEST CODE FOR READ FROM FILE
		st.readFromFile(input);
		st.writeToFile(output);
		if ((sizeof(output)) >= siz)
			cout << "\nObjectReadFromFileFunction:OK" << endl;
		else
			cout << "\nErrorInObjectReadFromFileFunction" << endl;

	}
	
	//s.push(ptr);
	//DRIVER TEST CODE FOR PUSH FUNCTION
	Cnode *ptr2 = new Cnode(34);
	if (s.isNotEmpty())
	{		s.push(ptr2);
	       s.push(ptr3);
}
	if(s.isEmpty())
		cout << "\nErrorInObjectPushfunction" << endl;
	else
	cout << "\nObjectPushFunction:OK" << endl;
	Cnode *p=NULL;

	//DRIVER TEST CODE FOR POP FUNCTION
	if(s.isEmpty())
		cout <<"Stack is Empty"<< endl;
	else
	  p=s.pop();
	if(!p)
		cout << "\nErrorInObjectPopfunction" << endl;
	else
		cout << "\nObjectPopFunction:OK" << endl;

	//DRIVER TEST CODE FOR PRINT FUNCTION
	if (s.isEmpty())
	{
		cout << "Stack is empty" << endl;
		cout << "\nErrorInObjectPrintfunction" << endl;
	}
	else
	{
		cout << "\nObjectPrintFunction:OK" << endl;
		s.print();
		
	}

	//DRIVER TEST CODE COPY CONSTRUCTOR
	Cstack s2 = s1;
	if(s2.isNotEmpty())
		cout << "\nObjectCopyConstructor:OK" << endl;
	else
		cout << "\nErrorInObjectCopyConstructor" << endl;
	cout << "S2 STACK: " << endl;
	s2.print();


	//DRIVER TEST CODE FOR EQUAL OPERATOR
	bool f = false;
	if (s.isNotEmpty())
	{
		s1 = s;

		for (int i = s1.getCount(); i > 0; --i)
		{
			if (s1.pop()->getData() == s.pop()->getData())
				f = true;
		}
	}
	if(f)
	cout << "\nObjectEqualOperator:OK" << endl;
	else
		cout <<"\nErrorInObjectEqualOperator" << endl;

	//DRIVER TEST CODE FOR DESTRUCTOR
	s.~Cstack();
	if(s.isEmpty())
		cout << "\nObjectDestructor:OK" << endl;
	else
		cout << "\nErrorInObjectDestructor" << endl;
		
	system("pause");
	return 0;
}
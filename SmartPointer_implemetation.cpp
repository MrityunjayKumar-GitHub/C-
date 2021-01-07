/* Defining smart pointer */

/* The idea is to define a normal pointer inside class and overload *' and '->' operators. 
Define distroctor also to automaticallly remove the allocated pointer whrn it is not in use.

*/

#include<iostream>

using namespace std;

class SmartPtr
{
	int *ptr;  //Actual Pointer 
	
	public:
		//Define constructor
		SmartPtr(int *p)
		{
			ptr = p;
		}
	
	//Define destuctor 
	~SmartPtr()
	{
		delete(ptr);  //Deleting actual pointer
	}
	
	//Overloading * and -> operator 
	int & operator*()
	{
		return *ptr;
	}
};

int main()
{
	SmartPtr s_Ptr(new int());
	*s_Ptr = 20;

	cout<<"Smart pointer = "<<*s_Ptr<<endl;	
	
	int i = 30;
	SmartPtr s_Ptr2(&i);
	cout<<"New Pointer = "<<*s_Ptr2<<endl;
	return 0;
}

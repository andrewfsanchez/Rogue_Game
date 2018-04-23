#include "Object.h"
#include <iostream>

#ifndef NODE
#define NODE

class Node
{
public:
	Node(Object* thing);
	Node();
	Object* getObject();
	void setObject(Object* thing);
	void print();
	void deleteObject();

private:
	Object* space;

};


#endif 

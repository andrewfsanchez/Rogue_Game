
#include "node.h"


using namespace std;

Node::Node(Object* thing)
{
	space = thing;
}

Object* Node::getObject()
{
	return space;
}

void Node::setObject(Object* thing)
{
	space = thing;
}

void Node::print()
{
	if (space == NULL)
	{
		cout << " ";
		return;
	}
	cout << space->getSymbol();
}

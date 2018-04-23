
#include "Node.h"


using namespace std;

Node::Node(Object* thing)
{
	space = thing;
}
Node::Node()
{
	space = NULL;
}

Object* Node::getObject()
{
	return space;
}

void Node::setObject(Object* thing)
{
	space = thing;
}
void Node::deleteObject()
{
	space = NULL;
}

void Node::print()
{
	if (space == NULL)
	{
		cout << " . ";
		return;
	}
	cout << space->getSymbol();
}

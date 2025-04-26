#include "BABAobj.h"
#include <iostream>
using namespace std;
BabaObject::BabaObject() : Object(ObjectType::BABA)
{
}

void BabaObject::Render()
{
	cout << "B" << " ";
}

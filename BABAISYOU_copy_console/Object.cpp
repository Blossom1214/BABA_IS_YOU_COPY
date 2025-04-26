#include "Object.h"
using namespace std;
ObjectType Object::GetType() const
{
	return _type;
}

const Position& Object::GetPosition() const
{
	return _position;
}

void Object::SetPosition(const Position& pos)
{
	_position = pos;
}

void Object::AddRule(const std::string& rule)
{
	_rules.insert(rule);
}

void Object::RemoveRule(const std::string& rule)
{
	_rules.erase(rule);
}

bool Object::HasRule(const std::string& rule) const
{
	return _rules.find(rule) != _rules.end();
}
bool Object::IsNoun() const
{
	return ObjectRole(_type) == ObjectRole::NOUN;
}

bool Object::IsVerb() const
{
	return ObjectRole(_type) == ObjectRole::VERB;
}

bool Object::IsProperty() const
{
	return ObjectRole(_type) == ObjectRole::PROPERTY;
}

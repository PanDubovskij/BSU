#pragma once

class Element
{
	char value;
public:
	Element() = default;
    Element(char value) : value(value) {};
	friend std::ostream& operator<<(std::ostream& out, const Element& e)
	{
		out << e.value;
		return out;
	}
};


#include "Passenger.h"

std::istream &operator>> (std::istream &is, Passenger &qwe)
{
	is >> qwe.time >> qwe.position >> qwe.destination;
	if (!is)qwe = Passenger();
	return is;
}
bool cmp(Passenger a, Passenger b)
{
	return (a.time < b.time);
}
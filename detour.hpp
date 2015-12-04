#ifndef	__DETOUR_HPP__
#define __DETOUR_HPP__

#include <vector>
#include <utility>

/***
 ** shortDetour:	This function calculates the detour distance made by going from point A to B passing through point C then D.
 **			It also calculates the detour distance made by going from point C to D passing through point A then B
 ** parameters:		This function takes a vector fill with 4 latitude and longitude pairs.
 ** return:		This function return a pair with the two detour distance.
 ***/
std::pair<int, int>	shortDetour(std::vector<std::pair<double, double> > &pt);

#endif

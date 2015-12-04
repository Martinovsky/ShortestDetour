#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include "detour.hpp"


/***
 ** main:	This is the entry point of the program
 ** parameters:	This program needs 4 latitude and longitude pairs to work.
 **		If you don't give any, it's going to ask for the pairs.
 ***/
int	main(int argc, char * argv[])
{
  std::vector<std::pair<double, double> > arr;

  if (argc == 1)
    {
      std::cout << "Please enter the coordinate:" << std::endl;
      double lat = 0.0;
      double lon = 0.0;
      for (int i = 0; i < 4; i++)
	{
	  std::cout << "Latitude " << (char)('A' + i) << ": ";
	  std::cin >> lat; 
	  std::cout << "Longitude " << (char)('A' + i) << ": ";
	  std::cin >> lon;
	  arr.push_back(std::make_pair(lat, lon));
	  lat = 0.0;
	  lon = 0.0;
	}
    }
  else if (argc > 8)
    {
      std::stringstream ss;
      double lat = 0.0;
      double lon = 0.0;
      for (int i =1; i < 8; i+=2)
	{
	  ss.str(argv[i]);
	  ss >> lat;
	  ss.str("");
	  ss.clear();

	  ss.str(argv[i+1]);
	  ss >> lon;
	  ss.str("");
	  ss.clear();

	  arr.push_back(std::make_pair(lat, lon));
	  lat = 0.0;
	  lon = 0.0;
	}
    }
  else
    {
      std::cout << "Please provide enough values or don't provide any." << std::endl;
      return 1;
    }
  std::pair<int, int> result = shortDetour(arr);
  std::cout << "The first driver will make a detour of " << result.first / 1000 << " kilometers and " << result.first % 1000 << " meters." << std::endl;
  std::cout << "The second driver will make a detour of " << result.second / 1000 << " kilometers and " << result.second % 1000 << " meters." << std::endl;
  return 0;
}

#include <vector>
#include <utility>
#include <cmath>


/***
 ** pathDistance:	This function calculate the distance between to points.
 ** parameters:		This function takes two pair of latitude and longitude.
 ** return:		This function return the distance in meters between to points.
 ***/
static int	pathDistance(std::pair<double, double> ptA, std::pair<double, double> ptB)
{
  double rlatA = M_PI * ptA.first / 180;
  double rlonA = M_PI * ptA.second / 180;
  double rlatB = M_PI * ptB.first / 180;
  double rlonB = M_PI * ptB.second / 180;

  return (6371000 * acos( sin(rlatA) * sin(rlatB) + cos(rlatA) * cos(rlatB) * cos(rlonA - rlonB)));
}

/***
 ** shortDetour:	This function calculates the detour distance made by going from point A to B passing through point C then D.
 **			It also calculates the detour distance made by going from point C to D passing through point A then B.
 ** parameters:		This function takes a vector fill with 4 latitude and longitude pairs.
 ** return:		This function return a pair with the two detour distance.
 ***/
std::pair<int, int>	shortDetour(std::vector<std::pair<double, double> > &pt)
{
  int ab, ac, cd, db;
  int res1 = 0;
  int res2 = 0;

  ab = pathDistance(pt[0], pt[1]);
  ac = pathDistance(pt[0], pt[2]);
  cd = pathDistance(pt[2], pt[3]);
  db = pathDistance(pt[1], pt[3]);

  res1 = ac + cd + db - ab;
  res2 = ac + ab + db - cd;

  return (std::make_pair(res1, res2));
}

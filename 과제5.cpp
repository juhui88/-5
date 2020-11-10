#include <iostream>
#include <vector>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b)
	{
		x = a;
		y = b;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
};
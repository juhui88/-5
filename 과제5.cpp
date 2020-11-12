#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Point
{
	int x, y;
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
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

int ccw(Point p1, Point p2, Point p3)//외적값
{
	int s;
	s = (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
	if (s > 0)//반시계방향
		return 1;
	else if (s == 0)//일직선
		return 0;
	else //시계방향
		return -1;
}

float dist(Point a, Point b)//두점 거리 구하기
{
	return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) + ((a.getY() - b.getY()) * (a.getY() - b.getY())));
}

class Polygon
{
	vector <Point> p;
public:
	void create(int x, int y)
	{
		p.push_back(Point(x, y));
	}

	int ccwN()//오목점 개수
	{
		vector <int> c;
		int count = 0;
		for (int i = 0; i < p.size() - 2;i++)
		{
			c.push_back(ccw(p[i], p[i + 1], p[i + 2]));
		}
		c.push_back(ccw(p[p.size() - 2], p[p.size() - 1], p[0]));//p.size()-2번째부턴 i의 범위를 벗어나게 생성이 되기 때문에 따로 p.size()-2번째와 p.size()-1번째 결과값을 넣어준다
		c.push_back(ccw(p[p.size() - 1], p[0], p[1]));

		for (int i = 1; i < p.size();i++)
		{
			if (c[i - 1] != c[i]) { // 앞 숫자와 다르면 오목점이 됨 따라서 count에 1을 더해준다
				count++;
				i++; // 오목점이 발견된 후 그 다음 값은 이 전값과 무조건 다르기 때문에 i의 값을 1더해줘서 그 다음부터 비교할 수 있게 한다.
			}
		}
		return count;
	}
	float perimeter()//둘레
	{
		float length = 0;
		for (int i = 0; i < p.size() - 1; i++)
		{
			length += dist(p[i], p[i + 1]);
		}
		length += dist(p[p.size() - 1], p[0]);

		return length;
	}

	float square()//면적
	{
		float s = 0, temp1 = 0, temp2 = 0;
		for (int i = 0; i < p.size() - 1; i++)
		{
			temp1 += p[i].getX() * p[i + 1].getY();
			temp2 += p[i + 1].getX() * p[i].getY();
		}
		temp1 += p[p.size() - 1].getX() * p[0].getY();
		temp2 += p[0].getX() * p[p.size() - 1].getY();// 과제 공지에 있던 공식 활용 for문으로 마지막까진 범위가 안 되서 따로 더해줌

		s = (temp1 - temp2) * 0.5;
		if (s < 0)
			s *= -1;//temp2가 더 크다면 s가 0보다 작아질 수 있으니 바꿔줌

		return s;
	}
};


int main()
{
	int n, x, y;
	Polygon p;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		p.create(x, y);
	}

	cout << fixed;
	cout.precision(1);

	cout << p.ccwN() << endl;

	cout << p.perimeter() << endl;

	cout << p.square() << endl;

	return 0;
}



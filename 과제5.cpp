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

int ccw(Point p1, Point p2, Point p3)//������
{
	int s;
	s = (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
	if (s > 0)//�ݽð����
		return 1;
	else if (s == 0)//������
		return 0;
	else //�ð����
		return -1;
}

float dist(Point a, Point b)//���� �Ÿ� ���ϱ�
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

	int ccwN()//������ ����
	{
		vector <int> c;
		int count = 0;
		for (int i = 0; i < p.size() - 2;i++)
		{
			c.push_back(ccw(p[i], p[i + 1], p[i + 2]));
		}
		c.push_back(ccw(p[p.size() - 2], p[p.size() - 1], p[0]));//p.size()-2��°���� i�� ������ ����� ������ �Ǳ� ������ ���� p.size()-2��°�� p.size()-1��° ������� �־��ش�
		c.push_back(ccw(p[p.size() - 1], p[0], p[1]));

		for (int i = 1; i < p.size();i++)
		{
			if (c[i - 1] != c[i]) { // �� ���ڿ� �ٸ��� �������� �� ���� count�� 1�� �����ش�
				count++;
				i++; // �������� �߰ߵ� �� �� ���� ���� �� ������ ������ �ٸ��� ������ i�� ���� 1�����༭ �� �������� ���� �� �ְ� �Ѵ�.
			}
		}
		return count;
	}
	float perimeter()//�ѷ�
	{
		float length = 0;
		for (int i = 0; i < p.size() - 1; i++)
		{
			length += dist(p[i], p[i + 1]);
		}
		length += dist(p[p.size() - 1], p[0]);

		return length;
	}

	float square()//����
	{
		float s = 0, temp1 = 0, temp2 = 0;
		for (int i = 0; i < p.size() - 1; i++)
		{
			temp1 += p[i].getX() * p[i + 1].getY();
			temp2 += p[i + 1].getX() * p[i].getY();
		}
		temp1 += p[p.size() - 1].getX() * p[0].getY();
		temp2 += p[0].getX() * p[p.size() - 1].getY();// ���� ������ �ִ� ���� Ȱ�� for������ ���������� ������ �� �Ǽ� ���� ������

		s = (temp1 - temp2) * 0.5;
		if (s < 0)
			s *= -1;//temp2�� �� ũ�ٸ� s�� 0���� �۾��� �� ������ �ٲ���

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



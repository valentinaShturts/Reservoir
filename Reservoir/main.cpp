#include <iostream>
using namespace std;

class Reservoir
{
	char* name;
	char* type;
	int width;
	int length;
	int depth;
public:
	Reservoir()
	{
		name = nullptr;
		type = nullptr;
		width = 0;
		length = 0;
		depth - 0;
	}
	Reservoir(const char* n, const char* t, int w, int l, int d) : width(w), length(l), depth(d)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);

		type = new char[strlen(t) + 1];
		strcpy_s(type, strlen(t) + 1, t);
	}
	~Reservoir()
	{
		delete[] name;
		delete[] type;

		cout << "Destruct" << endl;
	}
	Reservoir(const Reservoir& other) :width(other.width), length(other.length), depth(other.depth)
	{
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);

		type = new char[strlen(other.type) + 1];
		strcpy_s(type, strlen(other.type) + 1, other.type);
	}
	void Print() const
	{
		cout << type << " " << name << endl;
		cout << "Width: " << width << endl;
		cout << "Length: " << length << endl;
		cout << "Depth: " << depth << endl << endl;
	}
	char* GetName()
	{
		return name;
	}
	char* GetType()
	{
		return type;
	}
	int GetWidth()
	{
		return width;
	}
	int GetLength()
	{
		return length;
	}
	int GetDepth()
	{
		return depth;
	}
	void SetName(const char* n)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	void SetType(const char* t)
	{
		type = new char[strlen(t) + 1];
		strcpy_s(type, strlen(t) + 1, t);
	}
	void SetWidth(int w)
	{
		width = w;
	}
	void SetLength(int l)
	{
		length = l;
	}
	void SetDepth(int d)
	{
		depth = d;
	}
};


int main()
{

}
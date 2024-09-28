#include <iostream>
using namespace std;

class Reservoir
{
	char* name;
	char* type;
	double width;
	double length;
	double depth;
public:
	Reservoir() : name(nullptr), type(nullptr), width(0), length(0), depth(0){}
	explicit Reservoir(const char* n, const char* t, double w, double l, double d) : width(w), length(l), depth(d)
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
		cout << "Name: " << name << endl;
		cout << "Type: " << type << endl;
		cout << "Width: " << width << endl;
		cout << "Length: " << length << endl;
		cout << "Depth: " << depth << endl;
		cout << "Volume: " << Volume() << endl;
		cout << "Surface area: " << SurfaceArea() << endl << endl;
	}
	double Volume() const 
	{
		double vol = width * length * depth;
		return vol;
	}
	double SurfaceArea() const 
	{
		double sur = width * length;
		return sur;
	}
	bool CheckSameType(const Reservoir& other) const 
	{
		bool isSame = strcmp(type, other.type) == 0;
		return isSame;
	}
	void AreaComparison(const Reservoir& other) const
	{
		if (CheckSameType(other) == 1)
		{
			if (this->SurfaceArea() > other.SurfaceArea()) cout << this->name << " is larger than " << other.name << endl << endl;
			else if (this->SurfaceArea() < other.SurfaceArea()) cout << other.name << " is larger than " << this->name << endl << endl;
			else { cout << "Areas are equal " << endl << endl; }
		}
		else
		{
			cout << "These reservoirs are not the same type" << endl << endl;
		}
	}

	char* GetName() const
	{
		return name;
	}
	char* GetType() const
	{
		return type;
	}
	double GetWidth() const
	{
		return width;
	}
	double GetLength() const
	{
		return length;
	}
	double GetDepth() const
	{
		return depth;
	}
	void SetName(const char* n)
	{
		delete[] name;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	void SetType(const char* t)
	{
		delete[] type;
		type = new char[strlen(t) + 1];
		strcpy_s(type, strlen(t) + 1, t);
	}
	void SetWidth(double w)
	{
		width = w;
	}
	void SetLength(double l)
	{
		length = l;
	}
	void SetDepth(double d)
	{
		depth = d;
	}
};



class ReservoirArray 
{
	Reservoir* reservoirs[10];
	int count;

public:
	ReservoirArray() : count(0) 
	{
		for (int i = 0; i < 10; i++)
		{
			reservoirs[i] = nullptr;
		}
	
	}
	~ReservoirArray() 
	{
		for (int i = 0; i < count; i++)
		{
			delete reservoirs[i];  
		}
	}
	void AddReservoir(const Reservoir& r) 
	{
		if (count < 10)  
		{
			reservoirs[count] = new Reservoir(r);
			count++;
		}
		else
		{
			cout << "Array is full, cannot add more reservoirs." << endl;
		}
	}
	void DeleteReservoir(int index) 
	{
		bool found = false;

		if (index>=0 && index<=count)
		{
			delete reservoirs[index];
			reservoirs[index] = nullptr;

			for (int i = index; i < count - 1; i++)
			{
				reservoirs[i] = reservoirs[i + 1];
			}

			count--;
			found = true;
		}

		if (!found)
		{
			cout << "Reservoir not found." << endl;
		}
	}
	void ShowAllReservoirs() const 
	{
		for (int i = 0; i < count; i++) 
		{
			cout << "Reservoir #" << i + 1 << endl;
			reservoirs[i]->Print();
		}
	}
};



int main()
{
	ReservoirArray arr;
	Reservoir r1("Lake A","Lake", 50, 80, 1600);
	Reservoir r2("Lake B", "Lake", 200, 400, 2210);
	arr.AddReservoir(r1);
	arr.AddReservoir(r2);
	r1.AreaComparison(r2);

	arr.ShowAllReservoirs();
	arr.DeleteReservoir(0);
	arr.ShowAllReservoirs();
}
#include <iostream>
#include <fstream>

using namespace std;

class Image
{
public:
	Image();
	~Image();

	void CreateImage(int tmx, int tmy);
	void SetPointImage(int x, int y, int collor);
	int GetPointImage(int x, int y);
	void ShowImage();
	void SaveToPnmImage(string filename);

private:
	class img
	{
	public:
		int* points;
		int mx;
		int my;
		img* next;
		img(int mx = int(), int my = int(), int* points = int(), img* next = nullptr)
		{
			this->mx = mx;
			this->my = my;
			this->points = points;
			this->next = next;
		}
	};
	int size_i;
	int size_j;
	int collor;
	img* head;
};

Image::Image()
{
	collor = 0;
	size_i = 0;
	size_j = 0;
	head = nullptr;
}

Image::~Image()
{
	while (size_i)
	{
		img* pic = head;
		head = head->next;
		delete pic;
		size_i -- ;
		while (size_j)
		{
			img* pic = head;
			head = head->next;
			delete pic;
			size_j--;
		}
	}
}



void Image::CreateImage(int tmx, int tmy)
{
	img* pic = new img();
	pic->mx = tmx;
	pic->my = tmy;
	pic->points = new int[tmx * tmy]{ 1 };
}

void Image::SetPointImage(int x, int y, int collor)
{
	img* pic = new img();
	pic->points[(y * pic->mx + x)] = collor;
}

int Image::GetPointImage(int x, int y)
{
	img* pic = new img();
	return pic->points[(y * pic->mx + x)];
}

void Image::ShowImage()
{
	img* pic = new img();
	for (int i = 0; i < pic->my; i++)
	{
		for (int j = 0; j < pic->mx; j++)
		{
			cout << pic->points[(i * pic->mx + j)] << " ";
			size_j++;
		}
		cout << endl;
		size_i++;
	}
}

void Image::SaveToPnmImage(string filename)
{
	img* pic = new img();
	fstream out;
	out.open(filename, fstream::out);
	out << "Picture" << endl;
	out << pic->mx << " " << pic->my << endl;

	for (int i = 0; i < pic->my; i++)
	{
		for (int j = 0; j < pic->mx; j++)
		{
			out << pic->points[i * pic->mx + j] << endl;
		}
		out << endl;
	}
	out.close();
}

int main()
{
	Image picture;
	picture.CreateImage(5, 5);
	picture.SetPointImage(3, 3, 255);
	picture.ShowImage();
}

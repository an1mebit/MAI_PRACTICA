#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Image
{
	int mx;
	int my;
	int* points;
};

void CreateImage(Image* img, int tmx, int tmy)
{
	img->mx = tmx;
	img->my = tmy;
	img->points = new int[tmx * tmy]{ 1 };
}

void SetPointImage(Image* img, int x, int y, int collor)
{
	img->points[(y * img->mx + x)] = collor;
}

int GetPointImage(Image* img, int x, int y)
{
	return img->points[(y * img->mx + x)];
}

void ShowImage(Image* img)
{
	for (int i = 0; i < img->my; i++)
	{
		for (int j = 0; j < img->mx; j++)
		{
			cout << img->points[i * img->mx + j] << " ";
		}
		cout << endl;
	}
}

void SaveToPnmFile(Image* img, string fileName)
{
	fstream out;
	out.open(fileName, fstream::out);
	out << "Picture" << endl;
	out << img->mx << " " << img->my << endl;

	for (int i = 0; i < img->my; i++)
	{
		for (int j = 0; j < img->mx; j++)
		{
			out << img->points[i * img->mx + j] << " ";
		}
		out << endl;
	}
	out.close();
}

bool TestCreateImage()
{
	Image* pic = new Image;
	CreateImage(pic, 1, 3);

	if (pic->points[0] == 0 && pic->points[2] == 0 && pic->mx == 1 && pic->my == 2)
		return true;
	return false;
}

bool TestSetPointImage()
{
	Image* pic = new Image;
	CreateImage(pic, 1, 3);
	SetPointImage(pic, 1, 0, 245);
	SetPointImage(pic, 0, 3, 255);

	if (GetPointImage(pic, 1, 0) == 245 && GetPointImage(pic, 0, 3) == 255)
		return true;
	return false;
}

bool TestGetPointImage()
{
	Image* pic = new Image;
	CreateImage(pic, 1, 3);
	pic->points[2] = 255;
	if (GetPointImage(pic, 1, 2) == 255 && GetPointImage(pic, 1, 1) == 0)
		return true;
	return false;
}

bool TestShowImage()
{
	Image* pic = new Image;
	CreateImage(pic, 1, 2);
	SetPointImage(pic, 1, 1, 255);
	GetPointImage(pic, 1, 1);
	ShowImage(pic);
	if (pic->points[1 * pic->mx + 1] == 255)
		return true;
	return false;
}

bool TestSaveToPnmFile()
{
	Image* pic = new Image;
	CreateImage(pic, 1, 2);
	SetPointImage(pic, 1, 1, 255);
	GetPointImage(pic, 1, 1);
	ShowImage(pic);
	SaveToPnmFile(pic, "Test");
	if ("Test" == NULL)
		return false;
	return true;
}

void runTest(bool (*testFunction)(), const string& testName)
{
	if (testFunction())
		cout << "Test " << testName << " - OK" << endl;
	else
		cout << "Test " << testName << " - FAIL" << endl;
}

int main()
{
	runTest(TestCreateImage, "TestCreateImage");
	runTest(TestGetPointImage, "TestGetPointImage");
	runTest(TestSetPointImage, "TestSetPointImage");
	runTest(TestShowImage, "TestShowImage");
	runTest(TestSaveToPnmFile, "TestSveToPnmFile");
}
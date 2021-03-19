#include <iostream>
#include <math.h>
using namespace std;

struct Triangle {
	float sideA[20], sideB[20], sideC[20], P[20] /*Perimeter of triangle*/, faceTriangle[20];
}T[20];

struct Rectangle {
	float sideA[20], sideB[20], faceOfRectangle[20];
}R[20];


//Reading information for Triangle.
void ReadDataTriangle(int amount) {
	for (int i = 0; i < amount; i++) {
		cout << "Triangle number " << i + 1 << " Side A -> "; cin >> T[i].sideA[i];
		cout << "Triangle number " << i + 1 << " Side B -> "; cin >> T[i].sideB[i];
		cout << "Triangle number " << i + 1 << " Side C -> "; cin >> T[i].sideC[i];
		cout << endl;
	}
}

//Reading information for Rectangle.
void ReadDataRectangle(int amount) {
	for (int i = 0; i < amount; i++) {
		cout << "Rectangle number " << i + 1 << " Side A -> "; cin >> R[i].sideA[i];
		cout << "Rectangle number " << i + 1 << " Side B -> "; cin >> R[i].sideB[i];
		cout << endl;
	}
}

//Calculating face of Triangle with Heron formula.
void Heron(int amount) {
	for (int i = 0; i < amount; i++) {
		//P = (a+b+c)/2 - Perimeter of the Triangle.
		T[i].P[i] = (T[i].sideA[i] + T[i].sideB[i] + T[i].sideC[i]) / 2;
	}
	//S = sqrt(p*(p-a)*(p-b)*(p-c)) - Formula for face.
	for (int i = 0; i < amount; i++) {
		T[i].faceTriangle[i] = sqrt(T[i].P[i] * (T[i].P[i] - T[i].sideA[i]) * (T[i].P[i] - T[i].sideB[i]) * (T[i].P[i] - T[i].sideC[i]));
	}
}

//Calculating face of Right-Anled Triangle
void RightAngled(int amount) {
	//S = (a*b)/2 - Formula for Face.
	for (int i = 0; i < amount; i++) {
		R[i].faceOfRectangle[i] = ((R[i].sideA[i]) * (R[i].sideB[i])) / 2;
	}
}

//Finding the biggest Triangle face.
void BiggestTriangleFace(int amount) {
	double max = T[0].faceTriangle[0];
	int a = 0;
	for (int i = 0; i < amount; i++) {
		if (T[i].faceTriangle[i] > max) {
			max = T[i].faceTriangle[i];
			a = i;
		}
	}
	cout << "Biggest Triangle is: " << a + 1 << " with face " << max << endl;
}

//Finding the biggest Rectangle face.
void BiggestRectangleFace(int amount) {
	double max = R[0].faceOfRectangle[0];
	int b = 0;
	for (int i = 0; i < amount; i++) {
		if (R[i].faceOfRectangle[i] > max) {
			max = R[i].faceOfRectangle[i];
			b = i;
		}
	}
	cout << "Biggest Rectangle is: " << b + 1 << " with face " << max << endl;
}

int main() {
	int amountTriangles, amountRectangles;
	cout << "Enter amount Triangles: "; cin >> amountTriangles;
	cout << "Enter amount Rectangles: "; cin >> amountRectangles;
	cout << endl;

	ReadDataTriangle(amountTriangles);

	ReadDataRectangle(amountRectangles);

	Heron(amountTriangles);

	RightAngled(amountRectangles);

	BiggestTriangleFace(amountTriangles);

	BiggestRectangleFace(amountRectangles);
}
#pragma once
#include "comm.h"
#include <vector>
#include <iostream>
#include "glut.h"
#include <cmath>

using namespace std;

int maxSize = 20;
Graph <int> graph;
int WinW, WinH, R;
vertCoord vertC[20];

const int maxn = 100;

int n = 6;
int counter;
int found;
int minsum;
int s = 0;
int a[maxn][maxn];
int m[maxn];
int minm[maxn];

Graph<int> makeGraph() {
	Graph<int>graph;
	int amountofVerts, amountofEdges, vertex, sourceVertex, targetVertex, edgeWeight;
	cout << "Введите количество вершин графа:"; cin >> amountofVerts;
	cout << "Введите количество ребер графа:"; cin >> amountofEdges;
	for (int i = 0; i < amountofVerts; ++i)
	{
		cout << "Вершина:";
		cin >> vertex;
		int* vertPtr = &vertex;
		graph.InsertVertex(*vertPtr);
	}
	for (int i = 0; i < amountofEdges; ++i)
	{
		cout << "Исходная вершина: ";
		cin >> sourceVertex;
		int* sourceVertPtr = &sourceVertex;

		cout << "Конечная вершина: ";
		cin >> targetVertex;
		int* targetVertPtr = &targetVertex;

		cout << "Вес ребра: ";
		cin >> edgeWeight;
		graph.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight);
	}
	cout << endl;
	graph.Print();
	cout << "Стартовая вершина: ";
	cin >> sourceVertex;
	graph.Search();
	return graph;
}

void setCoord(int i, int n) {
	int R_;
	int x0 = WinW / 2;
	int y0 = WinH / 2;
	if (WinW > WinH) {
		R = 5 * (WinH / 13) / n;
		R_ = WinH / 2 - R - 10;
	}
	else {
		R = 5 * (WinW / 13) / n;
		R_ = WinW / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(n);
	float y1 = R_ * cos(theta) + y0;
	float x1 = R_ * sin(theta) + x0;

	vertC[i].x = x1;
	vertC[i].y = y1;
}

void drawCircle(int x, int y, int R) {
	glColor3f(1.0, 1.0, 1.0);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; ++i) {
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; ++i) {
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawText(int num, int x1, int y1) {
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(num);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); ++j) {
		glutBitmapCharacter(font, s[j]);
	}
}

void drawVertex(int n) {
	for (int i = 0; i < n; ++i) {
		drawCircle(vertC[i].x, vertC[i].y, R);
		drawText(i + 1, vertC[i].x, vertC[i].y);
	}
}
void drawLine(int text, int x0, int y0, int x1, int y1) {
	glColor3i(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();

	drawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);
	drawDirect(x0, y0, x1, y1);
}

void drawDirect(int x0, int y0, int x1, int y1) {
	float vx = x0 - x1;
	float vy = y0 - y1;
	float s = 1.0f / sqrt(vx * vx + vy * vy);
	vx *= s;
	vy *= s;
	x1 = x1 + R * vx;
	y1 = y1 + R * vy;

	glColor3i(0, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x1 + 10 * (vx + vy), y1 + 10 * (vy - vx));
	glVertex2f(x1 + 10 * (vx - vy), y1 + 10 * (vy + vx));
	glEnd();
}

void reshape(int w, int h) {
	WinW = w;
	WinH = h;
	glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
	glutPostRedisplay();
}

void display() {
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);
	glViewport(0, 0, WinW, WinH);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	graph.DrawGraph();
	glutSwapBuffers();
}

void outputWay()
{
	if (found)
	{
		cout << "Длина пути: " << minsum << endl;
		cout << "Путь: ";
		int c = 1;
		for (int i = 1; i <= n; i++)
		{
			int j = 1;
			while ((j <= n) && (minm[j] != c))
				j++;
			cout << j << "->";
			c++;
		}
		cout << minm[1] << endl;
	}
	else
	{
		cout << "Путь не найден.";
	}
}

void inputWay(int matr[20][20])
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = matr[i][j];
		}
	}
}

void searchWay(int k)
{
	if ((counter == n) && (a[k][1] != 0) && (s + a[k][1] < minsum))
	{
		found = 1;
		minsum = s + a[k][1];
		for (int i = 1; i <= n; i++)
			minm[i] = m[i];
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if ((i != k) && (a[k][i] != 0) && (m[i] == 0) && (s + a[k][i] < minsum))
			{
				s += a[k][i];
				counter++;
				m[i] = counter;
				searchWay(i);
				m[i] = 0;
				counter--;
				s -= a[k][i];
			}
		}
	}
}

void searchWay()
{
	s = 0;
	found = 0;
	minsum = 10000;
	for (int i = 1; i <= n; i++)
		m[i] = 0;
	counter = 1;
	m[1] = counter;
	searchWay(1);
	outputWay();
}
#pragma once
#include <glut.h>
#include <iostream>
#include<vector>
#include <string>
using namespace std;
const int maxSIZE = 10;
template <class T>
class Graph {
public:
	vector<T> vertList;
	int Matrix[maxSIZE][maxSIZE];
	vector<int> labelList;
public:
	Graph();
	~Graph();
	void Print();
	bool isEmpty();
	bool isFull();
	int GetVertPos(const T& vertex);
	template<class T>
	int GetAmountVerts() { return this->vertList.size(); }
	int GetAmountEdges();
	int GetWeight(const T& vertex1, const T& vertex2);
	vector<T> GetNbrs(const T& vertex);
	void addVertex(const T&);
	void addEdge(const T& vertex1, const T& vertex2, int weight);
	void FiilLabels(T& startVertex);
	int Dijkstra(T& startVert);
	bool allVisit(bool* mass);
	void drawGraph();
};

extern int WinW;
extern int WinH;

extern Graph<char> graph;

extern int R;

struct vertCoord
{
	int x, y;
};
vertCoord vertC[maxSIZE];
template<class T>
Graph<T>::Graph() {
	for (int i = 0; i < maxSIZE; ++i) {
		for (int j = 0; j < maxSIZE; ++j) {
			this->Matrix[i][j] = 0;
		}
	}
}

template<class T>
Graph<T>::~Graph() {

}
template<class T>
void Graph<T>::Print() {
	if (!this->isEmpty()) {
		cout << "Матрица смежности графа:" << endl;
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
			cout << this->vertList[i] << " ";
			for (int j = 0; j < vertListSize; ++j) {
				cout << " ";
				if (i == j) {
					cout << "M" << "\t";
				}
				else {
					cout << this->Matrix[i][j] << "\t";
				}
			}
			cout << endl;
		}
	}
	else {
		cout << "Граф пуст" << endl;
	}
}
template <class T>
int Graph<T>::GetVertPos(const T& vertex) {
	for (int i = 0; i < this->vertList.size(); ++i) {
		if (this->vertList[i] == vertex)
			return i;
	}
	return -1;
}
template<class T>
bool Graph<T>::isEmpty() {
	if (this->vertList.size() != 0)
		return false;
	else
		return true;
}
template<class T>
bool Graph<T>::isFull() {
	return (vertList.size() == maxSIZE);
}
template<class T>
int Graph<T>::GetAmountEdges() {
	int amount = 0;
	if (!this->isEmpty()) {
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
			for (int j = 0; j < vertListSize; ++j) {
				if (this->Matrix[i][j] != 0)
					amount += 1;
			}
		}
		return amount / 2;
	}
	else
		return 0;
}
template<class T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2) {
	if (!this->isEmpty()) {
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		return Matrix[vertPos1][vertPos2];
	}
	return 0;
}
template<class T>
vector<T> Graph<T>::GetNbrs(const T& vertex) {
	std::vector<T> nbrsList;
	int pos = this->GetVertPos(vertex);
	if (pos != (-1)) {
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
			if (this->Matrix[pos][i] != 0)
				nbrsList.push_back(this->vertList[i]);
		}
	}
	return nbrsList;
}
template<class T>
void Graph<T>::addVertex(const T& vertex) {
	if (!this->isFull()) {
		this->vertList.push_back(vertex);
	}
	else {
		cout << "Граф уже заполнен. Невозможно добавить новую вершину " << endl;
		return;
	}
}
template<class T>
void Graph<T>::addEdge(const T& vertex1, const T& vertex2, int weight) {
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1)) {
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (this->Matrix[vertPos1][vertPos2] != 0) {
			cout << "Ребро между этими вершинами уже существует" << endl;
			return;
		}
		else {
			this->Matrix[vertPos1][vertPos2] = weight;
		}
	}
	else {
		cout << "Обеих вершин (или одной из них) нет в графе " << endl;
		return;
	}
}
template<class T>
void Graph<T>::FiilLabels(T& startVertex) {
	int size = this->vertList.size();
	for (int i = 0; i < size; ++i) {
		labelList.push_back(1000000);
	}
	int p = GetVertPos(startVertex);
	labelList[p] = 0;
}
template<class T>
int Graph<T>::Dijkstra(T& startVert) {

	if (GetVertPos(startVert) != -1) {

		FiilLabels(startVert);
		int p = vertList.size();
		bool* visitVert = new bool[p];

		for (int i = 0; i < vertList.size(); i++) {
			visitVert[i] = false;
		}

		T temp = startVert;
		while (!allVisit(visitVert)) {

			int cnt = 0;
			int min = 1000000;
			vector<T> sosedi = GetNbrs(temp);

			for (int i = 0; i < sosedi.size(); i++) {
				int start = labelList[GetVertPos(temp)];
				int w = GetWeight(temp, sosedi[i]);
				int v = labelList[GetVertPos(sosedi[i])];
				if (start + w < v) {
					labelList[GetVertPos(sosedi[i])] = start + w;
				}
				if (labelList[GetVertPos(sosedi[i])] < min && !visitVert[GetVertPos(sosedi[i])]) {
					min = labelList[GetVertPos(sosedi[i])];
				}
				cnt++;
			}
			if (cnt == sosedi.size()) {
				visitVert[GetVertPos(temp)] = true;
			}
			for (int i = 0; i < sosedi.size(); i++) {
				if (labelList[GetVertPos(sosedi[i])] == min) {
					temp = sosedi[i];
				}
			}
		}
		for (int i = 0; i < vertList.size(); i++) {
			if (vertList[i] != startVert) {
				cout << "Кратчайшее расстояние от " << startVert << " вершины до " << vertList[i] << " вершины =" << labelList[i] << endl;
			}
		}
		return 0;
	}
}
template <class T>
bool Graph<T>::allVisit(bool* mass) {
	for (int i = 0; i < labelList.size(); i++) {
		if (labelList[i] == 1000000) {
			return false;
		}
	}
	return true;
}

void setCoord(int i, int n)
{
	int R_;
	int x0 = WinW / 2;
	int y0 = WinH / 2;
	if (WinW > WinH)
	{
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


void drawCircle(int x, int y, int R)
{
	glColor3f(1.0, 1.0, 1.0);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}


void drawText(int nom, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(nom);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}


void drawVertex(int n)
{
	for (int i = 0; i < n; i++) {
		drawCircle(vertC[i].x, vertC[i].y, R);
		drawText(i + 1, vertC[i].x, vertC[i].y);
	}
}


void drawLine(int text, int x0, int y0, int x1, int y1)
{
	glColor3i(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
	drawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);

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


void reshape(int w, int h)
{
	WinW = w;
	WinH = h;
	glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
	glutPostRedisplay();
}


void display()
{
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);
	glViewport(0, 0, WinW, WinH);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	graph.drawGraph();

	glutSwapBuffers();
}

template<class T>
void Graph<T>::drawGraph()
{
	int n = vertList.size();
	for (int i = 0; i < n; i++)
	{
		setCoord(i, n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a = Matrix[i][j];
			if (a != 0)
			{
				drawLine(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y);
			}
		}
	}
	drawVertex(n);
}
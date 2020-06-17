#include "Graph.h"

int WinW;
int WinH;
Graph<char> graph;
int R;
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");
	graph.addVertex('1');
	graph.addVertex('2');
	graph.addVertex('3');
	graph.addVertex('4');
	graph.addVertex('5');
	graph.addVertex('6');
	graph.addEdge('1', '2', 11);
	graph.addEdge('1', '3', 21);
	graph.addEdge('2', '4', 6);
	graph.addEdge('3', '5', 3);
	graph.addEdge('3', '6', 20);
	graph.addEdge('4', '3', 8);
	graph.addEdge('4', '5', 15);
	graph.addEdge('6', '1', 7);
	graph.Print();
	cout << endl;
	char c = '1';
	graph.Dijkstra(c);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(900, 720);
	glutCreateWindow("Graph");
	WinW = glutGet(GLUT_WINDOW_WIDTH);
	WinH = glutGet(GLUT_WINDOW_HEIGHT);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
#ifndef __GS_GEOMETRIC__
#define __GS_GEOMETRIC__

typedef int GLint;
typedef float GLfloat;

class gsMathematic;
class gsFileHandler;

extern gsMathematic* mathematic;

const GLfloat planeSize = 11.f;
const GLfloat pi = 3.14159265f;
const GLfloat half_pi = 3.14159265f/2.0f;
const GLfloat pi180 = pi/180.0f;

enum AxisEnum
{
	X, Y, Z
};

class Point3D
{
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;

	Point3D(void);
	Point3D(GLfloat points[3]);
	Point3D(GLfloat _x, GLfloat _y, GLfloat _z);
	~Point3D(void);

	Point3D* copy(void);
	void makeUnitary(void);
	void print(void);

	bool isZeroVector(void);
	bool isParalel(Point3D* p);

	GLfloat magnitude(void);
	GLfloat angleTo(Point3D* p);

	void drawVertex3f(void);
	void rotate(GLfloat angle, AxisEnum axis);

	void operator +(Point3D* p);
	void operator -(Point3D* p);
	void operator *(GLfloat value);

public:
	static GLfloat dot(Point3D*, Point3D*);
	static Point3D* vector(Point3D*, Point3D*);
	static Point3D* crossProduct(Point3D*, Point3D*);
};

extern Point3D* defaultColor;

class Triangle3D
{
public:
	Point3D* a;
	Point3D* b;
	Point3D* c;
	Point3D* normal;

	Point3D* color;

	Triangle3D(void);
	Triangle3D(Point3D* _a, Point3D* _b, Point3D* _c);
	~Triangle3D(void);

	void calculateNormal(void);
	void drawTriangle(void);
	void drawTriangleLines(void);
	void print(void);

	void translate(Point3D* translation);
	void rotate(GLfloat angle, AxisEnum axis);

public:
	static Triangle3D* randomTriangle(void);
};

class Color3D
{
public:
	static Point3D* randomColor(void);
	static Point3D* getColor(GLfloat red, GLfloat green, GLfloat blue);
};

class Plane3D
{
private:
	bool wireFrame;
public:
	Point3D* a;
	Point3D* normal;

	Point3D* p1;
	Point3D* p2;

	Point3D* color;

	Plane3D(void);
	Plane3D(Point3D* _a, Point3D* _normal);
	~Plane3D(void);

	void setWireframe(bool);
	void drawPlane(void);
	void createWireframe(void);

	Point3D* parametricPoint3D(GLfloat s, GLfloat t);
};

class Sphere3D
{

};

class Cube3D
{

};

class Mesh3D
{
private:
	bool wireFrame;
	bool enableArrays;
	gsFileHandler* fileHandler;
public:
	GLint vertexesSize;
	GLint facesSize;

	Point3D* vertexes;
	Point3D* faces;
	Triangle3D* triangles;

	Mesh3D(void);
	Mesh3D(const char* fileName);
	~Mesh3D(void);

	void setWireframe(bool);
	void drawMesh(void);

	float* splitVector3(char* line);
	Point3D* readVector3(char* line);

private:
	void generateMesh();
};

#endif
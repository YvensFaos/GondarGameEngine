#ifndef __CAMERA__
#define __CAMERA__

typedef float GLfloat;
class Point3D;

class Camera
{
public:
	GLfloat walkingStepSize;
	GLfloat rotationStepSize;

	GLfloat fnear;
	GLfloat ffar;
	GLfloat ffov;

	Point3D *position;
	Point3D *lookAt;
	Point3D *up;
	Point3D *rotation;

	void logCamera(void);
	void cameraLookAt(void);
	void calculateLookAt(void);
	void initCamera(GLfloat, GLfloat, GLfloat);
	Camera(Point3D*, Point3D*, Point3D*);
	~Camera();

public:
	void left(void);
	void right(void);
	void stepBy(GLfloat);
	void foward(void);
	void back(void);
	void moveUp(void);
	void moveDown(void);
};
#endif
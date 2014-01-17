#include "gsCamera.h"

#include <stdio.h>
#include "gsIncludeOpenGL.h"
#include <math.h>

#include "gsGeometric.h"

gsCamera::gsCamera(Point3D* _position, Point3D* _lookAt, Point3D* _up)
{
	position = _position->copy();
	lookAt = _lookAt->copy();
	up = _up->copy();

	rotation = new Point3D(0.0, 0.0, 0.0);

	calculateLookAt();

	walkingStepSize = 1.0f;
	rotationStepSize = 10.0f;
}

gsCamera::~gsCamera()
{
	delete position;
	delete lookAt;
	delete up;
	delete rotation;
}

void gsCamera::calculateLookAt()
{
	GLfloat dx =  (GLfloat) sin(rotation->y * pi180);
	GLfloat dz =  (GLfloat) cos(rotation->y * pi180);
	GLfloat dy =  (GLfloat) sin(rotation->x * pi180);
	GLfloat dz2 = (GLfloat) cos(rotation->x * pi180);

	lookAt->x = position->x - dx;
	lookAt->y = position->y + dy;
	lookAt->z = position->z - dz - dz2 + 1.0f;
}

void gsCamera::logCamera()
{
	printf("position: %f %f %f\nlook at: %f %f %f\nrotation: %f %f %f\n\n", 
		position->x, position->y, position->z, 
		lookAt->x,   lookAt->y,   lookAt->z, 
		rotation->x, rotation->y, rotation->z);
}

void gsCamera::initCamera(GLfloat _near, GLfloat _far, GLfloat _fov)
{
	fnear = _near;
	ffar = _far;
	ffov = _fov;
}

void gsCamera::cameraLookAt()
{
	calculateLookAt();

	gluLookAt(
	position->x, position->y, position->z, 
	lookAt->x, lookAt->y, lookAt->z, 
	up->x, up->y, up->z);
}

void gsCamera::left()
{
	rotation->y += rotationStepSize;
}

void gsCamera::right()
{
	rotation->y -= rotationStepSize;
}

void gsCamera::stepBy(GLfloat dir)
{
	GLfloat _dx = (GLfloat) sin(rotation->y * pi180);
	GLfloat _dz = (GLfloat) cos(rotation->y * pi180);

	_dx = dir * _dx * walkingStepSize;
	_dz = dir * _dz * walkingStepSize;

	position->x += _dx;
	position->z += _dz;
}

void gsCamera::foward()
{
	stepBy(-1.0f);
}

void gsCamera::back()
{
	stepBy(1.0f);
}

void gsCamera::moveUp()
{
	position->y += (walkingStepSize/2);
}

void gsCamera::moveDown()
{
	position->y -= (walkingStepSize/2);
}
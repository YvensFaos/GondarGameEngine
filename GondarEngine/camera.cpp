#include "camera.h"

#include <stdio.h>
#include <Windows.h>
#include <GL\GLU.h>
#include <math.h>

#include "geometric.h"

Camera::Camera(Point3D* _position, Point3D* _lookAt, Point3D* _up)
{
	position = _position->copy();
	lookAt = _lookAt->copy();
	up = _up->copy();

	rotation = new Point3D(0.0, 0.0, 0.0);

	calculateLookAt();

	walkingStepSize = 1.0f;
	rotationStepSize = 10.0f;
}

Camera::~Camera()
{
	delete position;
	delete lookAt;
	delete up;
	delete rotation;
}

void Camera::calculateLookAt()
{
	GLfloat dx =  (GLfloat) sin(rotation->y * pi180);
	GLfloat dz =  (GLfloat) cos(rotation->y * pi180);
	GLfloat dy =  (GLfloat) sin(rotation->x * pi180);
	GLfloat dz2 = (GLfloat) cos(rotation->x * pi180);

	lookAt->x = position->x - dx;
	lookAt->y = position->y + dy;
	lookAt->z = position->z - dz - dz2 + 1.0f;
}

void Camera::logCamera()
{
	printf("position: %f %f %f\nlook at: %f %f %f\nrotation: %f %f %f\n\n", 
		position->x, position->y, position->z, 
		lookAt->x,   lookAt->y,   lookAt->z, 
		rotation->x, rotation->y, rotation->z);
}

void Camera::initCamera(GLfloat _near, GLfloat _far, GLfloat _fov)
{
	fnear = _near;
	ffar = _far;
	ffov = _fov;
}

void Camera::cameraLookAt()
{
	calculateLookAt();

	gluLookAt(
	position->x, position->y, position->z, 
	lookAt->x, lookAt->y, lookAt->z, 
	up->x, up->y, up->z);
}

void Camera::left()
{
	rotation->y += rotationStepSize;
}

void Camera::right()
{
	rotation->y -= rotationStepSize;
}

void Camera::stepBy(GLfloat dir)
{
	GLfloat _dx = (GLfloat) sin(rotation->y * pi180);
	GLfloat _dz = (GLfloat) cos(rotation->y * pi180);

	_dx = dir * _dx * walkingStepSize;
	_dz = dir * _dz * walkingStepSize;

	position->x += _dx;
	position->z += _dz;
}

void Camera::foward()
{
	stepBy(-1.0f);
}

void Camera::back()
{
	stepBy(1.0f);
}

void Camera::moveUp()
{
	position->y += (walkingStepSize/2);
}

void Camera::moveDown()
{
	position->y -= (walkingStepSize/2);
}
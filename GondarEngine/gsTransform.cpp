#include "gsTransform.h"


#include "gsConfig.h"
#include "gsClock.h"


void gsTransform::_init(gsVector3 pos, gsVector3 siz, gsVector3 rot, gsVector3 spd, gsVector2* texCoords, gsColor col) {
	position = pos;
	size = siz;
	rotation = rot;
	speed = spd;
	tint = col;

	if (texCoords == 0) {
		textureCoordinates[0] = gsVector2(0, 1);
		textureCoordinates[1] = gsVector2(1, 1);
		textureCoordinates[2] = gsVector2(1, 0);
		textureCoordinates[3] = gsVector2(0, 0);
	} else {
		textureCoordinates[0] = texCoords[0];
		textureCoordinates[1] = texCoords[1];
		textureCoordinates[2] = texCoords[2];
		textureCoordinates[3] = texCoords[3];
	}
}

void gsTransform::applySpeed() {
	position += speed * gsClock::getDeltaTime();
}

void gsTransform::bounceAtScreenEdges() {
	if (position.x < 0) {
		position.x = 1;
		speed.x *= -1;
	} else if (position.x + size.x > GS_RESOLUTION_X) {
		position.x = GS_RESOLUTION_X - 1 - size.x;
		speed.x *= -1;
	}

	if (position.y < 0) {
		position.y = 1;
		speed.y *= -1;
	} else if (position.y + size.y > GS_RESOLUTION_Y) {
		position.y = GS_RESOLUTION_Y - 1 - size.y;
		speed.y *= -1;
	}
}

bool gsTransform::touchedScreenEdges() {
	if (position.x < 0 || position.x + size.x > GS_RESOLUTION_X) {
		return true;
	} else if (position.y < 0 || position.y + size.y > GS_RESOLUTION_Y) {
		return true;
	} else {
		return false;
	}
}
bool gsTransform::leftTheSceen() {
	if (position.x + size.x < 0 || position.x > GS_RESOLUTION_X) {
		return true;
	} else if (position.y + size.y < 0 || position.y > GS_RESOLUTION_Y) {
		return true;
	} else {
		return false;
	}
}


void gsTransform::setTextureCoordinates(gsVector2* coords) {
	textureCoordinates[0] = coords[0];
	textureCoordinates[1] = coords[1];
	textureCoordinates[2] = coords[2];
	textureCoordinates[3] = coords[3];
}
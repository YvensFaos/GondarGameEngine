#include "gsCollisionProxy.h"


bool gsCollisionProxy::broadTest(const gsCollisionProxy& a, const gsCollisionProxy& b) {
	if (a.aabbMax.x < b.aabbMin.x) return false;
	if (a.aabbMax.y < b.aabbMin.y) return false;
	if (a.aabbMax.z < b.aabbMin.z) return false;

	if (a.aabbMin.x > b.aabbMax.x) return false;
	if (a.aabbMin.y > b.aabbMax.y) return false;
	if (a.aabbMin.z > b.aabbMax.z) return false;

	return true;
}

#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)

const gsCollisionInfo* gsCollisionProxy::narrowTest(const gsCollisionProxy& a, const gsCollisionProxy& b) {
	gsVector3 imin, imax; // intersection min and max

	// Encontrando a AABB da interseção.
	imin.x = max(a.aabbMin.x, b.aabbMin.x);
	imin.y = max(a.aabbMin.y, b.aabbMin.y);
	imin.z = max(a.aabbMin.z, b.aabbMin.z);

	imax.x = min(a.aabbMax.x, b.aabbMax.x);
	imax.y = min(a.aabbMax.y, b.aabbMax.y);
	imax.z = min(a.aabbMax.z, b.aabbMax.z);

	// Criando os 8 pontos de contato
	gsVector3 contactPoints[8];
	contactPoints[0] = gsVector3(imin.x, imin.y, imin.z);
	contactPoints[1] = gsVector3(imin.x, imin.y, imax.z);
	contactPoints[2] = gsVector3(imin.x, imax.y, imin.z);
	contactPoints[3] = gsVector3(imin.x, imax.y, imax.z);
	contactPoints[4] = gsVector3(imax.x, imin.y, imin.z);
	contactPoints[5] = gsVector3(imax.x, imin.y, imax.z);
	contactPoints[6] = gsVector3(imax.x, imax.y, imin.z);
	contactPoints[7] = gsVector3(imax.x, imax.y, imax.z);

	gsVector3 pen1, pen2, icenter;
	icenter = (imax - imin) / 2;
	//workaround to make it all 2D
	icenter.z = 5000.0f;

	// Encontrando o vetor penetração no eixo de menor interseção
	if(icenter.x < icenter.y) {
		if(icenter.x < icenter.z) {
			// x é o eixo com a interceção menor
			if (a.aabbMin.x < b.aabbMin.x) {
				pen1.x = -icenter.x;
				pen2.x = +icenter.x;
			} else {
				pen1.x = +icenter.x;
				pen2.x = -icenter.x;
			}
		} else {
			// z é o eixo com a interceção menor
			if (a.aabbMin.z < b.aabbMin.z) {
				pen1.z = -icenter.z;
				pen2.z = +icenter.z;
			} else {
				pen1.z = +icenter.z;
				pen2.z = -icenter.z;
			}
		}
	} else {
		if(icenter.y < icenter.z) {
			// y é o eixo com a interceção menor
			if (a.aabbMin.y < b.aabbMin.y) {
				pen1.y = -icenter.y;
				pen2.y = +icenter.y;
			} else {
				pen1.y = +icenter.y;
				pen2.y = -icenter.y;
			}
		} else {
			// z é o eixo com a interceção menor
			if (a.aabbMin.z < b.aabbMin.z) {
				pen1.z = -icenter.z;
				pen2.z = +icenter.z;
			} else {
				pen1.z = +icenter.z;
				pen2.z = -icenter.z;
			}
		}
	}

	// criando o relatório da colisão
	gsCollisionInfo *info = new gsCollisionInfo[2];
	info[0] = gsCollisionInfo(pen1, contactPoints);
	info[1] = gsCollisionInfo(pen2, contactPoints);

	return info;
}
#include "gsCollision.h"


#include "gsConfig.h"

void gsCollision::detectCollisions(gsArrayList<gsGameObject*>* objects) {
	gsArrayList<gsGameObject*> quadrants[4]; // ++3, -+, --, +-
	gsGameObject *g;

	float mx = GS_RESOLUTION_X / 2.0f;
	float my = GS_RESOLUTION_Y / 2.0f;

	for (int i = 0; i < objects->getSize(); i++)
	{
		g = objects->get(i);
		if (g->transform.position.x < mx) {
			if (g->transform.position.y < my) {
				quadrants[1].add(g); // upper left
			}
			if (g->transform.position.y + g->transform.size.y > mx) {
				quadrants[2].add(g);
			}
		}
		if (g->transform.position.x + g->transform.size.x > mx) {
			if (g->transform.position.y < my) {
				quadrants[0].add(g); // upper left
			}
			if (g->transform.position.y + g->transform.size.y > mx) {
				quadrants[3].add(g);
			}
		}
	}

	bruteforce(&quadrants[0]);
	bruteforce(&quadrants[1]);
	bruteforce(&quadrants[2]);
	bruteforce(&quadrants[3]);
}

void gsCollision::bruteforce(gsArrayList<gsGameObject*>* objects) {
	gsGameObject *g1, *g2;
	gsCollisionProxy p1, p2;

	for (int i = 0; i < objects->getSize(); i++)
	{
		g1 = objects->get(i);
		if (!g1->isCollident()) {
			continue;
		}

		p1 = gsCollisionProxy(g1);
		for (int j = i + 1; j < objects->getSize(); j++)
		{
			g2 = objects->get(j);
			if (!g2->isCollident()) {
				continue;
			}

			if ((g1->collisionMask & g2->collisionMask) != 0) {
				p2 = gsCollisionProxy(g2);

				if (gsCollisionProxy::broadTest(p1, p2)) {
					dispatchPair(p1, p2);
				}
			}
		}
	}
}
void gsCollision::dispatchPair(const gsCollisionProxy& p1, const gsCollisionProxy& p2) {
	const gsCollisionInfo *infos = gsCollisionProxy::narrowTest(p1, p2);
	gsGameObject *g1 = p1.object;
	gsGameObject *g2 = p2.object;

	if (g1->isSolid() && g2->isSolid()) {
		g1->transform.position += infos[0].penetration;
		g2->transform.position += infos[1].penetration;
	}

	g1->onCollision(g2, infos[0]);
	g2->onCollision(g1, infos[1]);

	delete[] infos;
}
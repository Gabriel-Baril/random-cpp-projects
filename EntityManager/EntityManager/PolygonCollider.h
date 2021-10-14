#include "Collider2D.h"

class PolygonCollider : public Collider2D
{
public:
	void collide(const PolygonCollider&) override;
	void collide(const CircleCollider&) override;
};
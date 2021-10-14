
class PolygonCollider;
class CircleCollider;
class SegmentCollider;
class CapsuleCollider;
class BoxCollider;
class AABBCollider;
class EllipseCollider;

class Collider2D
{
protected:
	bool is_static;
public:
	virtual void collide(const PolygonCollider&) = 0;
	virtual void collide(const CircleCollider&) = 0;
	virtual void collide(const SegmentCollider&) = 0;
	virtual void collide(const CapsuleCollider&) = 0;
	virtual void collide(const BoxCollider&) = 0;
	virtual void collide(const AABBCollider&) = 0;
	virtual void collide(const EllipseCollider&) = 0;
};
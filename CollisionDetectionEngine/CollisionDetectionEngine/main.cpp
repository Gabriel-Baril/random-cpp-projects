#include <iostream>
#include <string>

enum class SET_OPERATOR
{
	UNION,
	DIFFERENCE,
	SYM_DIFFERENCE,
	INTERSECTION,
	COMPLEMENT
};

enum class PRIMITIVE
{
	CUBE = 5,
	SPHERE, 
	AABB,
	CYLINDER, 
	PLANE,
	ELLIPSOID,
	CAPSULE,
	NULL_PRIM
};

enum class NODE_TYPE
{
	OPERATOR = 13,
	SHAPE
};
const char* get_operator(SET_OPERATOR op)
{
	switch (op)
	{
		case SET_OPERATOR::UNION:
			return "UNION";
			break;
		case SET_OPERATOR::DIFFERENCE:
			return "DIFFERENCE";
			break;
		case SET_OPERATOR::SYM_DIFFERENCE:
			return "SYM_DIFFERENCE";
			break;
		case SET_OPERATOR::INTERSECTION:
			return "INTERSECTION";
			break;
		case SET_OPERATOR::COMPLEMENT:
			return "COMPLEMENT";
			break;
	}
	return "UNKNOWN";
}

const char* get_primitive(PRIMITIVE prim)
{
	switch (prim)
	{
		case PRIMITIVE::CUBE:
			return "CUBE";
			break;
		case PRIMITIVE::SPHERE:
			return "SPHERE";
			break;
		case PRIMITIVE::AABB:
			return "AABB";
			break;
		case PRIMITIVE::CYLINDER:
			return "CYLINDER";
			break;
		case PRIMITIVE::PLANE:
			return "PLANE";
			break;
		case PRIMITIVE::ELLIPSOID:
			return "ELLIPSOID";
			break;
		case PRIMITIVE::CAPSULE:
			return "CAPSULE";
			break;
	}
	return "UNKNOWN";
}

const char* get_node_type(NODE_TYPE nt)
{
	switch (nt)
	{
		case NODE_TYPE::OPERATOR:
			return "OPERATOR";
			break;
		case NODE_TYPE::SHAPE:
			return "SHAPE";
			break;
	}
	return "UNKNOWN";

}

struct Vec3
{
	float x;
	float y;
	float z;

	friend std::ostream& operator<<(std::ostream& os, const Vec3& vec)
	{
		os << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]";
		return os;
	}
};

struct OperatorNode;

// Constructing Solid Geometry
struct Node
{
	NODE_TYPE type;
	Node(NODE_TYPE type) : type(type) {}

	bool contain(const Vec3& v) const;
};

struct OperatorNode : Node
{
	SET_OPERATOR oprt;
	Node* left;
	Node* right;
	OperatorNode(SET_OPERATOR oprt, Node* left, Node* right) : Node(NODE_TYPE::OPERATOR), oprt(oprt), left(left), right(right) {}
};

struct ShapeNode : Node
{
	PRIMITIVE prim;
	Vec3 translation;
	Vec3 scaling;
	Vec3 rotation;
	ShapeNode(PRIMITIVE prim, const Vec3& translation = { 0,0,0 }, const Vec3& scaling = { 1,1,1 }, const Vec3& rotation = { 0,0,0 }) :
		Node(NODE_TYPE::SHAPE),
		prim(prim),
		translation(translation),
		scaling(scaling),
		rotation(rotation) {}

	void print_transform()
	{
		std::cout << "[TRANSFORM: T" << translation << ", S" << scaling << ", R" << rotation << "]\n";
	}

	virtual bool contain(const Vec3& v) const = 0;
};

struct SphereNode : ShapeNode
{
	float radius;
	SphereNode(float radius, const Vec3& translation = { 0,0,0 }, const Vec3& scaling = { 1,1,1 }, const Vec3& rotation = { 0,0,0 }) :
		ShapeNode(PRIMITIVE::SPHERE, translation, scaling, rotation),
		radius(radius)
		{}

	bool contain(const Vec3& v) const override
	{
		//std::cout << "IN SPHERE CONTAIN(Vec3)\n";
		return (v.x - translation.x) * (v.x - translation.x) + (v.y - translation.y) * (v.y - translation.y) + (v.z - translation.z) * (v.z - translation.z) <= radius * radius;
	}
};

struct CylinderNode : ShapeNode
{
	float radius;
	float height;
	CylinderNode(float radius, float height, const Vec3& translation = { 0,0,0 }, const Vec3& scaling = { 1,1,1 }, const Vec3& rotation = { 0,0,0 }) :
		ShapeNode(PRIMITIVE::CYLINDER, translation, scaling, rotation),
		radius(radius),
		height(height)
	{}

	bool contain(const Vec3& v) const override
	{
		//std::cout << "IN CYLINDER CONTAIN(Vec3)\n";
		return (v.x - translation.x) * (v.x - translation.x) + (v.z - translation.z) * (v.z - translation.z) <= radius * radius && v.y >= (translation.y - height/2) && v.y <= (translation.y + height / 2);
	}
};

struct AABBNode : ShapeNode
{
	AABBNode(const Vec3& translation = { 0,0,0 }, const Vec3& scaling = { 1,1,1 }, const Vec3& rotation = { 0,0,0 }) :
		ShapeNode(PRIMITIVE::AABB, translation, scaling, rotation)
	{}

	bool contain(const Vec3& v) const override
	{
		return false;
	}
};


void print_CSGTree(Node* tree, unsigned tab = 0)
{
	for (unsigned i = 0; i < tab; i++)
			std::cout << '-';
	if (tree->type == NODE_TYPE::OPERATOR)
	{
		OperatorNode* op = static_cast<OperatorNode*>(tree);
		std::cout << get_operator(op->oprt) << " [" << get_node_type(op->type) << "][" << tab << "]\n";
		if(op->left)
			print_CSGTree(op->left, tab + 1);
		if(op->right)
			print_CSGTree(op->right, tab + 1);
	}
	else
	{
		ShapeNode* sn = static_cast<ShapeNode*>(tree);
		std::cout << get_primitive(sn->prim) << " [" << get_node_type(sn->type) << "][" << tab << "]";
		sn->print_transform();
	}
}

bool isCSGTreeValid(Node* tree)
{
	if (tree->type == NODE_TYPE::OPERATOR)
	{
		OperatorNode* op = static_cast<OperatorNode*>(tree);
		if (!op->left || !op->right)
			return false;
		return isCSGTreeValid(op->right) && isCSGTreeValid(op->left);
	}
	return true;
}

bool Node::contain(const Vec3& v) const
{
	if (type == NODE_TYPE::OPERATOR)
	{
		OperatorNode* op = static_cast<OperatorNode*>(const_cast<Node*>(this));
		//std::cout << get_operator(op->oprt) << '\n';
		switch (op->oprt)
		{
			case SET_OPERATOR::DIFFERENCE:
				return op->left->contain(v) && !op->right->contain(v);
			case SET_OPERATOR::INTERSECTION:
				return op->left->contain(v) && op->right->contain(v);
			case SET_OPERATOR::SYM_DIFFERENCE:
				return op->left->contain(v) ^ op->right->contain(v);
			case SET_OPERATOR::UNION:
				return op->left->contain(v) || op->right->contain(v);
		}
	}
	else
	{
		ShapeNode* sh = static_cast<ShapeNode*>(const_cast<Node*>(this));
		//std::cout << get_primitive(sh->prim) << '\n';
		return sh->contain(v);
	}
}

namespace hedron
{
	double abs(double val)
	{
		if (val < 0)
			return -val;
		return val;
	}
}

template<typename T, unsigned N>
struct Vec
{
	T value[N];
};

template<typename T, typename U, unsigned N, unsigned M>
bool point_point_bool_collision(const Vec<T, N>& p1, const Vec<U, M>& p2)
{
	if constexpr (N > M)
	{
		for (unsigned i = 0; i < M; i++)
			if (*((T*)&p1 + i) != *((U*)&p2 + i))
				return false;

		for (unsigned i = M; i < N; i++)
			if (*((T*)&p1 + i) != 0)
				return false;
	}
	else
	{
		for (unsigned i = 0; i < N; i++)
			if (*((U*)&p2 + i) != *((T*)&p1 + i))
				return false;

		for (unsigned i = N; i < M; i++)
			if (*((U*)&p2 + i) != 0)
				return false;
	}
	return true;
}

template<typename T, typename U, unsigned N, unsigned M>
bool point_point_bool_collision(const Vec<T, N>& p1, const Vec<U, M>& p2, double epsilon)
{
	if constexpr (N > M)
	{
		for (unsigned i = 0; i < M; i++)
		{
			T p1_component = *((T*)&p1 + i);
			U p2_component = *((U*)&p2 + i);
			if (hedron::abs(p1_component - p2_component) <= epsilon)
				return false;
		}
		
		for (unsigned i = M; i < N; i++)
			if (*((T*)&p1 + i) != 0)
				return false;
	}
	else
	{
		for (unsigned i = 0; i < N; i++)
		{
			if (hedron::abs(*((T*)&p1 + i) - *((U*)&p2 + i)) <= epsilon)
				return false;
		}

		for (unsigned i = N; i < M; i++)
			if (*((U*)&p2 + i) != 0)
				return false;
	}
	return true;
}

struct Plane
{
	float a;
	float b;
	float c;
	float d;

	void print_plane()
	{
		std::cout << a << "x + " << b << "y + " << c << "z + " << d;
	}
};

enum class AXIS_ALIGNMENT
{
	X, Y, Z, W
};

template<unsigned N>
struct AlignedTo
{
	AXIS_ALIGNMENT alignment;
	AlignedTo(AXIS_ALIGNMENT alignment) : alignment(alignment) {}
	unsigned get_axis_component()
	{
		return static_cast<unsigned>(alignment);
	}
};

struct DynamicAlignedTo
{
	unsigned aligned_to_component;
};

struct AlignedTorus : AlignedTo
{
	float small_radius;
	float big_radius;
	AlignedTorus(float small_radius, float big_radius) : AlignedTo{ AXIS_ALIGNMENT::X }, small_radius{ small_radius }, big_radius{ big_radius } {}
	bool contain(const Vec<float, 3>& v)
	{
		float dist = sqrt(v.value[0] * v.value[0] + v.value[1] * v.value[1] + v.value[2] * v.value[2]);
		return dist >= big_radius &&
			   dist <= big_radius + 2*small_radius &&
			   v.value[1] <= -small_radius &&
			   v.value[1] >= small_radius;
	}
};


int main()
{
	/*
	SphereNode s1 = { 3.f };
	CylinderNode s2 = { 5.f, 15.f };
	SphereNode s3 = { 1.f };
	OperatorNode op1 = { SET_OPERATOR::DIFFERENCE, &s2, &s1 };
	OperatorNode op2 = { SET_OPERATOR::UNION, &op1, &s3 };

	print_CSGTree(&op2);
	std::cout << op2.contain({5, 0, 0}) << '\n';
	*/
	//std::cout << std::boolalpha << ((double)23.5 == (float)23.5) << '\n';

	Vec<float, 4> v1 = { 23.5f, 0.2f, 10, 12 };
	Vec<float, 4> v2 = { 23.8, 0.2f, 10, 12 };
	//std::cout << point_point_bool_collision(v1, v2, 0.5);

	AlignedTo align_to_x = {AXIS_ALIGNMENT::Z};
	std::cout << align_to_x.get_axis_component() << '\n';
}


/*
bool evalutate_CSGTree(Node* tree, const Vec3& v)
{
	if (tree->type == NODE_TYPE::OPERATOR)
	{
		OperatorNode* op = static_cast<OperatorNode*>(tree);
		//std::cout << get_operator(op->oprt) << '\n';
		switch (op->oprt)
		{
			case SET_OPERATOR::DIFFERENCE:
				return evalutate_CSGTree(op->left, v) && !evalutate_CSGTree(op->right, v);
			case SET_OPERATOR::INTERSECTION:
				return evalutate_CSGTree(op->left, v) & evalutate_CSGTree(op->right, v);
			case SET_OPERATOR::SYM_DIFFERENCE:
				return evalutate_CSGTree(op->left, v) ^ evalutate_CSGTree(op->right, v);
			case SET_OPERATOR::UNION:
				return evalutate_CSGTree(op->left, v) | evalutate_CSGTree(op->right, v);
		}
	}
	else
	{
		ShapeNode* sh = static_cast<ShapeNode*>(tree);
		//std::cout << get_primitive(sh->prim) << '\n';
		return sh->contain(v);
	}
}
*/
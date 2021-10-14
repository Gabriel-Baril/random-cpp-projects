#include <iostream>
#include <string>

class IFileReader
{
	virtual void read(const std::string& filePath) = 0;
	virtual void close_file(const std::string& filePath) = 0;
};


class Shape
{
public:
	Shape(const std::string& name)
		: m_name{ name } {}

	std::string get_name()
	{
		return m_name;
	}

	virtual void render() = 0;
private:
	std::string m_name;
};

class Circle : public Shape
{
public:
	Circle(CircleRenderer* renderer, float x, float y, std::string name)
		: Shape{ name }, m_renderer{ renderer }, m_x{ x }, m_y{ y }
	{
		m_renderer->set_source(this);
	}

	void render() override
	{
		m_renderer->render();
	}
private:
	float m_x;
	float m_y;
	CircleRenderer* m_renderer;
};

class CircleRenderer
{
public:
	CircleRenderer(Circle* source)
		: m_source{ source } {}

	void set_source(Circle* source)
	{
		m_source = source;
	}

	void render()
	{
		std::cout << "Rendering circle... with name " << m_source->get_name() << std::endl;
	}
private:
	Circle* m_source;
};


class Application
{
public:
	void use_shape()
	{
		if (!m_shape) return;
		m_shape->render();
	}
private:
	Shape* m_shape;
};

int main()
{
	Circle c = Circle(12, 14, "Circle 1");
}
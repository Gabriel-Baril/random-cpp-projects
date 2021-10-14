#pragma once
#include <string>

struct Window {};
struct Time { float dt; };

class ISceneLayer {
public:
	ISceneLayer(const std::string& name) : m_name{ name } {}

	virtual void update(Window* context, Time dt) = 0;
	virtual void render(Window* context, Time dt) = 0;
	virtual void on_attach() {};
	virtual void on_detach() {};
	// virtual void on_event() {};

	inline const std::string& get_name() const { return m_name; }
private:
	std::string m_name;
};
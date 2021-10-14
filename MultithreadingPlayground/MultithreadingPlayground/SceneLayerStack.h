#pragma once

#include <vector>
#include "ISceneLayer.h"

// Wrapper class used to manage a vector of layers
class SceneLayerStack
{
public:
	SceneLayerStack();
	~SceneLayerStack();

	void push_layer(ISceneLayer* layer);
	void push_overlay(ISceneLayer* overlay);
	void pop_layer(ISceneLayer* layer);
	void pop_overlay(ISceneLayer* overlay);

	std::vector<ISceneLayer*>::iterator begin() { return m_layers.begin(); }
	std::vector<ISceneLayer*>::iterator end() { return m_layers.end(); }
	std::vector<ISceneLayer*>::reverse_iterator rbegin() { return m_layers.rbegin(); }
	std::vector<ISceneLayer*>::reverse_iterator rend() { return m_layers.rend(); }

	std::vector<ISceneLayer*>::const_iterator begin() const { return m_layers.begin(); }
	std::vector<ISceneLayer*>::const_iterator end() const { return m_layers.end(); }
	std::vector<ISceneLayer*>::const_reverse_iterator rbegin() const { return m_layers.rbegin(); }
	std::vector<ISceneLayer*>::const_reverse_iterator rend() const { return m_layers.rend(); }
private:
	std::vector<ISceneLayer*> m_layers; // We need to use a vector and not a stack because we need to reverse it and push elements in the middle
	unsigned int m_layerInsertIndex = 0;
};
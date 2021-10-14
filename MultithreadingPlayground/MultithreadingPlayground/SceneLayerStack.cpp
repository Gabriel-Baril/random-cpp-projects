#include "SceneLayerStack.h"

SceneLayerStack::SceneLayerStack()
{
}

SceneLayerStack::~SceneLayerStack()
{
	for (ISceneLayer* layer : m_layers)
	{
		delete layer;
	}
}

void SceneLayerStack::push_layer(ISceneLayer* layer)
{
	layer->on_attach();
	m_layers.emplace(m_layers.begin() + m_layerInsertIndex, layer); // Added after the last layer
	m_layerInsertIndex++;
}

void SceneLayerStack::push_overlay(ISceneLayer* overlay)
{
	overlay->on_attach();
	m_layers.emplace_back(overlay); // Added at the back of the list
}

void SceneLayerStack::pop_layer(ISceneLayer* layer)
{
	auto it = std::find(m_layers.begin(), m_layers.end(), layer);
	if (it != m_layers.end())
	{
		layer->on_detach();
		m_layers.erase(it);
		m_layerInsertIndex--;
	}
}

void SceneLayerStack::pop_overlay(ISceneLayer* overlay)
{
	auto it = std::find(m_layers.begin(), m_layers.end(), overlay);
	if (it != m_layers.end())
	{
		overlay->on_detach();
		m_layers.erase(it);
	}
}
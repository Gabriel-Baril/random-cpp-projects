#include <iostream>

#include "SceneLayerStack.h"
#include "PlayerStatLayer.h"
#include "PlayerHealthLayer.h"

int main() {
	SceneLayerStack layerStack;
	layerStack.push_layer(new PlayerStatLayer);
	layerStack.push_layer(new PlayerHealthLayer);
	for (const auto& layer : layerStack) {
		layer->update(nullptr, { 0 });
	}

	for (const auto& layer : layerStack) {
		layer->render(nullptr, { 0 });
	}
}
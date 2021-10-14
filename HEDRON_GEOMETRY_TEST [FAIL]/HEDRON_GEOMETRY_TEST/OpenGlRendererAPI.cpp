#include "OpenGlRendererAPI.h"
#include <iostream>

template<typename T>
OpenGlRendererAPI<T>::OpenGlRendererAPI()
{

}

template<typename T>
void OpenGlRendererAPI<T>::render(const PolygonData<T>& p_data)
{
	std::cout << "Rendering Polygon from opengl API\n";
}

template<typename T>
void OpenGlRendererAPI<T>::render(const CircleData<T>& p_data)
{
	std::cout << "Rendering Circle from opengl API\n";
}

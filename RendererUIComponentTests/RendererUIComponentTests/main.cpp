#include <iostream>
#include <string>

#include "TextLabel.h"
#include "TextLabelRenderer1.h"
#include "TextLabelRenderer2.h"



int main()
{
	TextLabelRenderer2* renderer = new TextLabelRenderer2;
	TextLabel label("Label_1", 200, 100);
	label.renderer = renderer;

	label.draw();

	delete renderer;
}

#ifndef COLORINDEX_H
#define COLORINDEX_H

class ColorIndex 
{
public:
		float R;
		float G;
		float B;

	ColorIndex() 
	{
		R = 0.0; G = 0.0; B = 0.0;
	}

	ColorIndex(float r, float g, float b)
	{
		R = r; G = g; B = b; 
	}
};

#endif
//:
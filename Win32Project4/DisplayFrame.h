#ifndef DISPLAYFRAME_H
#define DISPLAYFRAME_H

#include "DisplayFrame.h"
#include "Configuration.h"

// Generator dialog

class DisplayFrame : public CFrameWnd
{

public:
	DisplayFrame(int x, int y, Configuration* config, BOOL display_type);   // standard constructor
	virtual ~DisplayFrame();
	void OnPaint();
	Bitmap* createBitmapPixels(HDC hdc, int totalFOV_width, int totalFOV_height);
	void createImage(CPaintDC & x, BOOL display_type);
	Bitmap* totalFOV_Image;
	std::vector<ChannelConfig>* channels;
	std::vector<Bitmap*> channel_images;


private:
	Configuration* config;
	BOOL display_type;
	int totalFOV_width;
	int totalFOV_height;
	int test_pattern;

	DECLARE_MESSAGE_MAP()
};

#endif

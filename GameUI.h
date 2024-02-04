#pragma once
#include "MyIncludes.h"

class cGameUI
{
public:
	cGameUI();
	~cGameUI();
	void Init();
	void Draw();
	void DrawMenuTab(MenuTab tab);

private:
	MenuTab MoveUI;
	MenuTab ShotUI;
};


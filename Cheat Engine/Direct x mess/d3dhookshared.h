#ifndef D3DHOOKSHARED_H
#define D3DHOOKSHARED_H

#include <windows.h>


#pragma pack(1)
typedef struct 
{
	char CheatEngineDir[200];
	UINT64 dxgi_present;
	UINT64 d3d9_present;
	UINT64 d3d9_reset;

	UINT64 dxgi_newpresent; //From the dll: set this to the function address in the dll
	UINT64 d3d9_newpresent;                              
	UINT64 d3d9_newreset;

	UINT64 dxgi_originalpresent; //From the dll: set this to the variable that should get the address of the original function with no hook
	UINT64 d3d9_originalpresent;   
	UINT64 d3d9_originalreset;

	int hookwnd;
	int clickedoverlay;
	int clickedx;
	int clickedy;

	DWORD lastHwnd;
	int MouseOverlayId; //set to -1 if no mouse overlayd ID is set, otherwise it contains an overlay ID to be used and rendered at the current mouse coords
	

	int OverLayHasUpdate;
	int overlaycount;

	struct _bitmap {
		int valid;
		int updatedpos;
		int updatedresource;

		int width;
		int height;
		int x;
		int y;
		float alphaBlend;
		int resourcesize;
		int resourceoffset;
	} resources[1];	
} *PD3DHookShared;
#pragma pack()


#endif
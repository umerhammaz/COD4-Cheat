#pragma once
#include "Common.hpp"
#include "Utils.hpp"

extern ID3DXFont* g_pDefaultFont;

struct Vertex_t
{
    float x, y, z, rhw;
    D3DCOLOR color;
};

namespace D3D
{
	bool AtttachHooks( HWND hWnd = nullptr );
	void DrawString( Vec2 vecPos, Color colColor, const char* szText, bool bOutlined = true,
					 bool bCenetered = false, ID3DXFont* pFont = g_pDefaultFont );
	void DrawFilledRect( Vec2 vecPos, Vec2 vecSize, Color colColor );
	void DrawRect( Vec2 vecPos, Vec2 vecSize, Color colColor );
}

#pragma once
#include "Utils.hpp"
#include "Common.hpp"

/*
*   Warning!
* 
*       Some modded servers have up to 64 players but the game is very much dead now
*   not a problem to care for atm. If it is: find sv_maxclients and read it.
*/
#define MAX_PLAYERS 32

class C_Refdef
{
public:
    uint32_t x; //0x0000
    uint32_t y; //0x0004
    uint32_t width; //0x0008
    uint32_t height; //0x000C
    Vec2 fov; //0x0010
    Vec3 origin; //0x0018
    Vec3 matrix[ 3 ]; //0x0024
    char pad_0058[ 28 ]; //0x0058
}; //Size: 0x0074

class C_Entity
{
public:
    char pad_0000[ 28 ]; //0x0000
    Vec3 origin; //0x001C
    char pad_0028[ 32 ]; //0x0028
}; //Size: 0x0048

namespace SDK
{
	void FindOffsets( );
    C_Entity* GetEntityFromIndex( int i );

    inline C_Refdef* m_pRefDef = nullptr;
}

#include "SDK.hpp"

void SDK::FindOffsets( )
{
	m_pRefDef = reinterpret_cast< C_Refdef* >( 0x00797600 );
}

C_Entity* SDK::GetEntityFromIndex( int i )
{
	// The entity list in this game is weird ...
	return reinterpret_cast< C_Entity* >( ( 0x84F2D8 + 0x1DC ) + ( i * 0x1DC ) );
}

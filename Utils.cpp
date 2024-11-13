#include "Utils.hpp"
#include "SDK.hpp"

uint8_t* Utils::FindPattern( HMODULE hHandle, const char* szPattern, const char* szMask )
{
    if ( hHandle == nullptr )
    {
        return nullptr;
    }

    MODULEINFO moduleInfo;
    if ( GetModuleInformation( GetCurrentProcess( ), hHandle, &moduleInfo, sizeof( moduleInfo ) ) )
    {
        uint8_t* pBaseAddress = static_cast< uint8_t* >( moduleInfo.lpBaseOfDll );
        size_t uModuleSize = moduleInfo.SizeOfImage;

        for ( size_t i = 0; i < uModuleSize; ++i )
        {
            bool bFound = true;
            for ( size_t j = 0; szMask[ j ] != '\0'; ++j )
            {
                if ( szMask[ j ] == 'x' && szPattern[ j ] != pBaseAddress[ i + j ] )
                {
                    bFound = false;
                    break;
                }
            }

            if ( bFound )
            {
                return pBaseAddress + i;
            }
        }
    }

    MessageBoxA( nullptr, 
                 std::format( 
                     "Failed to find pattern {} with mask {}.", 
                     szPattern,
                     szMask 
                 ).c_str( ),
                 "DX9-Cheat-Base",
                 MB_OK | MB_ICONERROR );

    return nullptr;
}

bool Utils::WorldToScreen( const Vec3& vecWorld, Vec2& vecScreen )
{
    const Vec3 vecPos = vecWorld - SDK::m_pRefDef->origin;

    Vec3 vecTransform{};
    vecTransform.x = vecPos.DotProduct( SDK::m_pRefDef->matrix[ 1 ] );
    vecTransform.y = vecPos.DotProduct( SDK::m_pRefDef->matrix[ 2 ] );
    vecTransform.z = vecPos.DotProduct( SDK::m_pRefDef->matrix[ 0 ] );

    // Target is out of our fov.
    if ( vecTransform.z < 0.1f )
        return false;

    Vec2 vecCenter = {
        ( float )( SDK::m_pRefDef->width * 0.5f ),
        ( float )( SDK::m_pRefDef->height * 0.5f )
    };

    vecScreen.x = vecCenter.x * ( 1 - ( vecTransform.x / SDK::m_pRefDef->fov.x / vecTransform.z ) );
    vecScreen.y = vecCenter.y * ( 1 - ( vecTransform.y / SDK::m_pRefDef->fov.y / vecTransform.z ) );

    return true;
}

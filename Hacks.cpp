#include "Hacks.hpp"

void Hacks::OnRender( )
{
    // Watermark
    D3D::DrawFilledRect( { 5.f, 5.f }, { 145.f, 25.f }, { 0U, 0U, 0U, 100U } );
    D3D::DrawRect( { 5.f, 5.f }, { 145.f, 25.f }, { 83U, 230U, 79U, 255U } );
    D3D::DrawString( { 10.f, 10.f }, { 83U, 230U, 79U, 255U }, "COD4 Internal Cheat" );

    // ESP
    for ( int i = 0; i < MAX_PLAYERS; i++ )
    {
        C_Entity* pEntity = SDK::GetEntityFromIndex( i );
        if ( pEntity == nullptr )
            continue;

        const Vec3 entityOrigin = pEntity->origin;
        if ( entityOrigin.IsZero( ) || !entityOrigin.IsValid( ) )
            continue;

        Vec3 headPosition = entityOrigin;
        headPosition.z += 60.f;

        Vec2 screenOrigin{}, screenHead{};
        if ( !Utils::WorldToScreen( entityOrigin, screenOrigin ) ||
             !Utils::WorldToScreen( headPosition, screenHead ) )
            continue;

        // Box
        {
            float headHeight = screenHead.y - screenOrigin.y;
            float width = headHeight / 2;
            float centerX = width / -2;

            D3D::DrawRect(
                { screenOrigin.x + centerX, screenOrigin.y },
                { screenOrigin.x - centerX, screenHead.y },
                { 255U, 255U, 255U, 255U }
            );
        }
    }
}

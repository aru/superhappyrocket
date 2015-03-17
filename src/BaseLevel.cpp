#include "BaseLevel.h"

BaseLevel::BaseLevel( Context* ctx )
    :ctxt(ctx), lightSource(0), deltaTicks(0), startTicks(0), currentTicks(0)
{
}

BaseLevel::~BaseLevel() {}

const int BaseLevel::Initialize() { return SHR_SUCCESS; }
//const int BaseLevel::LoadContent() { return SHR_SUCCESS; }
const int BaseLevel::Draw() { return SHR_SUCCESS; }
const int BaseLevel::Update( Uint32 gameTime ) { return SHR_SUCCESS; }

const int BaseLevel::UnloadContent()
{
    unsigned int i;

    /* Free the memory of each thing in here */
    for( i = 0; i < actors.size(); i++ )
    {
        if( actors.at( i ) ) // paranoid sanity check
        {
            delete actors.at( i );
        }
    }

    sounds.clear();

    return SHR_SUCCESS;
}

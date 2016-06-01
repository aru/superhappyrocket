#include "SceneManager.h"

SceneManager::SceneManager( Context* ctx )
    :ctxt( ctx ), currentLevel( 0 )
{
}

SceneManager::~SceneManager()
{
}

const int SceneManager::Initialize()
{
    Level1* level1 = new Level1( ctxt );
    BaseLevel* base1 = level1; //downcast
    levels.push_back( base1 );

    LoadContent( currentLevel );
    return SHR_SUCCESS;
}

const int SceneManager::LoadContent( const unsigned int level )
{
    unsigned int i;

    /* Load the content in the level requested */
    if( level < levels.size() )
    {
        levels.at( level )->LoadContent();
    }
    else
    {
        printf("Trying to load an invalid level\n");
        SDL_assert(1);
    }

    /* Add all of the content loaded to each and every manager */

    // Add music, das ez
    ctxt->audio->LoadMusic( levels.at(level)->song );
    // Add sounds
    for( i = 0; i < levels.at(level)->sounds.size(); i++ )
    {
        ctxt->audio->LoadSound( levels.at(level)->sounds.at(i) );
    }
    // Add actors to the renderer
    for( i = 0; i < levels.at(level)->actors.size(); i++ )
    {
        // Initialize the actors
        levels.at(level)->actors.at(i)->Initialize( ctxt );
        // Add it
        ctxt->renderer->actors.push_back( levels.at(level)->actors.at( i ) );
    }
    // Add textures to the renderer
    for( i = 0; i < levels.at( level )->textures.size(); i++ )
    {
        ctxt->textureManager->addTexture(levels.at(level)->textures.at(i));
    }
    // Process the textures
    ctxt->textureManager->LoadContent();

    /* Associate our light source */
    ctxt->renderer->light = levels.at(level)->lightSource;

    levels.at(level)->Initialize();

    return SHR_SUCCESS;
}

const int SceneManager::Draw()
{
    return SHR_SUCCESS;
}

const int SceneManager::Update( Uint32 gameTime )
{
    levels.at( currentLevel )->Update( gameTime );
    return SHR_SUCCESS;
}

const int SceneManager::UnloadContent()
{
    return SHR_SUCCESS;
}

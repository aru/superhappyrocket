#include "Entity.h"

Entity::Entity( const int type, Context* ctx )
    :entityType( type ), ctxt( ctx ), speed( 5.0f ), move( false )
{
	M3DVector3f entityPos;
	M3DVector3f boundingBox;
    switch( entityType )
    {
    case 0:
        mesh = new assimpMesh( "./../content/models/estrella249.3ds", ctxt );
		entityPos[0] = 8.0f; entityPos[1] = 5.0f; entityPos[2] = -5.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin( entityPos );

        mesh->frame.RotateLocalZ( float( m3dDegToRad( 90.0f )) );
        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
        //mesh->frame.MoveForward( 50.0f );
        break;
    case 1:
        mesh = new assimpMesh( "./../content/models/edificio1.3ds", ctxt );
		entityPos[0] = -30.0f; entityPos[1] = -10.0f; entityPos[2] = -50.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);
        
        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
        mesh->scaleVector[0] = mesh->scaleVector[1] = mesh->scaleVector[2] =6.0f;
        //mesh->frame.MoveForward( 50.0f );
        break;
    case 2:
        mesh = new assimpMesh( "./../content/models/edificio2.3ds", ctxt );
		entityPos[0] = -10.0f; entityPos[1] = -10.0f; entityPos[2] = -50.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);
        
        mesh->scaleVector[0] = mesh->scaleVector[1] = mesh->scaleVector[2] =6.0f;
        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
        //mesh->frame.MoveForward( 50.0f );
        break;
    case 3:
        mesh = new assimpMesh( "./../content/models/edificio3.3ds", ctxt );
		entityPos[0] = -15.0f; entityPos[1] = -10.0f; entityPos[2] = -50.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);
        
        mesh->scaleVector[0] = mesh->scaleVector[1] = mesh->scaleVector[2] =6.0f;
        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
        //mesh->frame.MoveForward( 50.0f );
        break;
    case 4:
        mesh = new assimpMesh( "./../content/models/edificio4.3ds", ctxt );
		entityPos[0] = 20.0f; entityPos[1] = -10.0f; entityPos[2] = -50.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);
        
        mesh->scaleVector[0] = mesh->scaleVector[1] = mesh->scaleVector[2] =6.0f;
        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
        break;
    case 5:
        mesh = new assimpMesh( "./../content/models/edificio5.3ds", ctxt );
		entityPos[0] = 20.0f; entityPos[1] = -10.0f; entityPos[2] = -50.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);
       
        mesh->scaleVector[0] = mesh->scaleVector[1] = mesh->scaleVector[2] =6.0f;
        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
        break;
    case 6:
        mesh = new assimpMesh( "./../content/models/edificio6.3ds", ctxt );
		entityPos[0] = 20.0f; entityPos[1] = -10.0f; entityPos[2] = -50.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);
        
        mesh->scaleVector[0] = mesh->scaleVector[1] = mesh->scaleVector[2] =6.0f;
        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
        break;
    default:
        printf("Invalid entity requested: %d", entityType );
        break;
    }

}

Entity::~Entity()
{
    delete mesh;
    delete box;
    mesh = 0;
}

void Entity::Update( Uint32 gameTime )
{

    float linear = ( 50.f * ( gameTime / 1000.f));
    float angular = float(m3dDegToRad( 50.f * (gameTime / 1000.f)));
	M3DVector3f entityPos;

    if( move )
    {
        switch( entityType )
        {
        case 0:
            mesh->frame.RotateLocal( -angular, 1.0f, 1.0f, 0.0f );
            mesh->frame.TranslateWorld( 0.0f, 0.0f, linear );
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            mesh->frame.TranslateWorld( 0.0f, 0.0f, linear );
            break;
        default:
            break;
        }
		mesh->frame.GetOrigin(entityPos);
		mesh->collisionMesh.setOrigin(entityPos);
    }
    else
    {
        //mesh->frame.RotateLocal( -angular, 1.0f, 1.0f, 0.0f );
    }

	// update this entities bounding box position
	M3DVector3f meshPos;
	mesh->frame.GetOrigin(meshPos);
	mesh->collisionMesh.setOrigin(meshPos);

}

#include "Entity.h"

Entity::Entity( const int type, Context* ctx )
    :entityType( type ), ctxt( ctx ), speed( 5.0f ), move( false )
{
	M3DVector3f entityPos;
	M3DVector3f entityRadii;
	M3DVector3f scaleFactor = { 0.0f, 0.0f, 0.0f };
    switch( entityType )
    {
    case 0:
        mesh = new assimpMesh( "./../content/models/estrella249.3ds", ctxt );
		entityPos[0] = 8.0f; entityPos[1] = 5.0f; entityPos[2] = -5.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);

		entityRadii[0] = 0.82f; entityRadii[1] = 0.39f; entityRadii[2] = 0.78f;
		mesh->collisionMesh.setRadii( entityRadii );

        mesh->frame.RotateLocalZ( float( m3dDegToRad( 90.0f )) );
        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
        //mesh->frame.MoveForward( 50.0f );
        break;
    case 1:
        mesh = new assimpMesh( "./../content/models/edificio1.3ds", ctxt );
		entityPos[0] = -10.0f; entityPos[1] = -12.0f; entityPos[2] = -18.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);
		scaleFactor[0] = 7.0f; scaleFactor[1] = 7.0f; scaleFactor[2] = 7.0f;
		mesh->scaleVector[0] = scaleFactor[0]; mesh->scaleVector[1] = scaleFactor[1];  mesh->scaleVector[2] = scaleFactor[2];

		entityRadii[0] = 0.50f * scaleFactor[0]; entityRadii[1] = 0.50f * scaleFactor[1]; entityRadii[2] = 1.43f * scaleFactor[2];
		mesh->collisionMesh.setRadii(entityRadii);

        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
        //mesh->frame.MoveForward( 50.0f );
        break;
    case 2:
        mesh = new assimpMesh( "./../content/models/edificio2.3ds", ctxt );
		entityPos[0] = -22.0f; entityPos[1] = -12.0f; entityPos[2] = -24.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);
		scaleFactor[0] = scaleFactor[1] = scaleFactor[2] = 8.0f;
        mesh->scaleVector[0] = mesh->scaleVector[1] = mesh->scaleVector[2] = scaleFactor[0];

		entityRadii[0] = 0.31f * scaleFactor[0]; entityRadii[1] = 0.33f * scaleFactor[1]; entityRadii[2] = 1.73f * scaleFactor[2];
        mesh->collisionMesh.setRadii(entityRadii);

        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
        //mesh->frame.MoveForward( 50.0f );
        break;
    case 3:
        mesh = new assimpMesh( "./../content/models/edificio3.3ds", ctxt );
		entityPos[0] = 18.0f; entityPos[1] = -12.0f; entityPos[2] = -15.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);
		scaleFactor[0] = scaleFactor[1] = scaleFactor[2] = 6.0f;
		mesh->scaleVector[0] = mesh->scaleVector[1] = mesh->scaleVector[2] = scaleFactor[0];

		entityRadii[0] = 0.31f * scaleFactor[0]; entityRadii[1] = 0.33f * scaleFactor[1]; entityRadii[2] = 1.08f * scaleFactor[2];
		mesh->collisionMesh.setRadii(entityRadii);

        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
        //mesh->frame.MoveForward( 50.0f );
        break;
    case 4:
        mesh = new assimpMesh( "./../content/models/edificio4.3ds", ctxt );
		entityPos[0] = -1.0f; entityPos[1] = -12.0f; entityPos[2] = -24.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);
		scaleFactor[0] = scaleFactor[1] = scaleFactor[2] = 6.0f;
        mesh->scaleVector[0] = mesh->scaleVector[1] = mesh->scaleVector[2] = scaleFactor[0];

        entityRadii[0] = 0.50f * scaleFactor[0]; entityRadii[1] = 0.50f * scaleFactor[1]; entityRadii[2] = 2.30f * scaleFactor[2];
        mesh->collisionMesh.setRadii(entityRadii);
		mesh->collisionMesh.rotateX( float( m3dDegToRad(90.0f)) );

        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
        break;
    case 5:
        mesh = new assimpMesh( "./../content/models/edificio5.3ds", ctxt );
		entityPos[0] = 6.0f; entityPos[1] = -12.0f; entityPos[2] = -18.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);
		scaleFactor[0] = scaleFactor[1] = scaleFactor[2] = 6.0f;
		mesh->scaleVector[0] = mesh->scaleVector[1] = mesh->scaleVector[2] = scaleFactor[0];

		entityRadii[0] = 0.50f * scaleFactor[0]; entityRadii[1] = 0.50f * scaleFactor[1]; entityRadii[2] = 1.43f * scaleFactor[2];
		mesh->collisionMesh.setRadii(entityRadii);
		mesh->collisionMesh.rotateX( float(m3dDegToRad(90.0f)) );
        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
        break;
    case 6:
        mesh = new assimpMesh( "./../content/models/edificio6.3ds", ctxt );
		entityPos[0] = 14.0f; entityPos[1] = -12.0f; entityPos[2] = -20.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);
		scaleFactor[0] = scaleFactor[1] = scaleFactor[2] = 6.0f;
		mesh->scaleVector[0] = mesh->scaleVector[1] = mesh->scaleVector[2] = scaleFactor[0];

		entityRadii[0] = 0.31f * scaleFactor[0]; entityRadii[1] = 0.33f * scaleFactor[1]; entityRadii[2] = 1.73f * scaleFactor[2];
		mesh->collisionMesh.setRadii(entityRadii);

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

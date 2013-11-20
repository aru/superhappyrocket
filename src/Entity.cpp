#include "Entity.h"

Entity::Entity( const int type, Context* ctx )
	:entityType( type ), ctxt( ctx ), speed( 5.0f )
{

	switch( entityType )
	{
	case 0:
		mesh = new assimpMesh( "../../content/models/estrella249.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
		mesh->frame.RotateLocalZ( float( m3dDegToRad( 90.0f )) );
		mesh->frame.MoveForward( 50.0f );
		break;
	case 1:
		mesh = new assimpMesh( "../../content/models/edi1.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
		mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
		mesh->scaleVector[0] = mesh->scaleVector[1] = mesh->scaleVector[2] =6.0f;
		mesh->frame.MoveForward( 50.0f );
		break;
	case 2:
		mesh = new assimpMesh( "../../content/models/edi2.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
		mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
		mesh->frame.MoveForward( 50.0f );
		break;
	case 3:
		mesh = new assimpMesh( "../../content/models/edi3.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
		mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
		mesh->frame.MoveForward( 50.0f );
		break;
	case 4:
		mesh = new assimpMesh( "../../content/models/edi4.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
		mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
		break;
	case 5:
		mesh = new assimpMesh( "../../content/models/edi5.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
		mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
		break;
	case 6:
		mesh = new assimpMesh( "../../content/models/edi6.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
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

	if( move )
	{

	float linear = ( 50.0f * ( gameTime / 1000.f));
	float angular = float(m3dDegToRad( 50.0f * (gameTime / 1000.f)));

	switch( entityType )
	{
	case 1:
		mesh->frame.RotateLocal( -angular, 1.0f, 1.0f, 1.0f );
		mesh->frame.TranslateWorld( 0.0f, 0.0f, linear );
		break;
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
}
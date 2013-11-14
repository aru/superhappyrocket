#include "Entity.h"

Entity::Entity( const int type, Context* ctx )
	:entityType( type ), ctxt( ctx )
{

	switch( entityType )
	{
	case 0:
		mesh = new assimpMesh( "../../content/models/estrella249.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
		break;
	case 1:
		mesh = new assimpMesh( "../../content/models/edi1.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
		break;
	case 2:
		mesh = new assimpMesh( "../../content/models/edi2.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
		break;
	case 3:
		mesh = new assimpMesh( "../../content/models/edi3.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
		break;
	case 4:
		mesh = new assimpMesh( "../../content/models/edi4.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
		break;
	case 5:
		mesh = new assimpMesh( "../../content/models/edi5.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
		break;
	case 6:
		mesh = new assimpMesh( "../../content/models/edi6.3ds", ctxt );
		box = new BoundingBox( mesh->frame.GetOriginX(), mesh->frame.GetOriginY(), mesh->frame.GetOriginZ(), 
							   1.0f, 1.0f, 1.0f );
		break;
	default:
		printf("Invalid entity requested: %d", entityType );
		break;
	}

}

Entity::~Entity()
{
	delete mesh;
	mesh = 0;
}


#include "Entity.h"

Entity::Entity( const int type, Context* ctx )
    :entityType( type ), ctxt( ctx ), speed( 5.0f ), move( false )
{
	M3DVector3f entityPos;
	M3DVector3f collisionPos;
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
		entityPos[0] = -3.0f; entityPos[1] = -13.0f; entityPos[2] = -30.0f;
		//entityPos[0] = -1.0f; entityPos[1] = -12.0f; entityPos[2] = -24.0f;
        mesh->frame.SetOrigin( entityPos );
		mesh->collisionMesh.setOrigin(entityPos);
		scaleFactor[0] = scaleFactor[1] = scaleFactor[2] = 6.0f;
        mesh->scaleVector[0] = mesh->scaleVector[1] = mesh->scaleVector[2] = scaleFactor[0];

        entityRadii[0] = 0.3f * scaleFactor[0]; entityRadii[1] = 2.30f * scaleFactor[1]; entityRadii[2] = 0.3f * scaleFactor[2];
		//entityRadii[0] = 0.5f * scaleFactor[0]; entityRadii[1] = 2.30f * scaleFactor[1]; entityRadii[2] = 0.5f * scaleFactor[2];
		//entityRadii[0] = 0.5f * scaleFactor[0]; entityRadii[1] = 0.5f * scaleFactor[1]; entityRadii[2] = 2.30f * scaleFactor[2];
        mesh->collisionMesh.setRadii(entityRadii);

        mesh->frame.RotateLocalX( float( m3dDegToRad( 90.0f ) ));
		//mesh->collisionMesh.rotateX( float( m3dDegToRad(90.0f)) );
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


#if 0
>>> bpy.data.objects['star'].dimensions
Vector((1.6562707424163818, 0.7984262704849243, 1.5689722299575806))
Vector((0.8281353712081909, 0.39921313524246216, 0.7844861149787903))

>>> bpy.data.objects['edificio1'].dimensions
Vector((1.0021719932556152, 1.0021700859069824, 2.862863063812256))
Vector((0.5010859966278076, 0.5010850429534912, 1.431431531906128))

>>> bpy.data.objects['edificio2'].dimensions
Vector((0.623140811920166, 0.6660914421081543, 3.461493492126465))
Vector((0.311570405960083, 0.33304572105407715, 1.7307467460632324))

>>> bpy.data.objects['edificio3'].dimensions
Vector((0.6231414079666138, 0.6660592555999756, 2.1792571544647217))
Vector((0.3115707039833069, 0.3330296277999878, 1.0896285772323608))

>>> bpy.data.objects['edificio4'].dimensions
Vector((1.0018067359924316, 1.0018329620361328, 4.6005096435546875))
Vector((0.5009033679962158, 0.5009164810180664, 2.3002548217773438))

>>> bpy.data.objects['edificio5'].dimensions
Vector((1.0018064975738525, 1.0018322467803955, 2.8623809814453125))
Vector((0.5009032487869263, 0.5009161233901978, 1.4311904907226562))

>>> bpy.data.objects['edificio6'].dimensions
Vector((0.623140811920166, 0.6660914421081543, 3.4707722663879395))
Vector((0.311570405960083, 0.33304572105407715, 1.7353861331939697))

>> bpy.data.objects['rocket2491'].dimensions
Vector((0.47762301564216614, 1.4505228996276855, 0.48499149084091187))
Vector((0.23881150782108307, 0.7252614498138428, 0.24249574542045593)

>>> bpy.data.objects['catlow249'].dimensions
Vector((3.2612833976745605, 2.913925886154175, 2.7944531440734863))
Vector((1.6306416988372803, 1.4569629430770874, 1.3972265720367432))
#endif // 0
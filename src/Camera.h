/**
 * Camera.h
 *
 * Manages the camera on the current context
 * This class is in charge of getting the current camera frame, model view matrix, 
 * projection matrix and view frustum.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details http://www.gnu.org/licenses/.
 */

#ifndef SHR_CAMERA
#define SHR_CAMERA

/* GLTools includes */
#include <GLTools.h>
#include <GLFrame.h>
#include <GLFrustum.h>
#include <GLMatrixStack.h>
#include <GLGeometryTransform.h>

/* SHR includes */
// No need for anything right now

class Camera{
public:

	/* Constructors */
	Camera();
	~Camera();

	/* Member Specific Fucntions */
	void MoveForward( float delta );
	void MoveLeft( float delta );
	void MoveUp( float delta );
	void RotateX( float delta );
	void RotateY( float delta );
	void RotateZ( float delta );

	/* Member variables */
	M3DMatrix44f		camera;
	GLFrame				cameraFrame;
	GLMatrixStack		modelViewMatrix;
	GLMatrixStack		projectionMatrix;
	GLFrustum			viewFrustum;
	GLGeometryTransform	transformPipeline;

};

#endif
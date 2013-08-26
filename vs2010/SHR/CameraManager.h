/**
 * CameraManager.h
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

#include "Context.h"
#include <GLTools.h>
#include <GLMatrixStack.h>
#include <GLFrame.h>
#include <GLFrustum.h>
#include <GLGeometryTransform.h>

class CameraManager
{
public:
	CameraManager();
	CameraManager( Context* ctx );
	~CameraManager();

	Context * ctxt;
	M3DMatrix44f		 camera;
	GLFrame              *cameraFrame;
	GLMatrixStack		 *modelViewMatrix;		// Modelview Matrix
	GLMatrixStack		 *projectionMatrix;		// Projection Matrix
	GLFrustum			 *viewFrustum;			// View Frustum
	GLGeometryTransform	 *transformPipeline;		// Geometry Transform Pipeline
};

#endif
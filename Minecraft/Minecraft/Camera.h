#pragma once
#include "cpp_includes.h"
#include "opengl_includes.h"
#include "Plane.h"

// http://www.lighthouse3d.com/tutorials/view-frustum-culling/geometric-approach-extracting-the-planes/
// https://docs.unity3d.com/Manual/FrustumSizeAtDistance.html


class Camera {
public:
	Camera(float fov, float aspect, float near, float far);
	Camera() {}
	glm::mat4 getWorldToViewMatrix() const;
	glm::vec2 oldMousePosition;

	vec3 getPerpViewAndUp() const;
	glm::vec3 getViewDirection() const { return this->viewDirection; };
	void mouseUpdate(const glm::vec2& mouse);
	
	float getFOV() const { return this->fov; };
	float getAspect() const { return this->aspect; };
	void setAspect(float aspect) { this->aspect = aspect; }
	float getNearPlaneDist() const { return this->near_plane_dist; };
	float getFarPlaneDist() const { return this->far_plane_dist; };
	vec3 getPosition() const { return this->position; };

	float getNearPlaneHeight() const { return 2.0f * this->near_plane_dist * tan(this->fov * 0.5f); };
	float getFarPlaneHeight() const { return 2.0f * this->far_plane_dist * tan(this->fov * 0.5f); };
	float getNearPlaneWidth() const { return this->getNearPlaneHeight() * this->aspect; };
	float getFarPlaneWidth() const { return this->getFarPlaneHeight() * this->aspect; };

	std::vector<Plane> getViewFrustum() const;

	void moveRight();
	void moveLeft();
	void moveForward();
	void moveBackward();
	void moveUp();
	void moveDown();

	friend class ViewFrustum;
private:
	vec3 position;
	vec3 viewDirection;
	static vec3 UP;
	float fov;
	float aspect;
	float near_plane_dist;
	float far_plane_dist;
};
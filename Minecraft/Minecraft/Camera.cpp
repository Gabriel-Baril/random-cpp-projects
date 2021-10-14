#include "Camera.h"

vec3 Camera::UP = vec3(0.0f, 1.0f, 0.0f);

Camera::Camera(float fov,float aspect,float near,float far)
{
	this->viewDirection = vec3(0.0f, 0.0f, -1.0f);
	this->fov = fov;
	this->aspect = aspect;
	this->near_plane_dist = near;
	this->far_plane_dist = far;
}

glm::mat4 Camera::getWorldToViewMatrix() const
{
	return glm::lookAt(position, position + viewDirection,UP);
}

vec3 Camera::getPerpViewAndUp() const
{
	return glm::cross(viewDirection, UP);
}

void Camera::mouseUpdate(const glm::vec2 & currentMousePosition)
{
	glm::vec2 mouseDelta = currentMousePosition - oldMousePosition;
	if (glm::length(mouseDelta) > 50.0f) {
		oldMousePosition = currentMousePosition;
		return;
	}
	const float ROTATIONAL_SPEED = 0.004;
	viewDirection = glm::mat3(glm::rotate(mouseDelta.x * ROTATIONAL_SPEED, UP) * glm::rotate(mouseDelta.y * ROTATIONAL_SPEED, getPerpViewAndUp() ) ) * viewDirection;

	oldMousePosition = currentMousePosition;
}

std::vector<Plane> Camera::getViewFrustum() const
{
	std::vector<Plane> planes;
	planes.reserve(6);

	float farDist = getFarPlaneDist();
	float nearDist = getNearPlaneDist();
	float Hfar_div_2 = getFarPlaneHeight() / 2;
	float Wfar_div_2 = getFarPlaneWidth() / 2;
	float Hnear_div_2 = getNearPlaneHeight();
	float Wnear_div_2 = getNearPlaneWidth();
	vec3 right = getPerpViewAndUp();
	
	vec3 p_to_far = Camera::UP * Hfar_div_2;
	vec3 rgh_to_far = right * Wfar_div_2;
	vec3 p_to_near = Camera::UP * Hnear_div_2;
	vec3 rgh_to_near = right * Wnear_div_2;

	vec3 fc = position + viewDirection * farDist;
	vec3 ftl = fc + p_to_far - rgh_to_far;
	vec3 ftr = fc + p_to_far + rgh_to_far;
	vec3 fbr = fc - p_to_far + rgh_to_far;
	vec3 fbl = fc - p_to_far - rgh_to_far;

	vec3 nc = position + viewDirection * nearDist;
	vec3 ntl = nc + p_to_near - rgh_to_near;
	vec3 ntr = nc + p_to_near + rgh_to_near;
	vec3 nbl = nc - p_to_near - rgh_to_near;
	vec3 nbr = nc - p_to_near + rgh_to_near;

	planes.emplace_back(Plane(ntl, ntr, nbr, nbl)); // near
	planes.emplace_back(Plane(ntr, ftr, fbr, nbr)); // right
	planes.emplace_back(Plane(ftl, ftr, fbr, fbl)); // far
	planes.emplace_back(Plane(ntl, ftl, fbl, nbl)); // left
	planes.emplace_back(Plane(ntl, ftl, ftr, ntr)); // up
	planes.emplace_back(Plane(nbl, fbl, fbr, nbr)); // down

	return planes;
}

void Camera::moveRight()
{
	position += getPerpViewAndUp();
}

void Camera::moveLeft()
{
	position -= getPerpViewAndUp();
}

void Camera::moveForward()
{
	position += viewDirection;
}

void Camera::moveBackward()
{
	position -= viewDirection;
}

void Camera::moveUp()
{
	position += UP;
}

void Camera::moveDown()
{
	position -= UP;
}

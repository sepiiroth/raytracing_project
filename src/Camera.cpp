#include "Camera.h"

/*Initialisation*/
Camera::Camera() {
    this->focal = 10;
}

Camera::Camera(float f) {
    this->focal = f;
}

/*Calculs*/
void Camera::changeFocal(float f) {
    this->focal = f;
}

Ray Camera::getRay(float x, float y) const {
	Ray r(-1 + 2*x, -1 + 2*y, 0, 0, 0, 0);
	Point foc(0, 0, this->focal);
	r.vec = (r.origin - foc);
	r = localToGlobal(r);
	return r.normalized();
}

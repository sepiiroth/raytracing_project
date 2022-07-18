#include "Camera.h"

Camera::Camera() {}

Ray Camera::getRay(float x, float y) const {
	Ray r(-1+2*x, -1+2*y, 0, 0, 0, 0);
	Point foc(0, 0, focal);
	r.vec = (r.origin - foc);
	//r = localToGlobal(r);
	r.vec = r.vec.normalized();
	return r;
}

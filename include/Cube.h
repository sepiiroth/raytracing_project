#ifndef CUBE_H
#define CUBE_H
#include "Object.h"
#include <math.h>

class Cube : public virtual Object {
    public:
        Cube();
        Cube(Point origin, float scale, TextureMode textureMode);

        float interSide(const Ray& r, int dim, float offset) const;

        virtual bool intersect(const Ray& ray, Point& impact) const {
            Ray r = globalToLocal(ray).normalized();
            float mint = -1;
            float offsets[]={-1,1};
            for(int d = 0; d < 3; d++){
                for(int o = 0; o < 2; o++){
                    float t = interSide(r, d, offsets[o]);
                    if(t>=0 && (mint<0 || mint>t)){
                        mint = t;
                    }
                }
            }

            if(mint >= 0){
                Vector v = r.vec * mint;
                Point p(r.origin[0]+v[0], r.origin[1]+v[1], r.origin[2]+v[2]);
                impact = localToGlobal(p);
                return true;
            }

            return false;
        }

        virtual Ray getNormal(const Point& p, const Point& o)const {
            Point lp = globalToLocal(p);
            Point lo = globalToLocal(o);
            Vector v(0,0,0);
            if(lp[0]>0.999)v[0]=1.0;
            else if(lp[0]<-0.999)v[0]=-1.0;
            else if(lp[1]>0.999)v[1]=1.0;
            else if(lp[1]<-0.999)v[1]=-1.0;
            else if(lp[2]>0.999)v[2]=1.0;
            else if(lp[2]<-0.999)v[2]=-1.0;
            if(lo[0]<1 && lo[0]>-1 && lo[1]<1 && lo[1]>-1 && lo[2]<1 && lo[2]>-1)
                return localToGlobal(Ray(lp,-v)).normalized();
            return localToGlobal(Ray(lp,v)).normalized();
        }

        virtual Point getTextureCoordinates(const Point& p)const{
            Point temp(globalToLocal(p));
            float x, y;

            if(temp[2] > .999f || temp[2] < -.999f)
            {
                x = temp[0]/2 + .5f;
                y = temp[1]/2 + .5f;
            }

            if(temp[0] > .999f || temp[0] < -.999f)
            {
                x = temp[2]/2 + .5f;
                y = temp[1]/2 + .5f;
            }

            if(temp[1] > .999f || temp[1] < -.999f)
            {
                x = temp[0]/2 + .5f;
                y = temp[2]/2 + .5f;
            }

            return Point(x, y, 0);
        }
    protected:

    private:
};

#endif // CUBE_H

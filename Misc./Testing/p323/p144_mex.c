#include <math.h>
#include <stdint.h>
#include <mex.h>
#include <omp.h>
#include <time.h>

/* 
 * Problem 144: In laser physics, a "white cell" is a mirror system that
 * acts as a delay line for the laser beam. The beam enters the cell,
 * bounces around on the mirrors, and eventually works its way back out.
 * 
 * The specific white cell we will be considering is an ellipse with the
 * equation 4x^2 + y^2 = 100
 * 
 * The section corresponding to -0.01 <= x <= +0.01 at the top is missing,
 * allowing the light to enter and exit through the hole.
 * 
 * The light beam in this problem starts at the point (0.0,10.1) just
 * outside the white cell, and the beam first impacts the mirror at
 * (1.4,-9.6).
 * 
 * Each time the laser beam hits the surface of the ellipse, it follows the
 * usual law of reflection "angle of incidence equals angle of reflection."
 * That is, both the incident and reflected beams make the same angle with
 * the normal line at the point of incidence.
 * 
 * In the figure on the left, the red line shows the first two points of
 * contact between the laser beam and the wall of the white cell; the blue
 * line shows the line tangent to the ellipse at the point of incidence of
 * the first bounce.
 * 
 * The slope m of the tangent line at any point (x,y) of the given ellipse
 * is: m = -4x/y
 * 
 * The normal line is perpendicular to this tangent line at the point of
 * incidence.
 * 
 * The animation on the right shows the first 10 reflections of the beam.
 * 
 * How many times does the beam hit the internal surface of the white cell
 * before exiting?
 */

#define DOUBLE_TOL      2.220446049250313e-16
#define SINGLE_TOL      1.192092895507813e-07
#define IS_INSIDE(x,y)  ( 4*x*x + y*y < 100 )

inline void next_v( double x, double y, double* vx, double* vy );
inline void next_p( double vx, double vy, double* x, double* y );
uint32_t p144(void);

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    clock_t start = clock();
    
    uint32_t result, i, iters = 1000;
    for(i = 0; i < iters; ++i)
        result = p144();
    
    clock_t end = clock();
    float seconds = (float)(end-start)/CLOCKS_PER_SEC;
    
    mexPrintf("\nResult:\t%d\nTime:\t%0.10f\n\n",result,seconds/iters);
    plhs[0] = mxCreateDoubleScalar((double)result);
    
    return;
}

uint32_t p144(void) {
    double x = 1.4, y = -9.6, vx = 1.4, vy = -19.7;
    uint32_t count = 0;
    
    while ( y < 9.999979999980001 ) {
        next_v(x,y,&vx,&vy);
        next_p(vx,vy,&x,&y);
        count++;
    }
    
    return count;
}

inline void next_v( double x, double y, double* vx, double* vy ) {
    double Tx, Ty, alpha;
    
    Tx = -y, Ty = 4*x;    
    alpha = ((*vx)*Tx + (*vy)*Ty)/(Tx*Tx + Ty*Ty);
    
    *vx = 2*alpha*Tx - (*vx);
    *vy = 2*alpha*Ty - (*vy);
    
    return;
}

inline void next_p( double vx, double vy, double* x, double* y ) {
    double x1 = (*x) + vx;
    double y1 = (*y) + vy;
    double tmin = 1.0, tmax = 1.0, tmid;
    
    if ( IS_INSIDE(x1,y1) ) {
        do {
            tmax *= 2.0;
            x1 = (*x) + tmax*vx;
            y1 = (*y) + tmax*vy;
        } while ( IS_INSIDE(x1,y1) );
    } else {
        do {
            tmin /= 2.0;
            x1 = (*x) + tmin*vx;
            y1 = (*y) + tmin*vy;
        } while ( !IS_INSIDE(x1,y1) );
    }
        
    while ( tmax-tmin > DOUBLE_TOL ) {
    //while ( tmax-tmin > SINGLE_TOL ) {
        tmid = 0.5*(tmin+tmax);
        x1 = (*x) + tmid*vx;
        y1 = (*y) + tmid*vy;
        
        if ( IS_INSIDE(x1,y1) ) {
            tmin = tmid;
        } else {
            tmax = tmid;
        }
    }
        
    tmid = 0.5*(tmin+tmax);
    *x += tmid*vx;
    *y += tmid*vy;
    
    return;
}


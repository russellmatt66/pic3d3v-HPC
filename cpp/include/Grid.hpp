#ifndef GRID_3D3V_HPP
#define GRID_3D3V_HPP
#include "pic3d3v.hpp"

class CartesianPoint{
    public:
        CartesianPoint(double x, double y, double z) :
            x_(x), y_(y), z_(z)
        {}

        const double X() const { return x_; }
        const double Y() const { return y_; }
        const double Z() const { return z_; }

        double& X() { return x_; }
        double& Y() { return y_; }
        double& Z() { return z_; }

        // Space for member functions that do typical things like compute norms

    private:
        double x_, y_, z_;
};

// rank-3 tensor for holding spatial grid 
class CartesianTensor{
    public: 
        CartesianTensor(size_t Nx) : 
            storage_(Nx*Nx*Nx, CartesianPoint(0.0,0.0,0.0))
        {}

        /* Accessors */

    private:
        std::vector<CartesianPoint> storage_;
};

// Simulation grid object for 3D3V full electromagnetic PIC code
/* Structure depends a lot on electromagnetic solver, so leave ambiguous for the moment */
class Grid3d3v{
    public:
        Grid3d3v(size_t Nx) :
            SpatialGrid_(Nx)
        {}

        /* Accessors */

    private:
        CartesianTensor SpatialGrid_;
};
#endif
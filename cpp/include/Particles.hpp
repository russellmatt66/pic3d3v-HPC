#include <vector>
#include <string>

// Class to collect all the particles together
class ParticleList{
    public:
        ParticleList(size_t N) : 
        N_(N), particles_x(N, 0.0), particles_vx(N, 0.0), particles_Ex(N, 0.0), x_found(N, 0), species_id(N, "") 
        {}

        // Boilerplate
        const size_t getParticleNum() const { return N_; }

        // Element-wise accessor methods
        const double ParticleX(size_t i) const { return particles_x[i]; }
        const double ParticleVx(size_t i) const { return particles_vx[i]; }
        const double ParticleEx(size_t i) const {return particles_Ex[i]; }
        const size_t XFound(size_t i) const { return x_found[i]; }
		const std::string SpeciesID(size_t i) const { return species_id[i]; }

        double &ParticleX(size_t i) { return particles_x[i]; }
        double &ParticleVx(size_t i) { return particles_vx[i]; }
        double &ParticleEx(size_t i) { return particles_Ex[i]; }
        size_t &XFound(size_t i) { return x_found[i]; }
		std::string SpeciesID(size_t i) { return species_id[i]; }

        // Also need to be able to access whole data members
        const std::vector<double>& getParticleX() const { return particles_x; }
        const std::vector<double>& getParticleVx() const { return particles_vx; }
        const std::vector<double>& getParticleEx() const { return particles_Ex; }
        const std::vector<size_t>& getXFound() const { return x_found; }
		const std::vector<std::string>& getSpeciesID() const { return species_id; }

        std::vector<double>& getParticleX() { return particles_x; }
        std::vector<double>& getParticleVx() { return particles_vx; }
        std::vector<double>& getParticleEx() { return particles_Ex; }
        std::vector<size_t>& getXFound() { return x_found; }
		std::vector<std::string>& getSpeciesID() { return species_id; }

    private:
        size_t N_;
        std::vector<double> particles_x;
        std::vector<double> particles_vx;
        std::vector<double> particles_Ex;
        std::vector<size_t> x_found;
        std::vector<std::string> species_id; 
};
#include <vector>
#include <string>

using std::string;

// Particle species class
class ParticleSpecies3d3v{
	public:
		// Constructor
		ParticleSpecies3d3v(size_t N, size_t Q, string ID) :
			N_(N), Q_(Q), species_id_(ID), 
			particle_x_(N, 0.0), particle_y_(N, 0.0), particle_z_(N, 0.0), 
			particle_vx_(N, 0.0), particle_vy_(N, 0.0), particle_vz_(N, 0.0),
			particle_Fx_(N, 0.0), particle_Fy_(N, 0.0), particle_Fz_(N, 0.0),
			xfound_(N, 0), yfound_(N, 0), zfound_(N, 0)
		{}
		
		/* Boilerplate, abandon all hope of not reading accessors, ye who enter here! */
		// Basic attributes
       	 	const size_t ParticleNum() const { return N_; }
		const double Q() const { return Q_; }
		const string SpeciesID() const { return species_id_; }
		string SpeciesID() { return species_id_; }
		
        	// Element-wise accessor methods
        	const double ParticleX(size_t i) const { return particle_x_[i]; }
		const double ParticleY(size_t i) const { return particle_y_[i]; }
		const double ParticleZ(size_t i) const { return particle_z_[i]; }
		
        	const double ParticleVx(size_t i) const { return particle_vx_[i]; }
        	const double ParticleVy(size_t i) const { return particle_vy_[i]; }
		const double ParticleVz(size_t i) const { return particle_vz_[i]; }
		
		const double ParticleFx(size_t i) const {return particle_Fx_[i]; }
		const double ParticleFy(size_t i) const {return particle_Fy_[i]; }
		const double ParticleFz(size_t i) const {return particle_Fz_[i]; }
        
		const size_t XFound(size_t i) const { return xfound_[i]; }
		const size_t YFound(size_t i) const { return yfound_[i]; }
		const size_t ZFound(size_t i) const { return zfound_[i]; }

        	double &ParticleX(size_t i) { return particle_x_[i]; }
		double &ParticleY(size_t i) { return particle_y_[i]; }
		double &ParticleZ(size_t i) { return particle_z_[i]; }
		
        	double &ParticleVx(size_t i) { return particle_vx_[i]; }
		double &ParticleVy(size_t i) { return particle_vy_[i]; }
		double &ParticleVz(size_t i) { return particle_vz_[i]; }
        
		double &ParticleFx(size_t i) { return particle_Fx_[i]; }
		double &ParticleFy(size_t i) { return particle_Fy_[i]; }
		double &ParticleFz(size_t i) { return particle_Fz_[i]; }
        
		size_t &XFound(size_t i) { return xfound_[i]; }
		size_t &YFound(size_t i) { return yfound_[i]; }
		size_t &ZFound(size_t i) { return zfound_[i]; }


        	// Also need to be able to access whole data members
        	const std::vector<double>& getParticleX() const { return particle_x_; }
		const std::vector<double>& getParticleY() const { return particle_y_; }
		const std::vector<double>& getParticleZ() const { return particle_z_; }
        
		const std::vector<double>& getParticleVx() const { return particle_vx_; }
		const std::vector<double>& getParticleVy() const { return particle_vy_; }
		const std::vector<double>& getParticleVz() const { return particle_vz_; }
        
		const std::vector<double>& getParticleFx() const { return particle_Fx_; }
		const std::vector<double>& getParticleFy() const { return particle_Fy_; }
		const std::vector<double>& getParticleFz() const { return particle_Fz_; }
        
		const std::vector<size_t>& getXFound() const { return xfound_; }
		const std::vector<size_t>& getYFound() const { return yfound_; }
		const std::vector<size_t>& getZFound() const { return zfound_; }


        	std::vector<double>& getParticleX() { return particle_x_; }
		std::vector<double>& getParticleY() { return particle_y_; }
		std::vector<double>& getParticleZ() { return particle_z_; }
		
        	std::vector<double>& getParticleVx() { return particle_vx_; }
		std::vector<double>& getParticleVy() { return particle_vy_; }
		std::vector<double>& getParticleVz() { return particle_vz_; }
		
        	std::vector<double>& getParticleFx() { return particle_Fx_; }
		std::vector<double>& getParticleFy() { return particle_Fy_; }
		std::vector<double>& getParticleFz() { return particle_Fz_; }
		
        	std::vector<size_t>& getXFound() { return xfound_; }
		std::vector<size_t>& getYFound() { return yfound_; }
		std::vector<size_t>& getZFound() { return zfound_; }
		
	private:
		string species_id_;
	    	size_t N_;
        	double Q_;
        	std::vector<double> particle_x_;
		std::vector<double> particle_y_;
		std::vector<double> particle_z_;
	        std::vector<double> particle_vx_;
	        std::vector<double> particle_vy_;
	        std::vector<double> particle_vz_;
	        std::vector<double> particle_Fx_;
	        std::vector<double> particle_Fy_;
	        std::vector<double> particle_Fz_;
	        std::vector<size_t> xfound_;
	        std::vector<size_t> yfound_;
	        std::vector<size_t> zfound_;
};

// Class to collect all the particles together
class ParticleList{
    public:
	ParticleList(size_t N, std::vector<ParticleSpecies3d3v> SpeciesArr) : 
        	N_(N), Q_(N, 0.0), species_id_(N, ""),
		particles_x_(N, 0.0), particles_y_(N, 0.0), particles_z_(N, 0.0),
		particles_vx_(N, 0.0), particles_vy_(N, 0.0), particles_vz_(N, 0.0),
		particles_Fx_(N, 0.0), particles_Fy_(N, 0.0), particles_Fz_(N, 0.0),
		xfound_(N, 0), yfound_(N, 0), zfound_(N, 0) 
	{}

        /* Boilerplate, abandon all hope of not reading accessors, ye who enter here! */
	// Basic attributes
	const size_t ParticleNum() const { return N_; }
	const double Q(size_t i) const { return Q_[i]; }
	const string SpeciesID(size_t i) const { return species_id_[i]; }
	string SpeciesID(size_t i) { return species_id_[i]; }
	
	const std::vector<string>& getSpeciesID() const { return species_id_; }
	std::vector<string>& getSpeciesID() { return species_id_; }

        // Element-wise accessor methods
	const double ParticleX(size_t i) const { return particles_x_[i]; }
	const double ParticleY(size_t i) const { return particles_y_[i]; }
	const double ParticleZ(size_t i) const { return particles_z_[i]; }
	
	const double ParticleVx(size_t i) const { return particles_vx_[i]; }
	const double ParticleVy(size_t i) const { return particles_vy_[i]; }
	const double ParticleVz(size_t i) const { return particles_vz_[i]; }
	
	const double ParticleFx(size_t i) const {return particles_Fx_[i]; }
	const double ParticleFy(size_t i) const {return particles_Fy_[i]; }
	const double ParticleFz(size_t i) const {return particles_Fz_[i]; }

	const size_t XFound(size_t i) const { return xfound_[i]; }
	const size_t YFound(size_t i) const { return yfound_[i]; }
	const size_t ZFound(size_t i) const { return zfound_[i]; }

	double &ParticleX(size_t i) { return particles_x_[i]; }
	double &ParticleY(size_t i) { return particles_y_[i]; }
	double &ParticleZ(size_t i) { return particles_z_[i]; }
	
	double &ParticleVx(size_t i) { return particles_vx_[i]; }
	double &ParticleVy(size_t i) { return particles_vy_[i]; }
	double &ParticleVz(size_t i) { return particles_vz_[i]; }

	double &ParticleFx(size_t i) { return particles_Fx_[i]; }
	double &ParticleFy(size_t i) { return particles_Fy_[i]; }
	double &ParticleFz(size_t i) { return particles_Fz_[i]; }

	size_t &XFound(size_t i) { return xfound_[i]; }
	size_t &YFound(size_t i) { return yfound_[i]; }
	size_t &ZFound(size_t i) { return zfound_[i]; }


	// Also need to be able to access whole data members
	const std::vector<double>& getParticleX() const { return particles_x_; }
	const std::vector<double>& getParticleY() const { return particles_y_; }
	const std::vector<double>& getParticleZ() const { return particles_z_; }

	const std::vector<double>& getParticleVx() const { return particles_vx_; }
	const std::vector<double>& getParticleVy() const { return particles_vy_; }
	const std::vector<double>& getParticleVz() const { return particles_vz_; }

	const std::vector<double>& getParticleFx() const { return particles_Fx_; }
	const std::vector<double>& getParticleFy() const { return particles_Fy_; }
	const std::vector<double>& getParticleFz() const { return particles_Fz_; }

	const std::vector<size_t>& getXFound() const { return xfound_; }
	const std::vector<size_t>& getYFound() const { return yfound_; }
	const std::vector<size_t>& getZFound() const { return zfound_; }


	std::vector<double>& getParticleX() { return particles_x_; }
	std::vector<double>& getParticleY() { return particles_y_; }
	std::vector<double>& getParticleZ() { return particles_z_; }
	
	std::vector<double>& getParticleVx() { return particles_vx_; }
	std::vector<double>& getParticleVy() { return particles_vy_; }
	std::vector<double>& getParticleVz() { return particles_vz_; }
	
	std::vector<double>& getParticleFx() { return particles_Fx_; }
	std::vector<double>& getParticleFy() { return particles_Fy_; }
	std::vector<double>& getParticleFz() { return particles_Fz_; }
	
	std::vector<size_t>& getXFound() { return xfound_; }
	std::vector<size_t>& getYFound() { return yfound_; }
	std::vector<size_t>& getZFound() { return zfound_; }

    private:
	size_t N_;
        std::vector<double> Q_;
	std::vector<string> species_id_;
        std::vector<double> particles_x_;
	std::vector<double> particles_y_;
	std::vector<double> particles_z_;
        std::vector<double> particles_vx_;
        std::vector<double> particles_vy_;
        std::vector<double> particles_vz_;
        std::vector<double> particles_Fx_;
        std::vector<double> particles_Fy_;
        std::vector<double> particles_Fz_;
        std::vector<size_t> xfound_;
        std::vector<size_t> yfound_;
        std::vector<size_t> zfound_;
};

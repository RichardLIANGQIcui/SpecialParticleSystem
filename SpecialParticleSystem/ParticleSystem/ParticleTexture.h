#include "common.h"

class ParticleTexture{
private:
	unsigned int textureID{ 0 };
	unsigned int numberOfRows{ 0 };
	Particle_Type type{Particle_Type::DEFAULT};
	bool isAdditive{ true }; //是否使用additive混合

public:
	ParticleTexture(int textureID, int numberOfRows, Particle_Type type, bool isAdditive) 
		:textureID(textureID), numberOfRows(numberOfRows), type(type), isAdditive(isAdditive){}

	inline int getTextureID() const
	{
		return textureID;
	}
	inline int getNumberOfRows() const
	{
		return numberOfRows;
	}
	inline Particle_Type getParticleType() const
	{
		return type;
	}
	inline bool getIsAdditve() const
	{
		return isAdditive;	
	}
	
};
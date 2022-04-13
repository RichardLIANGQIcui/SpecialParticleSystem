#ifndef PARTICLE_H
#define PARTICLE_H

#include <glm/glm.hpp>
#include <learnopengl/camera.h>
#include "ParticleTexture.h"

typedef glm::vec3 vec3;
typedef glm::vec2 vec2;

extern float GRAVITY;
extern float deltaTime;

class Particle{
private:
	vec3 position;
	vec3 velocity;
	float gravityEffect;
	float staticLifeLength;
	float lifeLength{ 0.0f };
	float rotation;
	float scale;
	float distance{ 0.0f };
	float elapsedTime{ 0.0f };

	bool alive = false;

	ParticleTexture texture;
	vec2 texOffset1;
	vec2 texOffset2;
	float blend{ 0.0f };

	void updateTextureCoordInfo();
	void setTextureOffset(vec2 &offset, int index);
	
public:
	Particle(const vec3& position, const vec3& velocity, float gravityEffect, float lifeLength, float rotation, float scale, const ParticleTexture& texture)
		: position(position), velocity(velocity), gravityEffect(gravityEffect), 
		staticLifeLength(lifeLength), lifeLength(lifeLength), rotation(rotation), scale(scale), texture(texture){}

	void setActive(const vec3& position, const vec3& velocity, float rotation, float scale);
	void setActive(const vec3& position, const vec3& velocity, float rotation, float scale,float Lifelength);
	void setNotActive();
	bool update(const Camera& camera);

	vec3 getPosition() const
	{
		return position;
	}
	float getRotation() const
	{
		return rotation;
	}
	float getScale() const
	{
		return scale;
	}
	float getStaticLifeLength() const
	{
		return staticLifeLength;
	}
	float getLifeLength() const
	{
		return lifeLength;
	}
	ParticleTexture getTexture() const
	{
		return texture;
	}
	vec2 getTexOffset1() const
	{
		return texOffset1;
	}
	vec2 getTexOffset2() const
	{
		return texOffset2;
	}
	float getBlend() const
	{
		return blend;
	}
	float getDistance() const
	{
		return distance;
	}
	bool isAlive() const
	{
		return alive;
	}
};

#endif


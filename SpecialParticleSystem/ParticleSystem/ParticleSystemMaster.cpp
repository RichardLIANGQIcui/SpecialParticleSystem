#include "ParticleSystemMaster.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

extern Camera camera;

unsigned int ParticleSystemMaster::loadTexture(char const* path)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum format{ 0 };
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	} else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}

vector<ParticleSystem> ParticleSystemMaster::particleSystems;
vector<vec3> ParticleSystemMaster::particleSystemsPositions;

void ParticleSystemMaster::LoadParticlesInfo(const vector<ParticleSetting>& ParticleConfigs)
{
	unsigned int textureID_0, textureID_1, textureID_2, textureID_3, textureID_4, textureID_5;
	textureID_0 = loadTexture("./Resource/particleAtlas.png");
	textureID_1 = loadTexture("./Resource/particleFire.png");
	textureID_2 = loadTexture("./Resource/snow.bmp");
	textureID_3 = loadTexture("./Resource/particleStar.png");
	textureID_4 = loadTexture("./Resource/particleSmoke.png");
	textureID_5 = loadTexture("./Resource/particleCosmic.png");

	ParticleTexture fireWorksTexture(textureID_0, 4, Particle_Type::FIREWORKS, false);
	ParticleTexture fireTexture(textureID_1, 8, Particle_Type::FIRE, true);
	ParticleTexture snowTexture(textureID_2, 1, Particle_Type::SNOW, true);
	ParticleTexture starTexture(textureID_3, 1, Particle_Type::STAR, true);
	ParticleTexture smokeTexture(textureID_4, 8, Particle_Type::SMOKE, false);
	ParticleTexture cosmicTexture(textureID_5, 4, Particle_Type::COSTMIC, true);

	for (const auto& setting : ParticleConfigs)
	{
		switch (setting.type_index)
		{
			case 0:
			{
				ParticleSystem fireWorks(setting.num, setting.speed, setting.gravity_factor, setting.life_length, fireWorksTexture);
				vec3 position{ setting.positon[0], setting.positon[1], setting.positon[2] };
				particleSystems.emplace_back(fireWorks);
				particleSystemsPositions.emplace_back(position);
				break;
			}
			case 1:
			{
				ParticleSystem fire(setting.num, setting.speed, setting.gravity_factor, setting.life_length, fireTexture);
				vec3 position{ setting.positon[0], setting.positon[1], setting.positon[2] };
				particleSystems.emplace_back(fire);
				particleSystemsPositions.emplace_back(position);
				break;
			}
			case 2:
			{
				ParticleSystem snow(setting.num, setting.speed, setting.gravity_factor, setting.life_length, snowTexture);
				vec3 position{ setting.positon[0], setting.positon[1], setting.positon[2] };
				particleSystems.emplace_back(snow);
				particleSystemsPositions.emplace_back(position);
				break;
			}
			case 3:
			{
				ParticleSystem star(setting.num, setting.speed, setting.gravity_factor, setting.life_length, starTexture);
				vec3 position{ setting.positon[0], setting.positon[1], setting.positon[2] };
				particleSystems.emplace_back(star);
				particleSystemsPositions.emplace_back(position);
				break;
			}
			case 4:
			{
				ParticleSystem smoke(setting.num, setting.speed, setting.gravity_factor, setting.life_length, smokeTexture);
				vec3 position{ setting.positon[0], setting.positon[1], setting.positon[2] };
				particleSystems.emplace_back(smoke);
				particleSystemsPositions.emplace_back(position);
				break;
			}
			case 5:
			{
				ParticleSystem galaxy(setting.num, setting.speed, setting.gravity_factor, setting.life_length, cosmicTexture);
				vec3 position{ setting.positon[0], setting.positon[1], setting.positon[2] };
				particleSystems.emplace_back(galaxy);
				particleSystemsPositions.emplace_back(position);
				break;
			}
		}
	}
}

void ParticleSystemMaster::LoadDefaultParticlesInfo()
{
	unsigned int textureID_0, textureID_1, textureID_2, textureID_3, textureID_4, textureID_5;
	textureID_0 = loadTexture("./Resource/particleAtlas.png");
	textureID_1 = loadTexture("./Resource/particleFire.png");
	textureID_2 = loadTexture("./Resource/particleSmoke.png");
	textureID_3 = loadTexture("./Resource/snow.bmp");
	textureID_4 = loadTexture("./Resource/particleStar.png");
	textureID_5 = loadTexture("./Resource/particleCosmic.png");

	ParticleTexture fireWorksTexture(textureID_0, 4, Particle_Type::FIREWORKS, false);
	ParticleTexture fireTexture(textureID_1, 8, Particle_Type::FIRE, true);
	ParticleTexture smokeTexture(textureID_2, 8, Particle_Type::SMOKE, false);
	ParticleTexture snowTexture(textureID_3, 1, Particle_Type::SNOW, true);
	ParticleTexture starTexture(textureID_4, 1, Particle_Type::STAR, true);
	ParticleTexture cosmicTexture(textureID_5, 4, Particle_Type::COSTMIC, true);

	/*ParticleSystem fireWorks(288, 1, -1, 4, fireWorksTexture);
	ParticleSystem fire(500, 3.6, 0.15, 4.0, fireTexture);
	ParticleSystem smoke(30, 0.5, 0, 12, smokeTexture);
	ParticleSystem snow(250, 1, -1, 8, snowTexture);
	ParticleSystem star(50, 4, -3, 8, starTexture);
	ParticleSystem galaxy(200, 3, -2, 4, cosmicTexture);

	particleSystems.emplace_back(fireWorks);
	particleSystems.emplace_back(fire);
	particleSystems.emplace_back(smoke);
	particleSystems.emplace_back(snow);
	particleSystems.emplace_back(star);
	particleSystems.emplace_back(galaxy);

	vec3 fireWorksPos = vec3(0.0f, -1.0f, -2.0f);
	vec3 firePos = vec3(-10.0f, -5.0f, 5.0f);
	vec3 smokePos = vec3(-5.0, -1.0, -2.0);
	vec3 snowPos = vec3(15.0f, 10.0f, 5.0f);
	vec3 starPos = vec3(0.0f, 40.0f, -5.0f);
	vec3 galaxyPos = vec3(0.0f, -1.0f, 10.0f);

	particleSystemsPositions.emplace_back(fireWorksPos);
	particleSystemsPositions.emplace_back(firePos);
	particleSystemsPositions.emplace_back(smokePos);
	particleSystemsPositions.emplace_back(snowPos);
	particleSystemsPositions.emplace_back(starPos);
	particleSystemsPositions.emplace_back(galaxyPos);*/

	ParticleSystem fire(500, 3.6, 0.15, 4.0, fireTexture);
	vec3 firePos = vec3(-5.0f, -5.0f, -25.0f);
	particleSystems.emplace_back(fire);
	particleSystemsPositions.emplace_back(firePos);

	ParticleSystem fireWorks(500, 2.5, -1.1, 4.2, fireWorksTexture);
	vec3 fireWorksPos = vec3(3.0f, -2.0f, -10.0f);
	particleSystems.emplace_back(fireWorks);
	particleSystemsPositions.emplace_back(fireWorksPos);

	ParticleSystem snow(300, 1, -0.5, 15, snowTexture);
	vec3 snowPos = vec3(0.0f, 25.0f, 0.0f);
	particleSystems.emplace_back(snow);
	particleSystemsPositions.emplace_back(snowPos);

}
void ParticleSystemMaster::Start(const Camera& camera)
{
	for (int i = 0; i < particleSystems.size(); i++)
	{
		particleSystems[i].generateParticles(particleSystemsPositions[i]);
		particleSystems[i].update(camera);
		particleSystems[i].render(camera);
	}
}

void ParticleSystemMaster::ParallelUpdate(int particle_index)
{
	particleSystems[particle_index].generateParticles(particleSystemsPositions[particle_index]);
	particleSystems[particle_index].update(camera);
}
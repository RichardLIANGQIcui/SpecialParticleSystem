#ifndef PARTICLE_SYSTEM_MASTER_H
#define PARTICLE_SYSTEM_MASTER_H

#include "ParticleSystem.h"
#include "ThreadPool.hpp"
#include "common.h"
#include <vector>

//后续改成loader
class ParticleSystemMaster{
private:
	static unsigned int loadTexture(const char* path);

public:
	static vector<ParticleSystem> particleSystems;
	static vector<vec3> particleSystemsPositions;
	static void LoadDefaultParticlesInfo();
	static void LoadParticlesInfo(const vector<ParticleSetting>& ParticleConfigs);
	static void ParallelUpdate(int particle_index);
	static void Start(const Camera& camera); // 所有粒子系统一起渲染调用此接口
};

#endif
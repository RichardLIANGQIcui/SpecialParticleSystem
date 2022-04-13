#ifndef PARTILCE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "ParticleMaster.h"
#include "ParticleRenderer.h"

extern float deltaTime;

class ParticleSystem{
private:
	float pps; // particles per second
	float speed;
	float gravityComplient; // ��������
	float lifeLength;

	ParticleTexture texture;

	//ParticleEmitter emitter; //ÿһ������ϵͳ���Լ���һ��emitter -> emit
	ParticleMaster master; //ÿ������ϵͳ��һ���Լ���master  -> update
	ParticleRenderer renderer; //ÿ������ϵͳ��һ���Լ���renderer -> render

	void initParticleList();
	void emitFireworksParticles(int count, vec3 systemCenter);
	void emitFireParticles(int count, vec3 systemCenter);
	void emitSmokeParticles(int count, vec3 systemCenter);
	void emitSnowParticles(int count, vec3 systemCenter);
	void emitStarParticles(int count, vec3 systemCenter);
	void emitCosmicParticles(int count, vec3 systemCenter);
	void emitDefaultParticles(int count, vec3 systemCenter);

public:
	//master��renderer�Զ�����Ĭ�ϵĹ��캯��
	ParticleSystem(float pps, float speed, float gravityComplient, float lifeLength, ParticleTexture texture) :
		pps(pps), speed(speed), gravityComplient(gravityComplient), lifeLength(lifeLength), texture(texture){}
	//���º���Ϊ�ⲿ���ýӿ�  �������Է�װΪһ���ӿ� particleSystem.start(sysPos,projection,camera)
	//projection������Ҳ�����Ż� �趨һ��Ĭ��ֵ ��renderer�����ʱ�� �������projection
	void generateParticles(const vec3& systemCenter);  //��ѭ���� ÿ֡����
	void setProjection(const mat4& projection);
	void update(const Camera& camera);
	void render(const Camera& camera);
};

#endif
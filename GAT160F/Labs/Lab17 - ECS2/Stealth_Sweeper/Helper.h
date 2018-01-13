#ifndef HELPER_H
#define HELPER_H
#include "glm.hpp"
#include <iostream>
namespace debugger {
	float randomFloat()
	{
		return (float)rand() / RAND_MAX;
	}
	float randomInRange(float min, float max)
	{
		return randomFloat() * (max - min) + min;
	}

	void printVari(glm::vec3 v)
	{
		std::cout << v.x << ", " << v.y << ", " << v.z << std::endl;
	}
	void printVari(glm::vec4 v)
	{
		std::cout << v.x << ", " << v.y << ", " << v.z << ", " << v.w<< std::endl;
	}
	void printVari(glm::mat4 m)
	{
		std::cout << m[0][0] << ", " << m[0][1] << ", " << m[0][2] << ", " << m[0][3] << std::endl;
		std::cout << m[1][0] << ", " << m[1][1] << ", " << m[1][2] << ", " << m[1][3] << std::endl;
		std::cout << m[2][0] << ", " << m[2][1] << ", " << m[2][2] << ", " << m[2][3] << std::endl;
		std::cout << m[3][0] << ", " << m[3][1] << ", " << m[3][2] << ", " << m[3][3] << std::endl;
		std::cout << std::endl;
	}
	void printVari(glm::mat3 m)
	{
		std::cout << m[0][0] << ", " << m[0][1] << ", " << m[0][2] << std::endl;
		std::cout << m[1][0] << ", " << m[1][1] << ", " << m[1][2] << std::endl;
		std::cout << m[2][0] << ", " << m[2][1] << ", " << m[2][2] << std::endl;
		std::cout << std::endl;
	}
}

#endif
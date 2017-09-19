#include "BlankScene.hpp"
#include <atlas/core/GLFW.hpp>

BlankScene::BlankScene()
{
}

BlankScene::~BlankScene()
{
}

void BlankScene::renderScene()
{
	float theta = 45.0f;
	float row = 3.0f;
	float aspectRatio = 1.0f;
	
	glm::vec3 eye(5.0*cos(glm::radians(theta)), 5.0*sin(glm::radians(theta)), row);
	glm::vec3 look(0.0, 0.0, 0.0);
	glm::vec3 up(0.0, 0.0, 1.0);
	
	glm::mat4 view = glm::lookAt(eye, look, up);
	glm::mat4 projection = glm::perspective(glm::radians(70.0f), aspectRatio, 0.01f, 100.0f);
	
	
	//Render red colour
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	mMass.renderGeometry(projection, view);
	mCoil.renderGeometry(projection, view);
}

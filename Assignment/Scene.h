#pragma once
#include "Camera.h"
#include "Dependencies/glm/glm/glm.hpp"
#include "Dependencies/glm/glm/glm.hpp"
#include "Dependencies/glm/glm/gtc/matrix_transform.hpp"
#include "Dependencies/glm/glm/gtc/type_ptr.hpp"



class Scene
{
public:
	void Initialise(GLFWwindow* _Window , std::shared_ptr<CameraObject> _camera);
	void LoadScene();



	void processInput(GLFWwindow* window);
	void RenderCube(std::shared_ptr<Shader>& shader);
	void SetCube();
	

	//fix
	//glm::vec3 bulbPos(0.0f, 0.0f, 0.0f);

	//Time
	double deltaTime;
	double lastFrame;

	//Cube
	unsigned int cubeVAO = 0;
	unsigned int cubeVBO = 0;

	//Window
	GLFWwindow* window;
	const unsigned int ScreenWidth = 1420;
	const unsigned int ScreenHeight = 920;

	//New objects
	std::shared_ptr<Shader> shader = std::make_shared<Shader>("vert.vs", "frag.fs");
	std::shared_ptr<Shader> simpleDepthShader = std::make_shared<Shader>("color.vs", "color.fs", "color.gs");
	std::shared_ptr<TextureLoader>woodTexture = std::make_shared<TextureLoader>("redwood.jpg", "normaltex");

	//Gamma
	bool gammaEnabled = false;
	bool gammaKeyPressed = false;

	//Camera
	std::shared_ptr<CameraObject> camera;

	//Shadows 
	bool shadows = true;
	bool shadowsKeyPressed = false;
	unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;


};
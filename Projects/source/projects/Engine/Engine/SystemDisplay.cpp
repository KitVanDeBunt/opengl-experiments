
#include "KECS.h"

#include "SFML\System.hpp"
#include <SFML\Window.hpp>
#include <GL\glew.h>
#include <SFML\OpenGL.hpp>
#include <glm\glm.hpp>
#include <iostream>


#define Log std::cout

namespace KECS{
	struct Vec3f
	{
		float x;
		float y;
		float z;

		Vec3f()
		{
		}

		Vec3f(float _x, float _y, float _z)
		{
			x = _x;
			y = _y;
			z = _z;
		}
	};
	SystemDisplay::SystemDisplay(GLdouble newWidth, GLdouble newHeight, sf::String newWindowTitle)
	{
		windowTitle = newWindowTitle;
		width = newWidth;
		height = newHeight;
	}


	SystemDisplay::~SystemDisplay()
	{
	}

	void SystemDisplay::Init(){
		SystemBase::Init();

		GLenum      err;

		Log << "[Display System]Start" << std::endl;

		if ((err = glewInit()) != GLEW_OK)
			Log << glewGetErrorString(err) << std::endl;

		Log << "[Display System]Init window" << std::endl;

		sf::ContextSettings settings;
		settings.depthBits = 24;
		settings.stencilBits = 8;
		settings.antialiasingLevel = 2; // Optional

		window = new sf::Window(sf::VideoMode((int)width, (int)height), windowTitle, sf::Style::Close, settings);
		//window2 = new sf::Window(sf::VideoMode(400, 400), "OpenGL 2", sf::Style::Close, settings);
		//window = windowt;

		Log << "[Display System]Test 2" << std::endl;
		if ((err = glewInit()) != GLEW_OK)
			Log << glewGetErrorString(err) << std::endl;

		Log << "[Display System]opengl test" << std::endl;
		fprintf(stdout, "[Display System]Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

		if (GLEW_VERSION_1_1){
			Log << "[Display System]Yay! OpenGL 1.1 is supported!" << std::endl;
		}
		if (GLEW_VERSION_1_2){
			Log << "[Display System]Yay! OpenGL 1.2 is supported!" << std::endl;
		}
		if (GLEW_VERSION_3_0){
			Log << "[Display System]Yay! OpenGL 3.0 is supported!" << std::endl;
		}

		//opengl 2d

		//glOrtho(-1.0, 1.0, -1.0, 1.0, 5, 100);
		//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
		glOrtho(-(width / 2.0), (width / 2.0), -(height / 2.0), (height / 2.0), -100.0, 100.0);

		//opengl 3d

		/*
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		GLfloat fovY = 60;
		GLfloat aspect = 100;
		GLfloat zNear = 0;
		GLfloat zFar = 2;
		fH = tan(fovY / 360 * pi) * zNear;
		fW = fH * aspect;
		gluPerspective(45.0f, (GLfloat)640 / (GLfloat)480, 0.1f, 10.0f);
		glMatrixMode(GL_MODELVIEW);

		*/

		// shader
		//GLuint ShaderProgram = glCreateProgram();
		//GLuint shaderVert = glCreateShader(GL_VERTEX_SHADER);
		//GLuint shaderFrag = glCreateShader(GL_FRAGMENT_SHADER);
		KECS::Utils::OpenGLUtil::CompileShaders();

		// test quad
		Vec3f Vertices[6];
		Vertices[0] = Vec3f(-1.0f, -1.0f, 0.0f);
		Vertices[1] = Vec3f(1.0f, -1.0f, 0.0f);
		Vertices[2] = Vec3f(-1.0f, 1.0f, 0.0f);
		Vertices[3] = Vec3f(-1.0f, 1.0f, 0.0f);
		Vertices[4] = Vec3f(1.0f, -1.0f, 0.0f);
		Vertices[5] = Vec3f(1.0f, 1.0f, 0.0f);

		glGenBuffers(1, &vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
			);

		window->setActive();

		glEnableVertexAttribArray(0);
		//glDisableVertexAttribArray(0);

		if (*entitys == NULL){
			std::cout << "[Display System] entity NULL" << std::endl;
		}

		UpdateSpriteList();
	}


	// TODO		:	should be updated every frame but is to slow
	// FORNOW	:	for now has to be call manually after a entity with a ComponentSprite and a ComponentTransform is created
	//				or if a ComponentSprite and a ComponentTransform is added to an existing entity
	//				or if a ComponentSprite or a ComponentTransform is destroyed or removed
	void SystemDisplay::UpdateSpriteList(){
		sprites = new ComponentSprite*[*entityCount];
		transforms = new ComponentTransform*[*entityCount];
		for (int i = 0; i < *entityCount; i++){
			sprites[i] = (ComponentSprite*)((*entitys)[i]->GetComponent(ID_COMPONENT_SPRITE));
			transforms[i] = (ComponentTransform*)((*entitys)[i]->GetComponent(ID_COMPONENT_TRANSFORM));
		}
	}

	void SystemDisplay::Update(){


		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Log << "[Display System] entityCount:" << *entityCount << std::endl;
		//Log << "[Display System] update" << std::endl;

		for (int i = 0; i < *entityCount; i++){
			DrawSprite(sprites[i], transforms[i]);
		}
		window->display();
	}

	float r = 0;

	sf::Vector3f spritePos;
	sf::Vector3f spriteRot;
	sf::Vector3f spriteScale;

	void SystemDisplay::DrawSprite(ComponentSprite* sprite, ComponentTransform* trans){
		

		spritePos = trans->position();
		spriteRot = trans->rotation();
		spriteScale = trans->scale();
		//glTranslatef(spritePos.x, spritePos.y, spritePos.z);

		static float ScaleSize = 0.025;

		float RadianRotation = KECS::Common::ToRadian(spriteRot.z);
	
		// Z transform and scale matrix
		KECS::Utils::Matrix4f ScaleEnTrans;
		ScaleEnTrans.m[0][0] = sinf(ScaleSize);		ScaleEnTrans.m[0][1] = 0.0f;				ScaleEnTrans.m[0][2] = 0.0f;				ScaleEnTrans.m[0][3] = (spritePos.x / (width/2));
		ScaleEnTrans.m[1][0] = 0.0f;				ScaleEnTrans.m[1][1] = sinf(ScaleSize);		ScaleEnTrans.m[1][2] = 0.0f;				ScaleEnTrans.m[1][3] = (spritePos.y / (height/2));
		ScaleEnTrans.m[2][0] = 0.0f;				ScaleEnTrans.m[2][1] = 0.0f;				ScaleEnTrans.m[2][2] = sinf(ScaleSize);		ScaleEnTrans.m[2][3] = (spritePos.z / 200.0);
		ScaleEnTrans.m[3][0] = 0.0f;				ScaleEnTrans.m[3][1] = 0.0f;				ScaleEnTrans.m[3][2] = 0.0f;				ScaleEnTrans.m[3][3] = 1.0f;

		// Z rotateion matrix
		KECS::Utils::Matrix4f Rot;
		Rot.m[0][0] = cosf(RadianRotation); Rot.m[0][1] = -sinf(RadianRotation); Rot.m[0][2] = 0.0f; Rot.m[0][3] = 0.0f;
		Rot.m[1][0] = sinf(RadianRotation); Rot.m[1][1] = cosf(RadianRotation); Rot.m[1][2] = 0.0f; Rot.m[1][3] = 0.0f;
		Rot.m[2][0] = 0.0f; Rot.m[2][1] = 0.0f; Rot.m[2][2] = 1.0f; Rot.m[2][3] = 0.0f;
		Rot.m[3][0] = 0.0f; Rot.m[3][1] = 0.0f; Rot.m[3][2] = 0.0f; Rot.m[3][3] = 1.0f;


		KECS::Utils::Matrix4f World = ScaleEnTrans*Rot;

		glUniformMatrix4fv(KECS::Utils::gWorldLocation, 1, GL_TRUE, &World.m[0][0]);

		//glRotatef(spriteRot.x, 1, 0, 0);
		//glRotatef(spriteRot.y, 0, 1, 0);
		//glRotatef(spriteRot.z, 0, 0, 1);
		//glScalef(spriteScale.x, spriteScale.y, spriteScale.z);

		//glPushMatrix();

		

		glDrawArrays(GL_TRIANGLES, 0, 6);


		glPopMatrix();
	}

	bool SystemDisplay::pollEvent(sf::Event& sfEvent){
		return window->pollEvent(sfEvent);
	}
}

#include "..\KECS.h"

#include <iostream>

using namespace std;

namespace KECS{
	namespace Utils{

		GLuint gWorldLocation;
		//GLuint gScaleLocation;

		const char* pVSFileName = "shader.vs.txt";
		const char* pFSFileName = "shader.fs.txt";

		void OpenGLUtil::AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
		{
			GLuint ShaderObj = glCreateShader(ShaderType);

			if (ShaderObj == 0) {
				fprintf(stderr, "Error creating shader type %d\n", ShaderType);
				exit(0);
			}

			const GLchar* p[1];
			p[0] = pShaderText;
			GLint Lengths[1];
			Lengths[0] = strlen(pShaderText);
			glShaderSource(ShaderObj, 1, p, Lengths);
			glCompileShader(ShaderObj);
			GLint success;
			glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
			if (!success) {
				GLchar InfoLog[1024];
				glGetShaderInfoLog(ShaderObj, 1024, NULL, InfoLog);
				fprintf(stderr, "Error compiling shader type %d: '%s'\n", ShaderType, InfoLog);
				exit(1);
			}

			glAttachShader(ShaderProgram, ShaderObj);
		}

		void OpenGLUtil::CompileShaders()
		{
			GLuint ShaderProgram = glCreateProgram();

			if (ShaderProgram == 0) {
				fprintf(stderr, "Error creating shader program\n");
				exit(1);
			}

			string vs, fs;

			if (!KECS::Common::ReadFile(pVSFileName, vs)) {
				exit(1);
			};

			if (!KECS::Common::ReadFile(pFSFileName, fs)) {
				exit(1);
			};

			AddShader(ShaderProgram, vs.c_str(), GL_VERTEX_SHADER);
			AddShader(ShaderProgram, fs.c_str(), GL_FRAGMENT_SHADER);

			GLint Success = 0;
			GLchar ErrorLog[1024] = { 0 };

			glLinkProgram(ShaderProgram);
			glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);
			if (Success == 0) {
				glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
				fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
				exit(1);
			}

			glValidateProgram(ShaderProgram);
			glGetProgramiv(ShaderProgram, GL_VALIDATE_STATUS, &Success);
			if (!Success) {
				glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
				fprintf(stderr, "Invalid shader program: '%s'\n", ErrorLog);
				exit(1);
			}

			glUseProgram(ShaderProgram);

			gWorldLocation = glGetUniformLocation(ShaderProgram, "gWorld");
			assert(gWorldLocation != 0xFFFFFFFF);
		}
	}
}
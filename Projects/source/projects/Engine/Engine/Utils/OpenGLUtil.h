#ifndef UTILS_ENGINE_OPENGL_H
#define UTILS_ENGINE_OPENGL_H

namespace KECS{
	namespace Utils{
		//extern GLuint gScaleLocation;
		extern GLuint gWorldLocation;

		class Matrix4f
		{
		public:
			float m[4][4];

			Matrix4f()
			{
			}

			inline void InitIdentity()
			{
				m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
				m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
				m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
				m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
			}

			inline Matrix4f operator*(const Matrix4f& Right) const
			{
				Matrix4f Ret;

				for (unsigned int i = 0; i < 4; i++) {
					for (unsigned int j = 0; j < 4; j++) {
						Ret.m[i][j] = m[i][0] * Right.m[0][j] +
							m[i][1] * Right.m[1][j] +
							m[i][2] * Right.m[2][j] +
							m[i][3] * Right.m[3][j];
					}
				}

				return Ret;
			}
		};

		class OpenGLUtil
		{
		public:

			static void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
			static void CompileShaders();
		};
	}
}

#endif	/* UTILS_ENGINE_COMMON_H */
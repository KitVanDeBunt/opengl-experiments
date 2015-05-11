#include <GL/glew.h>
#include "object.h"
#include <glm/glm.hpp>
using namespace glm;
#include <vector>
#include "myTypes.h"

#include <stdio.h>
#include <iostream>
#include <string.h>




char objLocation[] = "media/models/";
//http://elf-stone.com/glee.php
// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/
//http://julianibarz.wordpress.com/2010/05/12/glew-1-5-4-mingw32/
//https://launchpad.net/glew-cmake/+milestone/1.10.0


static const GLfloat g_vertex_buffer_data[] = { 
    -1.0f, -1.0f,
     1.0f, -1.0f,
    -1.0f,  1.0f,
     1.0f,  1.0f
};
static const GLushort g_element_buffer_data[] = { 0, 1, 2, 3 };


Object::Object(std::string fileName, float ix, float iy, float iz,DrawType drawType_ = NewNormal){
	drawType = drawType_;
	vertices = 0;
	x = ix;
	y = iy;
	z = iz;
	//temp_vertices.clear();
	//vertexIndices.clear();
	
	const char *charFileName = fileName.c_str();
	
	char objLoc[80];
	strcpy (objLoc,objLocation); 
	strcat  (objLoc,charFileName); 
	puts (objLoc);
	int l = 0;
	FILE * file = fopen(objLoc, "r");
	if( file == NULL ){
		printf("Impossible to open the file !\n");
	}
	printf("file loaded: %s \n",objLoc);
	while( 1 ){
		l++;
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		printf("res: %d eof: %d l: %d \n",res, EOF,l);
		if (res == EOF){
			break; // EOF = End Of File. Quit the loop.
		}else if ( strcmp( lineHeader, "v" ) == 0 ){
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
			temp_vertices.push_back(vertex);
		}else if ( strcmp( lineHeader, "f" ) == 0 ){
			//std::string vertex1, vertex2, vertex3;
			float vertexIndex[3], uvIndex[3], normalIndex[3];
			float matches = fscanf(file, "%f %f %f\n", &vertexIndex[0], &vertexIndex[1], &vertexIndex[2]);
			if (matches != 3){
				printf("L: %d  File can't be read by our simple parser : ( Try exporting with other options)  \n",matches);
			}else{
				//printf(":):):):)");
			}
			vertexIndices.push_back(vertexIndex[0]-1);
			vertexIndices.push_back(vertexIndex[1]-1);
			vertexIndices.push_back(vertexIndex[2]-1);
			vertices+=1;
			//uvIndices    .push_back(uvIndex[0]);
			//uvIndices    .push_back(uvIndex[1]);
			//uvIndices    .push_back(uvIndex[2]);
			//normalIndices.push_back(normalIndex[0]);
			//normalIndices.push_back(normalIndex[1]);
			//normalIndices.push_back(normalIndex[2]);
		}
	}
	/*
	for (int l = 0; l < vertexIndices.size(); l++){
		int i = l;
		printf("n:%d to:%d x:%f y:%f z:%f\n"
			, i 
			, vertexIndices[i]
			, temp_vertices[vertexIndices[i]].x
			, temp_vertices[vertexIndices[i]].y 
			, temp_vertices[vertexIndices[i]].z
		);
	}*/
	printf("size:%d\n", temp_vertices.size());
	printf("pre gen\n");
	
	glGenBuffers(1, &vertexbuffer);
	
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	
	glBufferData(GL_ARRAY_BUFFER, temp_vertices.size() * sizeof(glm::vec3), &temp_vertices[0], GL_STATIC_DRAW);
	
	glGenBuffers(1, &elementbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexIndices.size() * sizeof(unsigned int), &vertexIndices[0], GL_STATIC_DRAW);
	
	/*
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	
	glGenBuffers(1, &elementbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_element_buffer_data), g_element_buffer_data, GL_STATIC_DRAW);
	*/
	float elements = (vertexIndices.size()+1)*3;
	printf("elements %f /n",elements);
}

/*
static const GLfloat g_vertex_buffer_data[] = { 
    -1.0f, -1.0f,
     1.0f, -1.0f,
    -1.0f,  1.0f,
     1.0f,  1.0f
};
static const GLushort g_element_buffer_data[] = { 0, 1, 2, 3 };
*/


float r = 0;
void Object::draw(){
	if(drawType == NewNormal){
		glPushMatrix();
		r+=0.2f;
			
		glTranslatef(x,y,z);
		glRotatef(r,0,1,0);
		glScalef(0.4f,0.4f,0.4f);
			
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
		   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		   3,                  // size
		   GL_FLOAT,           // type
		   GL_FALSE,           // normalized?
		   0,                  // stride
		   (void*)0            // array buffer offset
		);
		 
		// Draw the triangle !
		//glDrawArrays(GL_TRIANGLE_STRIP, 0, vertices); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
		glDrawElements(
			GL_TRIANGLES,  // mode 
		   // 6,                  // count 
		   (vertexIndices.size()+1)*3, //count
			GL_UNSIGNED_SHORT,  // type 
			(void*)0            // element array buffer offset 
		);
		
		glDisableVertexAttribArray(0);
		glPopMatrix();
	}else{
		glPushMatrix();
			r+=0.2f;
			
			glTranslatef(x,y,z);
			glRotatef(r,0,1,0);
			glScalef(0.4f,0.4f,0.4f);
			//glBegin(GL_TRIANGLES);
			//glBegin(GL_LINES);
			if(0){
				for (int i = 0; i < vertexIndices.size(); i+=3){
					glBegin(GL_LINES);
						glVertex3f(temp_vertices[vertexIndices[i]].x,   temp_vertices[vertexIndices[i]].y , temp_vertices[vertexIndices[i]].z);
						glVertex3f(temp_vertices[vertexIndices[i+1]].x,   temp_vertices[vertexIndices[i+1]].y , temp_vertices[vertexIndices[i+1]].z);
						glVertex3f(temp_vertices[vertexIndices[i+2]].x,   temp_vertices[vertexIndices[i+2]].y , temp_vertices[vertexIndices[i+2]].z);
						glVertex3f(temp_vertices[vertexIndices[i]].x,   temp_vertices[vertexIndices[i]].y , temp_vertices[vertexIndices[i]].z);
					glEnd();
				}
			}else{
				for (int i = 0; i < vertexIndices.size(); i+=3){
				glBegin(GL_TRIANGLES);
					glVertex3f(temp_vertices[vertexIndices[i]].x,   temp_vertices[vertexIndices[i]].y , temp_vertices[vertexIndices[i]].z);
					glVertex3f(temp_vertices[vertexIndices[i+1]].x,   temp_vertices[vertexIndices[i+1]].y , temp_vertices[vertexIndices[i+1]].z);
					glVertex3f(temp_vertices[vertexIndices[i+2]].x,   temp_vertices[vertexIndices[i+2]].y , temp_vertices[vertexIndices[i+2]].z);
				glEnd();
			}
			}
		glPopMatrix();
	}
	
	
}









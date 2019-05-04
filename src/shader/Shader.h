//
// Created by xhh on 5/1/19.
//

#ifndef STORYBOARD_PLAYER_SHADER_H
#define STORYBOARD_PLAYER_SHADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:
    GLuint id;
public:
    Shader(const char *vertexPath, const char *fragmentPath);

    ~Shader();

    virtual void use();

    void setMat4(const GLint &location, const glm::mat4 &mat4);

    void setVec4(const GLint &location, const GLfloat &v0, const GLfloat &v1, const GLfloat &v2, const GLfloat &v3);

    void setVec4(const GLint &location, const glm::vec4 &vec4);

    void setVec3(const GLint &location, const GLfloat &v0, const GLfloat &v1, const GLfloat &v2);

    void setVec3(const GLint &location, const glm::vec3 &vec3);

    void setVec2(const GLint &location, const GLfloat &v0, const GLfloat &v1);

    void setVec2(const GLint &location, const glm::vec2 &vec2);

    void setFloat(const GLint &location, const GLfloat &v0);

    void setInt(const GLint &location, const GLint &v0);

    void setBool(const GLint &location, const GLboolean &v0);

private:
    void checkCompileError(GLuint shader);

    void checkLinkError(GLuint program);
};


#endif //STORYBOARD_PLAYER_SHADER_H

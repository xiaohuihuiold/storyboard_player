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
    GLuint  id;
public:
    Shader(const char *vertexPath,const char *fragmentPath);

    void use();
private:
    void checkCompileError(GLuint shader);
    void checkLinkError(GLuint program);
};


#endif //STORYBOARD_PLAYER_SHADER_H

//
// Created by xhh on 5/3/19.
//

#ifndef STORYBOARD_PLAYER_SPRITESHADER_H
#define STORYBOARD_PLAYER_SPRITESHADER_H

#include "Shader.h"

class SpriteShader : public Shader {
public:
    SpriteShader(const char *vertexPath, const char *fragmentPath);

    ~SpriteShader();

    void scale(const GLfloat &w, const GLfloat &h);

private:
    void setModel(const glm::mat4 &mat4);

    void setView(const glm::mat4 &mat4);

    void setProjection(const glm::mat4 &mat4);

public:
    int width;
    int height;
private:
    GLint modelLocation;
    GLint viewLocation;
    GLint projectionLocation;
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
};


#endif //STORYBOARD_PLAYER_SPRITESHADER_H

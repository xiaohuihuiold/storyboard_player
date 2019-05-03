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

    void setModel(const glm::mat4 &mat4);

    void setView(const glm::mat4 &mat4);

    void setProjection(const glm::mat4 &mat4);

private:
    GLint modelLocation;
    GLint viewLocation;
    GLint projectionLocation;
};


#endif //STORYBOARD_PLAYER_SPRITESHADER_H

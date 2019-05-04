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

    void use() override;

    void setModel(const glm::mat4 &mat4);

    void setView(const glm::mat4 &mat4);

    void setProjection(const glm::mat4 &mat4);

    void setColor(const glm::vec3 &color);

    void setAlpha(const GLfloat &alpha);

private:
    // 声明着色器变量location
    GLint modelLocation;
    GLint viewLocation;
    GLint projectionLocation;
    GLint alphaLocation;
    GLint colorLocation;
    // 初始化矩阵
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::ortho(-107.0f, 747.0f, 0.0f, 480.0f);
};


#endif //STORYBOARD_PLAYER_SPRITESHADER_H

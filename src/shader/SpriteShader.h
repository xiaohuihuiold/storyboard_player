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

    void setScale(const GLfloat &w, const GLfloat &h);

    void setAlpha(const GLfloat &alpha);

    void setAngle(const GLfloat &angle);

    void setXY(const GLfloat &x, const GLfloat &y);

    void setColor(const glm::vec3 &color);

    void draw();

    void use() override;

private:
    void setModel(const glm::mat4 &mat4);

    void setView(const glm::mat4 &mat4);

    void setProjection(const glm::mat4 &mat4);

public:
    int width = 0;
    int height = 0;
    GLuint texture = 0;
private:
    // 声明图片属性
    GLfloat scaleW = 1.0f;
    GLfloat scaleH = 1.0f;
    GLfloat alpha = 1.0f;
    GLfloat angle = 0.0f;
    GLfloat x = 0.0f;
    GLfloat y = 0.0f;
    glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
    // 声明着色器变量location
    GLint modelLocation;
    GLint viewLocation;
    GLint projectionLocation;
    GLint alphaLocation;
    GLint colorLocation;
    // 初始化矩阵
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::ortho(-107.0f, 747.0f, 0.0f, 480.0f);
};


#endif //STORYBOARD_PLAYER_SPRITESHADER_H

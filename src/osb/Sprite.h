//
// Created by xhh on 5/4/19.
//

#ifndef STORYBOARD_PLAYER_SPRITE_H
#define STORYBOARD_PLAYER_SPRITE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include "../shader/SpriteShader.h"

enum Origin {
    TOP_LEFT,
    TOP_CENTER,
    TOP_RIGHT,
    CENTER_LEFT,
    CENTER,
    CENTER_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_CENTER,
    BOTTOM_RIGHT
};

class Sprite {
public:

    void setScaleW(const GLfloat &w);

    void setScaleH(const GLfloat &h);

    void setAlpha(const GLfloat &alpha);

    void setAngle(const GLfloat &angle);

    void setX(const GLfloat &x);

    void setY(const GLfloat &y);

    void setColor(const glm::vec3 &color);

    void draw(SpriteShader *shader);

public:
    int width = 0;
    int height = 0;
    Origin origin = CENTER;
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
    // 初始化矩阵
    glm::mat4 model = glm::mat4(1.0f);
};


#endif //STORYBOARD_PLAYER_SPRITE_H

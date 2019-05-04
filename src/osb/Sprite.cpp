//
// Created by xhh on 5/4/19.
//

#include "Sprite.h"

void Sprite::setScaleW(const GLfloat &w) {
    this->scaleW = w;
}

void Sprite::setScaleH(const GLfloat &h) {
    this->scaleH = h;
}

void Sprite::setAlpha(const GLfloat &alpha) {
    this->alpha = alpha;
}

void Sprite::setAngle(const GLfloat &angle) {
    this->angle = angle;
}

void Sprite::setX(const GLfloat &x) {
    this->x = x;
}

void Sprite::setY(const GLfloat &y) {
    this->y = y;
}

void Sprite::setColor(const glm::vec3 &color) {
    this->color = color;
}

void Sprite::draw(SpriteShader *shader) {
    shader->use();
    glm::mat4 temp = model;
    temp = glm::translate(temp, glm::vec3(x, 480.0f - y, 0.0f));
    temp = glm::scale(temp, glm::vec3(scaleW * width, scaleH * height, 1.0f));
    temp = glm::rotate(temp, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));

    shader->setModel(temp);
    shader->setColor(color);
    shader->setAlpha(alpha);

    glBindTexture(GL_TEXTURE_2D, texture);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

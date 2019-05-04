//
// Created by xhh on 5/4/19.
//

#include "Sprite.h"

void Sprite::setScale(const GLfloat &w, const GLfloat &h) {
    this->scaleW = w;
    this->scaleH = h;
}

void Sprite::setAlpha(const GLfloat &alpha) {
    this->alpha = alpha;
}

void Sprite::setAngle(const GLfloat &angle) {
    this->angle = angle;
}

void Sprite::setXY(const GLfloat &x, const GLfloat &y) {
    this->x = x;
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

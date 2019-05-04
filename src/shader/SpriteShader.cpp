//
// Created by xhh on 5/3/19.
//

#include "SpriteShader.h"

SpriteShader::SpriteShader(const char *vertexPath, const char *fragmentPath) : Shader(vertexPath, fragmentPath) {
    modelLocation = glGetUniformLocation(id, "model");
    viewLocation = glGetUniformLocation(id, "view");
    projectionLocation = glGetUniformLocation(id, "projection");
    alphaLocation = glGetUniformLocation(id, "alpha");
    colorLocation = glGetUniformLocation(id, "color");
}

SpriteShader::~SpriteShader() {

}

void SpriteShader::setScale(const GLfloat &w, const GLfloat &h) {
    this->scaleW = w;
    this->scaleH = h;
}

void SpriteShader::setAlpha(const GLfloat &alpha) {
    this->alpha = alpha;
}

void SpriteShader::setAngle(const GLfloat &angle) {
    this->angle = angle;
}

void SpriteShader::setXY(const GLfloat &x, const GLfloat &y) {
    this->x = x;
    this->y = y;
}

void SpriteShader::setColor(const glm::vec3 &color) {
    this->color = color;
}

void SpriteShader::setModel(const glm::mat4 &mat4) {
    setMat4(modelLocation, mat4);
}

void SpriteShader::setView(const glm::mat4 &mat4) {
    setMat4(viewLocation, mat4);
}

void SpriteShader::setProjection(const glm::mat4 &mat4) {
    setMat4(projectionLocation, mat4);
}

void SpriteShader::draw() {
    glm::mat4 temp = model;
    temp = glm::translate(temp, glm::vec3(x, 480.0f - y, 0.0f));
    temp = glm::scale(temp, glm::vec3(scaleW * width, scaleH * height, 1.0f));
    temp = glm::rotate(temp, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));

    setModel(temp);
    setVec3(colorLocation, color);
    setFloat(alphaLocation, alpha);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void SpriteShader::use() {
    Shader::use();

    setView(view);
    setProjection(projection);
    glBindTexture(GL_TEXTURE_2D, texture);
}


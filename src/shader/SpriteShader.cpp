//
// Created by xhh on 5/3/19.
//

#include "SpriteShader.h"

SpriteShader::SpriteShader(const char *vertexPath, const char *fragmentPath) : Shader(vertexPath, fragmentPath) {
    // 正射投影,没必要用透视投影
    projection = glm::ortho(0.0f, 1200.0f, 0.0f, 720.0f, 0.0f, 100.0f);

    modelLocation = glGetUniformLocation(id, "model");
    viewLocation = glGetUniformLocation(id, "view");
    projectionLocation = glGetUniformLocation(id, "projection");

}

SpriteShader::~SpriteShader() {

}

void SpriteShader::scale(const GLfloat &w, const GLfloat &h) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, glm::vec3(w, h, 1.0f));
    setModel(model);
    setView(view);
    setProjection(projection);
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


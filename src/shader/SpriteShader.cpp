//
// Created by xhh on 5/3/19.
//

#include "SpriteShader.h"

SpriteShader::SpriteShader(const char *vertexPath, const char *fragmentPath) : Shader(vertexPath, fragmentPath) {
    modelLocation = glGetUniformLocation(id, "model");
    viewLocation = glGetUniformLocation(id, "view");
    projectionLocation = glGetUniformLocation(id, "projection");
}

SpriteShader::~SpriteShader() {

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

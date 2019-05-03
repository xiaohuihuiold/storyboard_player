//
// Created by xhh on 5/1/19.
//

#include "Shader.h"

Shader::Shader(const char *vertexPath, const char *fragmentPath) {
    std::string vertexStr;
    std::string fragmentStr;

    std::ifstream vertexFile;
    std::ifstream fragmentFile;

    vertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        vertexFile.open(vertexPath);
        fragmentFile.open(fragmentPath);

        std::stringstream vertexStream;
        std::stringstream fragmentStream;

        vertexStream << vertexFile.rdbuf();
        fragmentStream << fragmentFile.rdbuf();

        vertexFile.close();
        fragmentFile.close();

        vertexStr = vertexStream.str();
        fragmentStr = fragmentStream.str();
    } catch (std::ifstream::failure &e) {
        perror(e.what());
    }

    const char *vertexSource = vertexStr.c_str();
    const char *fragmentSource = fragmentStr.c_str();

    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    glCompileShader(vertexShader);
    checkCompileError(vertexShader);

    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentShader);
    checkCompileError(fragmentShader);

    this->id = glCreateProgram();
    glAttachShader(this->id, vertexShader);
    glAttachShader(this->id, fragmentShader);
    glLinkProgram(this->id);
    checkLinkError(this->id);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader() {

}

void Shader::use() {
    glUseProgram(this->id);
}

void Shader::checkCompileError(GLuint shader) {
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cout << "着色器编译失败:" << infoLog << std::endl;
    }
}

void Shader::checkLinkError(GLuint program) {
    int success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cout << "着色器程序链接出错:" << infoLog << std::endl;
    }
}

void Shader::setMat4(const GLint &location, const glm::mat4 &mat4) {
    glUniformMatrix4fv(location, 1, GL_FALSE, &mat4[0][0]);
}

void
Shader::setVec4(const GLint &location, const GLfloat &v0, const GLfloat &v1, const GLfloat &v2, const GLfloat &v3) {
    glUniform4f(location, v0, v1, v2, v3);
}

void Shader::setVec4(const GLint &location, const glm::vec4 &vec4) {
    glUniform4fv(location, 1, &vec4[0]);
}

void Shader::setVec3(const GLint &location, const GLfloat &v0, const GLfloat &v1, const GLfloat &v2) {
    glUniform3f(location, v0, v1, v2);
}

void Shader::setVec3(const GLint &location, const glm::vec3 &vec3) {
    glUniform3fv(location, 1, &vec3[0]);
}

void Shader::setVec2(const GLint &location, const GLfloat &v0, const GLfloat &v1) {
    glUniform2f(location, v0, v1);
}

void Shader::setVec2(const GLint &location, const glm::vec2 &vec2) {
    glUniform2fv(location, 1, &vec2[0]);
}

void Shader::setFloat(const GLint &location, const GLfloat &v0) {
    glUniform1f(location, v0);
}

void Shader::setInt(const GLint &location, const GLint &v0) {
    glUniform1i(location, v0);
}

void Shader::setBool(const GLint &location, const GLboolean &v0) {
    glUniform1i(location, (GLint) v0);
}
#include <iostream>
#include <vector>
#include <thread>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader/SpriteShader.h"
#include "stb_image/stb_image.h"
#include "osb/Sprite.h"

#define WINDOW_TITLE "Storyboard Player"

#define SPRITE_VERTEX_SHADER "../assets/shader/sprite_vertex.glsl"
#define SPRITE_FRAGMENT_SHADER "../assets/shader/sprite_fragment.glsl"

void refresh_fps();

void key_input(GLFWwindow *);

void framebuffer_size_callback(GLFWwindow *, int, int);

Sprite *loadTexture(const char *);

int WINDOW_WIDTH = 1708;
int WINDOW_HEIGHT = 960;

long currentTime = 0;
std::vector<Sprite *> sprites;

volatile int frames = 0;
volatile int fps = 0;
volatile bool refresh_is_run = true;
std::thread fpsThread(refresh_fps);

GLfloat vertices[] = {
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
};


int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, nullptr, nullptr);
    if (window == nullptr) {
        perror("窗口创建失败");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        perror("glad初始化失败");
        glfwTerminate();
        return -1;
    }
    // 可有可无
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    SpriteShader *spriteShader = new SpriteShader(SPRITE_VERTEX_SHADER, SPRITE_FRAGMENT_SHADER);
    for (int i = 0; i < 100; i++) {
        Sprite *sprite = loadTexture("../assets/flutter.png");
        sprites.push_back(sprite);
    }

    // 储存顶点数据
    GLuint spriteVBO;
    glGenBuffers(1, &spriteVBO);
    glBindBuffer(GL_ARRAY_BUFFER, spriteVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 处理顶点数据
    GLuint spriteVAO;
    glGenVertexArrays(1, &spriteVAO);
    glBindVertexArray(spriteVAO);
    glBindBuffer(GL_ARRAY_BUFFER, spriteVBO);
    // 读取顶点坐标
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // 读取纹理坐标
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    while (!glfwWindowShouldClose(window)) {

        currentTime = (long) (glfwGetTime() * 1000.0f);
        key_input(window);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // 去掉深度测试
        glDepthMask(false);

        glBindVertexArray(spriteVAO);

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                Sprite *sprite = sprites[i * j];
                sprite->setScaleW(0.5f);
                sprite->setScaleH(0.5f);
                sprite->setX(i * 40.0f);
                sprite->setY(j * 40.0f);
                sprite->setColor(glm::vec3(float(i * j) / 100.0f, float(i) / 10.0f, float(j) / 10.0f));
                sprite->draw(spriteShader);
            }
        }

        glDepthMask(true);
        glfwSwapBuffers(window);
        glfwPollEvents();
        frames++;
    }

    for (int i = 0; i < sprites.size(); i++) {
        delete sprites[i];
    }
    sprites.clear();
    delete spriteShader;

    refresh_is_run = false;
    fpsThread.join();

    glfwTerminate();
    return 0;
}

void refresh_fps() {
    while (refresh_is_run) {
        fps = frames;
        frames = 0;
        std::cout << "fps:" << fps << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void key_input(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;
}

Sprite *loadTexture(const char *path) {
    GLuint texture;
    // 生成材质
    glGenTextures(1, &texture);
    // 绑定材质
    glBindTexture(GL_TEXTURE_2D, texture);

    // 加载并生成纹理
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (data) {
        GLenum format = 3;
        if (nrChannels == 1)
            format = GL_RED;
        else if (nrChannels == 3)
            format = GL_RGB;
        else if (nrChannels == 4)
            format = GL_RGBA;
        // 生成纹理
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        // 生成mipmap
        glGenerateMipmap(GL_TEXTURE_2D);
        // 设置环绕方式 重复
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // 设置过滤方式 线性
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // 释放资源
        stbi_image_free(data);
    } else {
        std::cout << "材质加载失败" << std::endl;
    }

    Sprite *sprite = new Sprite();
    sprite->setWidth(width);
    sprite->setHeight(height);
    sprite->setTexture(texture);
    return sprite;
}
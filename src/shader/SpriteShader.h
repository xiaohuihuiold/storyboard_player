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
};


#endif //STORYBOARD_PLAYER_SPRITESHADER_H

//
// Created by nig3l on 07/01/2020.
//

#include "TextureFactory.h"

TextureFactory TextureFactory::INSTANCE = TextureFactory();
unsigned int TextureFactory::NUMBER_OF_TEXTURE = 2;

TextureFactory &TextureFactory::getInstance() {
    return INSTANCE;
}

TextureFactory::TextureFactory() {
    this->indexOfTexture = 0;
}

void TextureFactory::init() {
    INSTANCE.textures.emplace_back(new Texture("../resources/img/blue_logo.jpg"));
    INSTANCE.textures.emplace_back(new Texture("../resources/img/white_logo.jpg"));
}

Texture *TextureFactory::get() {
    this->indexOfTexture = (this->indexOfTexture + 1) % NUMBER_OF_TEXTURE;
    return this->textures[indexOfTexture];
}

TextureFactory::~TextureFactory() {
    for (Texture *textPtr : this->textures) {
        delete textPtr;
    }
    this->textures.clear();
    this->textures.shrink_to_fit();
}

//
// Created by wasku on 19-8-20.
//

#ifndef LEARNOPENGL_GLUTILFUNCTION_H
#define LEARNOPENGL_GLUTILFUNCTION_H

#include <jmorecfg.h>
#include "std_afx.h"

NAMESPACE_GL_BEGIN
//for loading a 2D texture from file
unsigned int loadTexture(char const *path,float& pic_width,float& pic_height);

// Generates a texture that is suited for attachments to a framebuffer
unsigned int generateAttachmentTexture(boolean depth, boolean stencil,unsigned int width,unsigned int height);
NAMESPACE_END


#endif //LEARNOPENGL_GLUTILFUNCTION_H

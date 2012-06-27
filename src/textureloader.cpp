/**
 *  WordGL
 *  Copyright (C) 2012  Viktor Was <viktor.was@technikum-wien.at>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef __APPLE__
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

#include <stdlib.h>
#include <unistd.h>
#include <vector>

#include "textureloader.h"
#include "imageloader.h"


namespace WordGL {
    
    // initialize static member variable with null
    TextureLoader* TextureLoader::loaderInstance = NULL;
    //Segmentation fault?
    //std::vector<GLuint> _textureId;
    GLuint _textureId;
    /**
    * Creates the TextureLoader
    */
    TextureLoader::TextureLoader (){
        TextureLoader::loaderInstance = this;
    }
    
    //NOTICE: load multiple at once with glGenTextures(TEX_COUNT, &_textureId[0]);
    //Makes the image into a mipmapped texture, and returns the id of the texture
    GLuint TextureLoader::loadMipmappedTexture(Image *image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	gluBuild2DMipmaps(GL_TEXTURE_2D,
			GL_RGB,
			image->width, image->height,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			image->pixels);
	return textureId;
    }

    //TODO: load multiple at once
    //Initializes rendering (enables macros) and creates textures
    void TextureLoader::initRendering(){
	// initialize rendering	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	
	glEnable(GL_TEXTURE_2D);
	
	//TODO: multiples with wrapper method with loop;
	//NOTICE: DONT CHANGE loadBMP ==>dont change loadMipmappedTexture either!
	Image* image = loadBMP("resources/textures/a.bmp");
	//Segmentation fault?
	//_textureId.push_back(loadMipmappedTexture(image));
	_textureId = loadMipmappedTexture(image);
	delete image;
    }

    /**
    * Returns a static instance of the TextureLoader.
    * @return The TextureLoader instance
    */
    TextureLoader* TextureLoader::getInstance(){
        return TextureLoader::loaderInstance;
    }


    TextureLoader::~TextureLoader(){

    }

}

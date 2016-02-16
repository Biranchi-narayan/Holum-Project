//
//
//  Project : Holum
//  File Name : File.cpp
//  Date : 13/02/2016
//
//

#include <Global.h>
#include <File.h>

File::File() {}

File::File(string path, string title) {
	this->path = path;
	this->title = title;
	this->thumbnailPath = (workingPath + "Video/") + title + ".png";
	init();
}

void File::init() {
	rectWidth = 480;
	rectHeight = 720;

	if (!thumbnailTexture.loadFromFile(thumbnailPath)) {
        #ifdef DEBUG
            cout << "Errore 005: Caricamento texture copertina '" << title << "' non riuscito." << endl;
        #endif
		thumbnailPath = workingPath + "/" + "defaultThumbnail.png";
        if (!thumbnailTexture.loadFromFile(thumbnailPath)) {
            #ifdef DEBUG
                cout << "Errore 008: Caricamento texture copertina di default non riuscito." << endl;
            #endif
        }
	}
	thumbnail = RectangleShape(Vector2f(rectWidth, rectHeight));
	FloatRect thumbnailBounds = thumbnail.getGlobalBounds();
	thumbnail.setOrigin(thumbnailBounds.left + (thumbnailBounds.width / 2.0f), thumbnailBounds.top + (thumbnailBounds.height / 2.0f));
	thumbnail.setPosition(Vector2f(width / 2, height / 2));
}

void File::setPath(string path) {
	this->path = path;
}

string File::getPath() {
	return path;
}

void File::setThumbnailPath(string thumbnailPath) {
	this->thumbnailPath = thumbnailPath;
}

string File::getThumbnailPath() {
	return thumbnailPath;
}

void File::setTitle(string Title) {
	this->title = Title;
}

string File::getTitle() {
	return title;
}

RectangleShape* File::getThumbnail() {
	return &thumbnail;
}

Texture* File::getThumbnailTexture() {
	return &thumbnailTexture;
}

void File::setThumbnailSize(float x, float y) {
	thumbnail.setSize(Vector2f(x, y));
}

void File::setThumbnailPosition(float x, float y) {
	thumbnail.setPosition(Vector2f(x, y));
}

Vector2f File::getThumbnailSize() {
	return Vector2f(thumbnail.getGlobalBounds().width, thumbnail.getGlobalBounds().height);
}

void File::setThumbnailScale(float x, float y) {
	thumbnail.setScale(Vector2f(x, y));
}

void File::moveThumbnail(float x, float y) {
	thumbnail.move(x, y);
}
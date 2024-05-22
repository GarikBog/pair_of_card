#ifndef OBJECT
#include "object.h"
#define OBJECT
#endif


/// OBJECT

/// other
Object::Object(float x, float y, int w, int h, std::string texture_file){
	Set_pos(x, y);
	Set_size(w, h);
	Set_texture(texture_file);
}

void Object::Draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
void Tick(sf::Time tick) {
}



///Setters
void Object::Set_pos(float x, float y){
	this->x = x;
	this->y = y;

	sprite.setPosition(x, y);

}
void Object::Set_size(int w, int h){
	this->w = w;
	this->h = h;

	sprite.setTextureRect(sf::IntRect(0, 0, w, h));
}
void Object::Set_texture(std::string texture_file){
	if (!texture.loadFromFile(texture_file)) {
		throw std::exception("Texture file is not found");
	}
	this->texture_file = texture_file;

	sprite.setTexture(texture);
}



///Getters
std::pair<float, float> Object::Get_size() const{
	return std::pair<float, float>(x, y);
}
std::pair<int, int> Object::Get_pos() const{
	return std::pair<int, int>(w, h);

}
std::string Object::Get_texture() const{
	return texture_file;
}










/// BUTTON STAFCHIK

bool Button::Mouse_on(float mx, float my) {
	float x = Get_pos().first, y = Get_pos().second;
	int w = Get_size().first, h = Get_size().second;

	return (mx > x && mx<x + w && my > y && my < y + h);
}








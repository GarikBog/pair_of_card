#ifndef OBJECT
#include "object.h"
#define OBJECT
#endif


/// OBJECT

/// other
Object::Object(int x, int y, int w, int h, std::string texture_file){
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
void Object::Set_pos(int x, int y){
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
std::pair<int, int> Object::Get_size() const{
	return std::pair<int, int>(w, h);
}
std::pair<int, int> Object::Get_pos() const{
	return std::pair<int, int>(x, y);

}
std::string Object::Get_texture() const{
	return texture_file;
}
sf::Sprite Object::GetSprite() const {
	return sprite;
}











/// BUTTON STAFCHIK

bool Button::Mouse_on(int mx, int my) {
	int x = Get_pos().first, y = Get_pos().second;
	int w = Get_size().first, h = Get_size().second;

	return (mx > x && mx<x + w && my > y && my < y + h);
}

void Button::Do(int mx, int my) {
	if (Mouse_on(mx, my)) {
		ButtonFunction();
	}
}

Button::Button(int x, int y, int w, int h, std::string texture_file, std::function<void()> foo) :Object(x, y, w, h, texture_file), ButtonFunction(foo) {
		
}



/// TEXT BUTTON

TextButton::TextButton(int x, int y, int w, std::string texture_file, std::function<void()> foo, std::string text, std::string font) : Button(x, y, w, 0.4*w, texture_file, foo) {
	Set_font(font);
	Set_text(text);

	outline_texture.loadFromFile("textures/outline.jpg");
	outline.setTexture(outline_texture);
	outline.setTextureRect(sf::IntRect(0,0,w + 14, 0.4*w + 14));
	outline.setPosition(x - 7, y - 7);
	this->text.setCharacterSize(0.3*w);
	this->text.setPosition(x+ 0.25*w, y);

	this->text.setFillColor(sf::Color::Green);


}

void TextButton::Draw(sf::RenderWindow& window,sf::Vector2i mouse_pos) {
	if (Mouse_on(mouse_pos.x, mouse_pos.y)) {
		window.draw(outline);
	}
	Object::Draw(window);
	window.draw(text);

}

void TextButton::Set_font(std::string font) {

	if (!this->font.loadFromFile(font)) {
		throw std::exception("Font file is not found");
	}

	text.setFont(this->font);

}

void TextButton::Set_text(std::string text) {
	this->text.setString(text);

}

void TextButton::Set_char_size(unsigned int size) {
	text.setCharacterSize(size);
}







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

int Size_of_text(std::string str,int w) {
	double ans = 0;
	for (char c : str) {
		switch (c)
		{
		case('t'):
			ans += 0.28;
			break;
		case('e'):
			ans += 0.51;
		case('q'):
			ans += 0.49;
			break;
		case('w'):
			ans += 0.74;
			break;
		case('r'):
			ans += 0.31;
			break;
		case('y'):
			ans += 0.76;
			break;
		case('u'):
			ans += 0.45;
			break;
		case('i'):
			ans += 0.21;
			break;
		case('o'):
			ans += 0.58;
			break;
		case('p'):
			ans += 0.53;
			break;
		case('a'):
			ans += 0.54;
			break;
		case('s'):
			ans += 0.5;
			break;
		case('d'):
			ans += 0.5;
			break;
		case('f'):
			ans += 0.28;
			break;
		case('g'):
			ans += 0.53;
			break;
		case('h'):
			ans += 0.5;
			break;
		case('j'):
			ans += 0.28;
			break;
		case('k'):
			ans += 0.52;
			break;
		case('l'):
			ans += 0.16;
			break;
		case('z'):
			ans += 0.51;
			break;
		case('x'):
			ans += 0.52;
			break;
		case('c'):
			ans += 0.49;
			break;
		case('v'):
			ans += 0.52;
			break;
		case('b'):
			ans += 0.54;
			break;
		case('n'):
			ans += 0.34;
			break;
		case('m'):
			ans += 0.78;
			break;
		default:
			ans += 0.5;
			break;
		}
	}
	return ((ans * w)+0.5);
}

/// TEXT BUTTON

TextButton::TextButton(int x, int y, int w, std::string texture_file, std::function<void()> foo, std::string text, std::string font) : Button(x, y, w, 0.4*w, texture_file, foo) {
	Set_font(font);
	Set_text(text);

	outline_texture.loadFromFile("textures/outline.jpg");
	outline.setTexture(outline_texture);
	outline.setTextureRect(sf::IntRect(0,0,w + 14, 0.4*w + 14));
	outline.setPosition(x - 7, y - 7);
	int size = Size_of_text(text, 0.3*w);
	this->text.setCharacterSize(0.3*w);
	this->text.setPosition(x+w/2 - size/2, y);

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







#ifndef SF_GRAFIC
#include <SFML/Graphics.hpp>
#define SF_GRAFIC
#endif

#ifndef FUNCTIONAL
#include<functional>
#define FUNCTIONAL
#endif // !FUNCTIONAL



class Object
{
private:
	int x, y;
	int w, h;
	sf::Texture texture;
	sf::Sprite sprite;
	std::string texture_file;

public:

	Object(int x, int y, int w, int h, std::string texture_file);
	void Draw(sf::RenderWindow& window);

	void Set_pos(int x, int y);
	void Set_size(int w, int h);
	void Set_texture(std::string texture_file);


	std::pair<int, int> Get_size() const;
	std::pair<int, int> Get_pos() const;
	std::string Get_texture() const;
	sf::Sprite GetSprite() const;

};


class Button : public Object {
private:
	std::function<void()> ButtonFunction;
public:
	Button(int x, int y, int w, int h, std::string texture_file, std::function<void()> foo);
	bool Mouse_on(int mx, int my);
	void Do(int mx, int my);
}; 



class TextButton : public Button {
private:
	sf::Text text;
	sf::Font font;
	sf::Texture outline_texture;
	sf::Sprite outline;
public:
	TextButton(int x, int y, int w,std::string texture_file, std::function<void()> foo, std::string text,std::string font);
	void Draw(sf::RenderWindow& window, sf::Vector2i mouse_pos);



	void Set_text(std::string text);
	void Set_font(std::string font);
	void Set_char_size(unsigned int size);


};


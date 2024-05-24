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
	float x, y;
	int w, h;
	sf::Texture texture;
	sf::Sprite sprite;
	std::string texture_file;

public:

	Object(float x, float y, int w, int h, std::string texture_file);
	void Draw(sf::RenderWindow& window);
	void Tick(sf::Time tick);

	void Set_pos(float x, float y);
	void Set_size(int w, int h);
	void Set_texture(std::string texture_file);


	std::pair<float, float> Get_size() const;
	std::pair<int, int> Get_pos() const;
	std::string Get_texture() const;

};


class Button : public Object {
private:
	std::function<void()> ButtonFunction;
public:
	Button(float x, float y, int w, int h, std::string texture_file, std::function<void()> foo);
	bool Mouse_on(float mx, float my);
	void Do(float mx, float my);
}; 



class TextButton : public Button {
private:
	sf::Text text;
	sf::Font font;
	sf::Texture outline_texture;
	sf::Sprite outline;
public:
	TextButton(float x, float y, int w, int h, std::string texture_file, std::function<void()> foo, std::string text,std::string font);

	void Set_text(std::string text);
	void Set_font(std::string font);
	void Set_char_size(unsigned int size);

};


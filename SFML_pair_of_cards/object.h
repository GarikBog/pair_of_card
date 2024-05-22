#ifndef SF_GRAFIC
#include <SFML/Graphics.hpp>
#define SF_GRAFIC
#endif


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

public:
	virtual bool Do();
	bool Mouse_on(float mx, float my);
};


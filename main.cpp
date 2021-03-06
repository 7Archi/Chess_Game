#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream> 
#include "map.h"

using namespace sf;

std::stringstream toString(int val)
{
	std::stringstream ss;
	ss << val;
	return ss;
}

//===========================================================================================
//CLASS_FIGURE
//===========================================================================================
class figure
{
public:
	int pass=0;
	int value;
	float step = 50, w=50, h=50;
	float x, y;
	String file_name;
	Image image;
	Texture texture;
	Sprite sprite;
	Text text;
	bool isSelect;
	figure() 
	{
		bool isSelect = false;
	};
	void initial(String Value, float X, float Y)
	{
		value = Value[0];
		pass = 1;
		image.loadFromFile("Animations/"+Value+"_0.png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y-5;
	    sprite.setTextureRect(IntRect(0, 0, 50, 50));
		sprite.setPosition(x, y);
		text.setCharacterSize(16);
		text.setFillColor(Color::Black);
		text.setString("");
		text.setPosition(x+25, y-25);
	}
	void settext(String str)
	{
		text.setString(str);
	}
};

//==========================================================================================
//MAIN
//==========================================================================================
int main()
{
	Font font;//����� 
	font.loadFromFile("Windsor.ttf");//�������� ������ ������ ���� ������
	Text text;//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
	//text.setFillColor(Color::Red);//��������� ����� � �������. ���� ������ ��� ������, �� �� ��������� �� �����
	text.setFont(font);
	text.setCharacterSize(14);
	text.setString("");
	text.setFillColor(Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	Image map_image;
	Texture map;
	Sprite s_map;
	map_image.loadFromFile("Animations/map.png");
	map.loadFromImage(map_image);
	s_map.setTexture(map);
	figure figure[32];
	int trigger_map = 0, trigger_figure = -1;
	int ch_figure = 0, i_mch, j_mch;
	int xbase = 1280, ybase = 720;
	int *xwin, *ywin;
	xwin = &xbase;
	ywin = &ybase;
	bool mousec = false;
	sf::RenderWindow window(VideoMode( *xwin, *ywin ), "Chess", sf::Style::Fullscreen);
	while (window.isOpen())
	{
		ch_figure = 0;
		Vector2i wPos = Mouse::getPosition(window);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if ((event.key.code == Mouse::Left) && (mousec == false))
			{
				mousec = true;
				if (trigger_figure == -1)
				{
					for (int i = 0; i < 32; i++)
						if (figure[i].sprite.getGlobalBounds().contains(wPos.x, wPos.y))
						{
							trigger_figure = i;
							figure[i].sprite.setColor(Color(100, 100, 100));
						}
				}
				else
				{
					for (int i = 0; i < 32; i++)
						if (figure[i].sprite.getGlobalBounds().contains(wPos.x, wPos.y))
						{
							if (trigger_figure == i)
							{
								figure[i].sprite.setColor(Color(255, 255, 255));
							}
							trigger_figure = -1;
						}

				}
			}
			if (event.type == Event::MouseButtonReleased)
				if (event.key.code == Mouse::Left)
					mousec = false;
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		i_mch = 0;
		j_mch = 0;
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == '0')
				{
					s_map.setTextureRect(IntRect(0, 0, 50, 50)); //���� ��������� ������ ������, �� ������ 1� ���������
					trigger_map = 0;
				}
				if (TileMap[i][j] == 'w')
				{
					s_map.setTextureRect(IntRect(50, 0, 50, 50));//���� ��������� ������ s, �� ������ 2� ���������
					trigger_map = 1;
				}
				if ((TileMap[i][j] == 'b'))
				{
					s_map.setTextureRect(IntRect(100, 0, 50, 50));//���� ��������� ������ 0, �� ������ 3� ���������
					trigger_map = 1;
				}
				s_map.setPosition(j * 50, i * 50);
				if ((trigger_map == 1)&&(i_mch<8))
				{
					if (FigureMap[i_mch][j_mch] != '0')
					{
						figure[ch_figure].initial((FigureMap[i_mch][j_mch]), 50 * j, 50 * i);
						figure[ch_figure].text.setFont(font);
						ch_figure++;
					}
					j_mch++;
					if (j_mch > 7)
					{
						i_mch++;
						j_mch = 0;
					}
				}
				window.draw(s_map);
			}
		for (int i = 0; i <= 32; i++)
			if (figure[i].pass == 1)
			{
				window.draw(figure[i].sprite);
				window.draw(figure[i].text);
			}
		window.display();
	}
	return 0;
}
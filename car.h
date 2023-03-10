#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"

struct Player {
	sf::Texture texture;
	sf::Sprite sprite;
	float speedx;
};

void playerInit(Player& player) {
	player.texture.loadFromFile(PLAYER_FILE_NAME);
	player.sprite.setTexture(player.texture);
	player.sprite.setPosition(PLAYER_START_POS);
	player.speedx = 0.f;
}

void playerControl(Player& player) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player.speedx = -CAR_SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player.speedx = CAR_SPEED;
	player.sprite.move(player.speedx, 0.f);
	player.speedx = 0.f;
}

void playerReboundEdges(Player& player) {
	float playerx = player.sprite.getPosition().x;
	float playery = player.sprite.getPosition().y;
	if (playerx >= RIGHT_ROADSIDE - PLAYER_WIDTH)
		player.sprite.setPosition(RIGHT_ROADSIDE - PLAYER_WIDTH, playery);
	if(playerx <= LEFT_ROADSIDE)
		player.sprite.setPosition(LEFT_ROADSIDE, playery);
}

void playerUpdate(Player& player) {
	playerControl(player);
	playerReboundEdges(player);
}

void playerDraw(sf::RenderWindow& window, const Player& player) {
	window.draw(player.sprite);
}

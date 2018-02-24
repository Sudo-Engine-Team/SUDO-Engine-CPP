/*
 * main.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: Timothy
 */
#include "../src/Application.h"
#include <GLFW/glfw3.h>
#include <iostream>

using namespace SUDO;

class MainScreen : public Screen{
public:
	void init() override {

	}
	void update(float delta) override {

	}
	void render() override {

	}
	void dispose() override {

	}
};

int main(){
	Application* app = new Application(900, 900/16*9, "Hello world");
	app->setScreen(new MainScreen());

	app->run();
	return 0;
}

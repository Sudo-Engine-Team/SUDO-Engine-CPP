/*
 * Appication.h
 *
 *  Created on: Feb 23, 2018
 *      Author: Timothy
 */
#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
#include "Screen.h"

namespace SUDO{
	class Application{
	private:
		GLFWwindow* window;
		const char* title;
		int width;
		int height;
		Screen* screen;
	public:
		Application(int width, int height, const char* title){
			this->height = height;
			this->width = width;
			this->title = title;
			this->window = NULL;
			this->screen = NULL;
		};

		void run(){
			if(!glfwInit()){
				std::cout << "Failed to create GLFW context" << std::endl;
				return;
			}
			this->window = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);
			glfwMakeContextCurrent(window);

			this->screen->init();

			while(!glfwWindowShouldClose(this->window)){
				this->screen->update(0);
				this->screen->render();
				/* Swap front and back buffers */
				glfwSwapBuffers(window);

				/* Poll for and process events */
				glfwPollEvents();
			}
			this->screen->dispose();
			glfwDestroyWindow(this->window);
			glfwTerminate();
		};

		GLFWwindow* getWindow(){
			return this->window;
		};

		void setScreen(Screen* screen){
			this->screen = screen;
		}

		void close(){
			glfwSetWindowShouldClose(this->window, GLFW_TRUE);
		};
	};
};

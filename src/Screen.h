/*
 * Screen.h
 *
 *  Created on: Feb 23, 2018
 *      Author: Timothy
 */
#pragma once

namespace SUDO{
	class Screen{
		public:
			virtual void init() = 0;
			virtual void update(float delta) = 0;
			virtual void render() = 0;
			virtual void dispose() = 0;
	};
};

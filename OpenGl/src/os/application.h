#pragma once

namespace vx {

	class Application {
	public:
		virtual void init()		= 0;
		virtual void logic()	= 0;
		virtual void draw()		= 0;
		virtual void close()	= 0;
	};

};
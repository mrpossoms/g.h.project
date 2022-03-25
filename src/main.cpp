#include "g.h"
#include "state.hpp"

struct game : public g::core
{

	g::asset::store assets;
	game::state state;

	game() = default;
	~game() = default;

	virtual bool initialize()
	{
		return true;
	}

	virtual void update(float dt)
	{

	}

};

#ifdef __EMSCRIPTEN__
EM_JS(int, canvas_get_width, (), {
  return document.getElementById('canvas').width;
});

EM_JS(int, canvas_get_height, (), {
  return document.getElementById('canvas').height;
});
#endif

int main (int argc, const char* argv[])
{
	game my_game;

	g::core::opts opts;

	opts.name = "my game";
	opts.gfx.fullscreen = false;

#ifdef __EMSCRIPTEN__
	auto monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);

	opts.gfx.width = canvas_get_width();
	opts.gfx.height = canvas_get_height();
#else
	opts.gfx.fullscreen = false;
#endif

	my_game.start(opts);

	return 0;
}

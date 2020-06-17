#include "mvpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Minerva {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}
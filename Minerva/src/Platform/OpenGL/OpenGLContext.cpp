#include "mvpch.h"

#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Minerva {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		MV_CORE_ASSERT(windowHandle, "GLFW window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MV_CORE_ASSERT(status, "Failed to initialize Glad!");

		MV_CORE_INFO("Initialized OpenGL context:");
		MV_CORE_INFO("    Renderer: {0}", glGetString(GL_RENDERER));
		MV_CORE_INFO("    Vendor: {0}", glGetString(GL_VENDOR));
		MV_CORE_INFO("    Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_WindowHandle);
	}

}
#include "mvpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Minerva {

	static GLenum ShaderDataTypeToGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
			case Minerva::ShaderDataType::Float: return GL_FLOAT;
			case Minerva::ShaderDataType::Float2: return GL_FLOAT;
			case Minerva::ShaderDataType::Float3: return GL_FLOAT;
			case Minerva::ShaderDataType::Float4: return GL_FLOAT;
			case Minerva::ShaderDataType::Mat3: return GL_FLOAT;
			case Minerva::ShaderDataType::Mat4: return GL_FLOAT;
			case Minerva::ShaderDataType::Int: return GL_INT;
			case Minerva::ShaderDataType::Int2: return GL_INT;
			case Minerva::ShaderDataType::Int3: return GL_INT;
			case Minerva::ShaderDataType::Int4: return GL_INT;
			case Minerva::ShaderDataType::Bool: return GL_BOOL;
		}

		MV_CORE_ASSERT(false, "Unknown shader data type!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) 
	{
		MV_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex buffer has no layout.");
		
		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : vertexBuffer->GetLayout())
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.GetComponentCount(),
				ShaderDataTypeToGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) 
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

}
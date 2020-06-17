#include <Minerva.h>

#include "imgui/imgui.h"

class ExampleLayer : public Minerva::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.0f, 1.0f, -1.0f, 1.0f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Minerva::VertexArray::Create());

		float vertices[7 * 3] = {
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f
		};

		std::shared_ptr<Minerva::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Minerva::VertexBuffer::Create(vertices, sizeof(vertices)));

		Minerva::BufferLayout layout = {
			{ Minerva::ShaderDataType::Float3, "a_Position" },
			{ Minerva::ShaderDataType::Float4, "a_Color" }
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[3] = { 0, 1, 2 };
		std::shared_ptr<Minerva::IndexBuffer> indexBuffer;
		indexBuffer.reset(Minerva::IndexBuffer::Create(indices, 3));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		float squareVerts[3 * 4] = {
			 0.2f,  0.2f,  0.0f,
			 0.55f, 0.2f,  0.0f,
			 0.55f, 0.8f,  0.0f,
			 0.2f,  0.8f,  0.0f,
		};

		m_SquareVA.reset(Minerva::VertexArray::Create());
		std::shared_ptr<Minerva::VertexBuffer> squareVB;
		squareVB.reset(Minerva::VertexBuffer::Create(squareVerts, sizeof(squareVerts)));

		Minerva::BufferLayout layout2 = {
			{ Minerva::ShaderDataType::Float3, "a_Position" }
		};
		squareVB->SetLayout(layout2);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Minerva::IndexBuffer> squareIB;
		squareIB.reset(Minerva::IndexBuffer::Create(squareIndices, 6));

		m_SquareVA->AddVertexBuffer(squareVB);
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSource = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			out vec3 v_Position;
			out vec4 v_Color;

			uniform mat4 u_ViewProjection;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}

		)";

		std::string fragmentSource = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = v_Color;
			}

		)";

		std::string vertexSource2 = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			out vec3 v_Position;

			uniform mat4 u_ViewProjection;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}

		)";

		std::string fragmentSource2 = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(0.8f, 0.2f, 0.2f, 1.0f);
			}

		)";

		m_Shader.reset(new Minerva::Shader(vertexSource, fragmentSource));
		m_Shader2.reset(new Minerva::Shader(vertexSource2, fragmentSource2));
	}

	void OnUpdate() override
	{
		Minerva::RenderCommand::Clear(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
		
		Minerva::Renderer::BeginScene(m_Camera);

		if (Minerva::Input::IsKeyPressed(MV_KEY_LEFT)) m_CameraPosition.x -= m_CameraSpeed;
		if (Minerva::Input::IsKeyPressed(MV_KEY_RIGHT)) m_CameraPosition.x += m_CameraSpeed;
		if (Minerva::Input::IsKeyPressed(MV_KEY_DOWN)) m_CameraPosition.y -= m_CameraSpeed;
		if (Minerva::Input::IsKeyPressed(MV_KEY_UP)) m_CameraPosition.y += m_CameraSpeed;

		if (Minerva::Input::IsKeyPressed(MV_KEY_A)) m_CameraRotation += m_CameraSpeed;
		if (Minerva::Input::IsKeyPressed(MV_KEY_D)) m_CameraRotation -= m_CameraSpeed;

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Minerva::Renderer::Submit(m_Shader2, m_SquareVA);
		Minerva::Renderer::Submit(m_Shader, m_VertexArray);

		Minerva::Renderer::EndScene();
	}

	void OnImGuiRender() override
	{
	}

	void OnEvent(Minerva::Event& event) override
	{
	}

private:
	std::shared_ptr<Minerva::Shader> m_Shader;
	std::shared_ptr<Minerva::VertexArray> m_VertexArray;

	std::shared_ptr<Minerva::Shader> m_Shader2;
	std::shared_ptr<Minerva::VertexArray> m_SquareVA;

	glm::vec3 m_CameraPosition;
	float m_CameraSpeed = 0.05f;
	float m_CameraRotation = 0.0f;

	Minerva::OrthoCamera m_Camera;
};

class Sandbox : public Minerva::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Minerva::Application* Minerva::CreateApplication()
{
	return new Sandbox();
}
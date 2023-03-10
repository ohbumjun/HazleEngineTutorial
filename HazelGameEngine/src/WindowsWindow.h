#pragma once

#include "Hazel/Window.h"

#include <GLFW/glfw3.h>

namespace Hazel
{
	class WindowsWindow : public Window
	{
	public :
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window Attribute
		virtual void SetEventCallback(const EventCallbackFn& callback) override
		{
			m_Data.EventCallback = callback;
		}
		void SetVSync(bool enabled);
		bool IsVSync() const;
	private :
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private :
		GLFWwindow* m_Window;

		// 아래 struct 는 GLFW 에 넘겨주기 위한 데이터이다.
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			// Application.h 의 OnEvent 가 여기에 세팅될 것이다.
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}



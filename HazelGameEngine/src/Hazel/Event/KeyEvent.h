#pragma once

#include "Event.h"
#include <sstream>

namespace Hazel
{
	// Key 와 관련된 Event 들의 Base Class
	class HAZEL_API KeyEvent : public Event
	{
	public :
		inline int GetKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyBoard | EventCategoryInput)
	
	protected :
		KeyEvent(int keycode) :
			m_KeyCode(keycode){}
	
		int m_KeyCode;
	};

	class HAZEL_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount) :
			KeyEvent(keycode), m_RepeatCount(repeatCount){}
		
		inline int GetKeyCode() const { return m_KeyCode; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent : " << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return ss.str();
		};

		EVENT_CLASS_TYPE(KeyPressed);

	private:
		int m_RepeatCount;
	};

	class HAZEL_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode, int repeatCount) :
			KeyEvent(keycode){}

		inline int GetKeyCode() const { return m_KeyCode; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent : " << m_KeyCode;
			return ss.str();
		};

		EVENT_CLASS_TYPE(KeyReleased);
	};
}
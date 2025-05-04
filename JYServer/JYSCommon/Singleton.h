#pragma once

template<typename T>
class Singleton
{
public:
	static T& GetInstance()
	{
		static T g_instance{};
		return g_instance;
	}

protected:
	Singleton() = default;

public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	virtual ~Singleton() = default;
};
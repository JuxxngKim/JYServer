#pragma once

#define NEW(cls, ...)			std::make_shared<cls>(__VA_ARGS__)
#define PTR						std::shared_ptr
#define UNIQUE_NEW(cls, ...)	std::make_unique<cls>(__VA_ARGS__)
#define UNIQUE_PTR				std::uniqueptr
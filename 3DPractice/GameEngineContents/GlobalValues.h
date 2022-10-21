#pragma once

// Ό³Έν :
class GlobalValues
{
public:
	// constrcuter destructer
	GlobalValues();
	~GlobalValues();

	// delete Function
	GlobalValues(const GlobalValues& _Other) = delete;
	GlobalValues(GlobalValues&& _Other) noexcept = delete;
	GlobalValues& operator=(const GlobalValues& _Other) = delete;
	GlobalValues& operator=(GlobalValues&& _Other) noexcept = delete;

protected:

private:

};

enum class CollisionGroup
{
	Player,
	Map,
};
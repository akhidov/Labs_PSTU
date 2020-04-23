#pragma once

struct fraction
{
	unsigned int first;
	unsigned int second;
	void Init(unsigned int, unsigned int);
	void Read();
	void Show();
	void iPart(unsigned int, unsigned int);
};
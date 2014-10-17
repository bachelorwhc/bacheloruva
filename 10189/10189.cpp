#include <iostream>
#include <string>

struct Map
{
	Map(unsigned short w, unsigned short h) :
		width(w),
		height(h)
	{
		m = new bool [w*h];
		mv = new unsigned short[w*h];
		for(int i = 0; i < w*h; ++i)
			mv[i] = 0;
		for(int i = 0; i < w*h; ++i)
			m[i] = false;
	}
	~Map()
	{
		delete[] m;
		delete[] mv;
	}
	
	void SetMine(unsigned x, unsigned y)
	{
		m[width * y + x] = true;
	}

	void ConstructValue()
	{
		for(int y = 0; y < height; ++y)
		{
			for(int x = 0; x < width; ++x)
			{
				if(m[width * y + x])
				for(int dx = -1; dx < 2; ++dx)
				{
					for(int dy = -1; dy < 2; ++dy)
					{
						if(dx == 0 && dy == 0)
							continue;
						if((x + dx < 0 || x + dx >= width) || (y + dy < 0 || y + dy >= height))
							continue;
						++mv[width * (y + dy) + x + dx];
					}
				}
			}
		}
	}

	void Display()
	{
		for(int y = 0; y < height; ++y)
		{
			for(int x = 0; x < width; ++x)
			{
				if(m[width * y + x])
					std::cout << '*';
				else
					std::cout << mv[width * y + x];
			}
			std::cout << std::endl;
		}
	}

	bool* m;
	unsigned short int* mv;
	unsigned short width;
	unsigned short height;
};

int main()
{
	unsigned short w, h;
	unsigned short id = 1;
	bool first(true);
	while(std::cin >> h >> w)
	{
		if(w == 0 && h == 0)
			return 0;
		Map m(w, h);
		std::string s;
		for(int i = 0; i < h; ++i)
		{
			std::cin >> s;
			for(int j = 0; j < w; ++j)
				if(s[j]=='*')
					m.SetMine(j, i);
		}
		m.ConstructValue();
		if(!first)
		{
			std::cout << std::endl;
		}
		else
			first = !first;
		std::cout << "Field #" << id++ << ':' << std::endl;
		m.Display();
		
	}
	return 0;
}
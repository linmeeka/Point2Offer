#include<cstring>
#include<cstdio>

class A {
private:
	A()
	{
		pthread_mutex_init(&mtx, 0);
	}
	static A *a;
public:
	static pthread_mutex_t mtx;
	static A* getInstance()
	{
		if (a == NULL)
		{
			pthread_mutex_lock(&mtx);
			a = new A();
			pthread_mutex_unlock(&mtx);
		}
		return a;
	}
};

class B
{
private:
	static B *b;
public:
	static B* getInstance()
	{
		return b;
	}
};

int main()
{

}
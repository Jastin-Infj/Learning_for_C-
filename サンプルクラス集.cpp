/**
* @file ���.cpp
* @brief ��{���Z�p�Ҏ����̖��΍��p���P�ɂ܂Ƃ߂��t�@�C���ł�
* @author Jastin
* @date 2018/12/25
* @par  History
- 2018/12/25 ���� ���
- 3����Vector�N���X�̒ǉ�
*/

#include <iostream>
#include <Windows.h>
namespace Common
{
	namespace Math
	{
		template<typename TYPE>
		class Vector3
		{
			TYPE x, y, z;
		public:
			template<typename TYPE>
			Vector3(const TYPE typeX, const TYPE typeY, const TYPE typeZ)
			{
				this->x = typeX;
				this->y = typeY;
				this->z = typeZ;
			}
			Vector3()
			{
				this->x = 0;
				this->y = 0;
				this->z = 0;
			}
			Vector3 operator+(const Vector3& vector)
			{
				double x, y, z;
				x = this->x + vector.x;
				y = this->y + vector.y;
				z = this->z + vector.z;
				return Vector3<double>(x,y,z);
			}
			Vector3 operator-(const Vector3& vector)
			{
				double x, y, z;
				x = this->x - vector.x;
				y = this->y - vector.y;
				z = this->z - vector.z;
				return Vector3<double>(x, y, z);
			}
			Vector3 operator*(const Vector3& vector)
			{
				double x, y, z;
				x = this->x * vector.x;
				y = this->y * vector.y;
				z = this->z * vector.z;
				return Vector3<double>(x, y, z);
			}
			Vector3 operator/(const Vector3& vector)
			{
				double x, y, z;
				x = vector.x != 0 ? this->x / vector.x :  vector.x;
				y = vector.y != 0 ? this->y / vector.y :  vector.y;
				z = vector.z != 0 ? this->z / vector.z :  vector.z;
				return Vector3<double>(x, y, z);
			}
			//���K�����s���܂�
			Vector3 Normalize()
			{
				double Squarelength = this->Length();

				Vector3<double> unit = *this;

				Squarelength = 1.0 / Squarelength;

				unit.x *= Squarelength;
				unit.y *= Squarelength;
				unit.z *= Squarelength;

				return unit;
			}
			//���������߂܂�
			double Length()
			{
				double x, y, z;
				x = this->x;
				y = this->y;
				z = this->z;
				return std::sqrt(this->Inside());
			}
			void Output()const
			{
				std::cout << "x: " << this->x << "  ";
				std::cout << "y: " << this->y << "  ";
				std::cout << "z: " << this->z << "  ";
			}
			//���ς����߂܂�
			static double Inside(Vector3* a ,Vector3* b)
			{
				return a->x * b->x + a->y * b->y + a->z * b->z;
			}
			//�O�ς����߂܂�
			static Vector3 Outside(Vector3* a, Vector3* b)
			{
				Vector3<double> outside;
				outside.x = a->y * b->z - a->z * b->y;
				outside.y = a->z * b->x - a->x * b->z;
				outside.z = a->x * b->y - a->y * b->x;
				return outside;
			}
		};
		class Vector2
		{
			Vector2()
			{

			}
		};
	}
	namespace Input
	{
		class Keyboard
		{

		};
	};
}
namespace Sample
{
	class Kadai1
	{
	public:
		Kadai1()
		{

		}
	};
};
int main()
{
	Common::Math::Vector3<double> vector1(1, 2, 3);
	Common::Math::Vector3<double> vector2(4, 5, 6);
	Common::Math::Vector3<double> total;
	total = Common::Math::Vector3<double>::Outside(&vector1, &vector2);
	std::cout << " �O �� " << std::endl;
	total.Output();
	system("pause");
}
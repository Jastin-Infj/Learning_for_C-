/**
* @file 問題.cpp
* @brief サンプルクラス集をまとめた関数です
* @author Jastin
* @date 2018/12/25
* @par  History
- 2018/12/25 横尾 拓実
- 3次元Vectorクラスの追加
- 2018/12/26 横尾 拓実
- 再起関数の基本復習問題を追加　
*/

#include <iostream>
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
			template<typename TYPE>
			void Setx(TYPE x)
			{
				this->x = x;
			}
			template<typename TYPE>
		    TYPE Getx()const
			{
				return this->x;
			}
			template<typename TYPE>
			void Sety(TYPE y)
			{
				this->y = y;
			}
			template<typename TYPE>
			TYPE Gety()const
			{
				return this->y;
			}
			template<typename TYPE>
			void Setz(TYPE z)
			{
				this->z = z;
			}
			template<typename TYPE>
			TYPE Getz()const
			{
				return this->z;
			}
			//正規化を行います
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
			//長さを求めます
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
			//内積を求めます
			static double Inside(Vector3* a ,Vector3* b)
			{
				return a->x * b->x + a->y * b->y + a->z * b->z;
			}
			//外積を求めます
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
	using namespace Common::Math;
	class RecurrenceFunction
	{
	public:
		static void Sample1(Vector3<double>* counter)
		{	
			if(counter->Getx<double>() <= 0.0)
			{
				return;
			}
			Vector3<double> vector(1, 1, 1);
			vector = *counter - vector;
			Sample1(&vector);
			counter->Output();
			std::cout << std::endl;
		}
	};
};
int main()
{
	Common::Math::Vector3<double> vector(10, 10, 10);
	Sample::RecurrenceFunction::Sample1(&vector);
	system("pause");
}
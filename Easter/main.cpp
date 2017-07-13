#include <iostream>
#include <fstream>
#include "Bucket.h"


int main()
{
	Bucket bucket0, bucket1, bucket2;
	Egg newEgg, second, third;
	newEgg.setEggName("new");
	newEgg.setEggSize(5);
	second.setEggName("second");
	second.setEggSize(10);
	third.setEggName("third");
	third.setEggSize(2);
	bucket1.addEgg(newEgg);
	bucket1.addEgg(second);
	bucket1.addEgg(third);
	bucket1.setOwnerName("second_bucket");
	bucket0.addEgg(newEgg);
	bucket0.setOwnerName("first_bucket");
	bucket2.addEgg(third);
	bucket2.addEgg(second);
	bucket2.setOwnerName("third_bucket");
	for (int i = 0; i < 3; i++)
		std::cout << "Egg name: " << bucket1.getEggByIndex(i).getEggName() << " size: " << bucket1.getEggByIndex(i).getEggSize() << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	char* name = new char[7];
	strcpy(name, "second");
	bucket1.removeEgg(name);
	for (int i = 0; i < 2; i++)
		std::cout << "Egg name: " << bucket1.getEggByIndex(i).getEggName() << " size: " << bucket1.getEggByIndex(i).getEggSize() << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	Bucket* buckets = new Bucket[3];
	buckets[0] = bucket0;
	buckets[1] = bucket1;
	buckets[2] = bucket2;
	Bucket* deser = new Bucket[3];
	int cnt = 0;
	Bucket one, two, three;
	one = bucket0 + bucket1;
	/*one.deserializeBucket("first");
	two.deserializeBucket("second");
	three.deserializeBucket("third");
	one.report();
	two.report();
	three.report();*/
	std::cout << "Bucket name: " << bucket0.getOwnerName() << " Size: " << bucket0.getSize() <<
		" Capacity: " << bucket0.getCapacity() << std::endl << "Eggs: " << std::endl;
	for (int i = 0; i < bucket0.getSize(); i++)
		std::cout << "Egg[" << i << "] - " << "Name: " << bucket0.getEggByIndex(i).getEggName() <<
		" Size: " << bucket0.getEggByIndex(i).getEggSize() << std::endl;
	//bucket0 *= 5;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Bucket name: " << bucket1.getOwnerName() << " Size: " << bucket1.getSize() <<
		" Capacity: " << bucket1.getCapacity() << std::endl << "Eggs: " << std::endl;
	for (int i = 0; i < bucket1.getSize(); i++)
		std::cout << "Egg[" << i << "] - " << "Name: " << bucket1.getEggByIndex(i).getEggName() <<
		" Size: " << bucket1.getEggByIndex(i).getEggSize() << std::endl;
	//bucket0 /= 5;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Bucket name: " << bucket2.getOwnerName() << " Size: " << bucket2.getSize() <<
		" Capacity: " << bucket2.getCapacity() << std::endl << "Eggs: " << std::endl;
	for (int i = 0; i < bucket2.getSize(); i++)
		std::cout << "Egg[" << i << "] - " << "Name: " << bucket2.getEggByIndex(i).getEggName() <<
		" Size: " << bucket2.getEggByIndex(i).getEggSize() << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "bucket0 + bucket1 : " << one.getOwnerName() << " " << "size: " << one.getSize() << " " <<
		"capacity: " << one.getCapacity() << std::endl << "eggs: " << std::endl;
	for (int i = 0; i < one.getSize(); i++)
		std::cout << "egg[" << i << "]: " << "name: " << one.getEggByIndex(i).getEggName() << " " << "size: "<< one.getEggByIndex(i).getEggSize() << std::endl;
	
	bucket0 %= bucket1;
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "Bucket name: " << bucket0.getOwnerName() << " Size: " << bucket0.getSize() <<
		" Capacity: " << bucket0.getCapacity() << std::endl << "Eggs: " << std::endl;
	for (int i = 0; i < bucket0.getSize(); i++)
		std::cout << "Egg[" << i << "] - " << "Name: " << bucket0.getEggByIndex(i).getEggName() <<
		" Size: " << bucket0.getEggByIndex(i).getEggSize() << std::endl;

	Bucket equal = bucket0;
	bool eq = equal >= bucket0;
	return 0;
}

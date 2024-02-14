// main.cpp 
// Практика
#include <iostream>



class Cat {
public:
	// конструктор по умолчанию
	Cat() :name_{}, breed_{}, owner_{} {}

	// параметрический контруктор
	Cat(std::string name, std::string breed, std::string owner) :name_{name}, breed_{ breed }, owner_(owner) {}

	// конструктор копирования
	Cat(Cat& cat){
		name_ = cat.Name();
		breed_ = cat.Breed();
		owner_ = cat.Owner();
	}

	// оператор сравнения котов
	bool operator ==(const Cat& cat) {
		if (name_ != cat.name_) {
			return false;
		}
		if (breed_ != cat.breed_) {
			return false;
		}
		if (owner_ != cat.owner_) {
			return false;
		}
		return true;
	}


	// гет и сет имя кота
	void Name(std::string name) {
		name_ = name;
	}

	std::string Name() {
		return name_;
	}

	// гет и сет порода
	void Breed(std::string breed) {
		breed_ = breed;
	}

	std::string Breed() {
		return breed_;
	}

	// гет и сет владельца
	void Owner(std::string owner) {
		owner_ = owner;
	}

	std::string Owner() {
		return owner_;
	}



private:
	std::string name_;
	std::string breed_;
	std::string owner_;
};


class Hotel{
public:
	Hotel() :c_arr_{ nullptr }, size_(4), count_{}, index_{} {
		c_arr_ = new Cat[size_];
	}
	
	Hotel(const Cat& cat) :c_arr_{}, size_(4), count_{ 1 }, index_{} {
		c_arr_ = new Cat[size_];
		c_arr_[index_] = cat;
		index_ += 1;
	}

	friend std::ostream& operator << (std::ostream& out, Hotel& hotel) {
			for (int i = 0; i < hotel.count_; i++) {
				out << "Cat " << i + 1 << ": " << hotel.c_arr_[i].Name() << ", " << hotel.c_arr_[i].Breed() << ", " << hotel.c_arr_[i].Owner() << "\n";
			}

			return out;
	}
	
	void ad_cat(const Cat& cat) {
		if (index_ < size_)
		{
			c_arr_[index_] = cat;
			count_ += 1;
			index_ += 1;

			
		}
		else
		{
			throw - 1;
		}
	}

	int find_cat(std::string name) {
		for (int i = 0; i < size_; i++) {
			if (c_arr_[i].Name() == name) {
				return i + 1;
			}
		}
		return -1;
	}

	

	void del_cat(const Cat& cat) {
		if (count_ > 0)
		{
			int tmp_count{};
			Cat* tmp = new Cat[size_];

			for (int i = 0; i < size_; i++) {
				if (c_arr_[i] == cat) {
					tmp_count -= 1;
				}
				else {
					tmp[tmp_count] = c_arr_[i];
				}
				tmp_count += 1;
			}
			count_ -= 1;
			c_arr_ = tmp;
		}
		else
		{
			throw - 1;
		}
	}

	int free_places() {
		return size_ - count_;
	}

	int getSize() {
		return size_;
	}

	void setSize(int size) {
		Cat* tmp = new Cat[size];

		for (int i = 0; i < size_; i++) {
			tmp[i] = c_arr_[i];
			}
		size_ = size;
		c_arr_ = tmp;

	}


	Cat* getCat() const {
		return c_arr_;
	}






	~Hotel() {
		delete[] c_arr_;
		size_ = 0;
		count_ = 0;
	}



private:
	Cat* c_arr_; // массив котов
	int size_; // размер массива котов
	int count_; // текущее количество котов
	int index_; // текущий кот

};





int main() {


	Cat cat1("Cat_Tom", "Red", "Peter");
	Cat cat2("Cat_Blue", "Blue", "Victor");
	Cat cat3("Cat_Purple", "Blond", "Bob");


	Hotel htl1(cat1);

	std::cout << "Max hotel have had : " << htl1.getSize() << std::endl;


	htl1.ad_cat(cat2);

	htl1.ad_cat(cat3);
	htl1.ad_cat(cat3);

	std::cout << "Find cat: " << cat2.Name() << " " << htl1.find_cat(cat2.Name()) << std::endl;
	//htl1.ad_cat(cat3);

	htl1.setSize(5);

	htl1.ad_cat(cat3);


	std::cout << htl1 << std::endl;

	std::cout << std::endl;

	htl1.del_cat(cat1);

	std::cout << htl1 << std::endl;





	return 0;
}
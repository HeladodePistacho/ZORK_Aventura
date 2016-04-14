#ifndef _ARRAY_DINAMIC_
#define _ARRAY_DINAMIC_

//empty, clean, size, capacity, pop back, shrink to fit.

template <class TYPE>

class dynamic_array
{
private:

	
	unsigned int capacity = 5;
	unsigned int num_elements = 0;

public:

	TYPE* vector;

public:

	dynamic_array()
	{
		vector = new TYPE[capacity];	
	}

	dynamic_array(const dynamic_array& other_array)
	{
		capacity = other_array.capacity;
		num_elements = other_array.num_elements;
		vector = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; ++i)
		{
			vector[i] = other_array.vector[i];
		}
	}

	void push_back(const TYPE& new_element)
	{
		if (num_elements == capacity)
		{
			capacity *= 2;
			TYPE* temp_vector = new TYPE[capacity];

			for (unsigned int i = 0; i < num_elements; i++)
			{
				temp_vector[i] = vector[i];
			}

			delete[] vector;
			vector = temp_vector;

		}
		vector[num_elements] = new_element;
		num_elements++;
		
	}

	void push_front(const TYPE& new_element)
	{
		if (num_elements + 1 == capacity)
		{
			capacity *= 2;
			TYPE* temp_vector = new TYPE[capacity];
			for (unsigned int i = 0; i < num_elements; i++)
			{
				temp_vector[i] = vector[i];
			}

			delete[]vector;
			vector = temp_vector;
			
		}

		for (int j = num_elements; j > -1; j--)
		{
			vector[j + 1] = vector[j];
		}

		vector[0] = new_element;
		num_elements++;

	}



	TYPE operator[](const unsigned int position) const
	{
		return vector[position];
	}
	
	bool empty() const
	{
		return num_elements == 0;
	}

	void clean()
	{
		capacity = 5;
		num_elements = 0;
		delete[] vector;
		vector = new TYPE[capacity];
		
	}

	unsigned int get_size()const
	{
		return num_elements;
	}

	unsigned int get_capacity()const
	{
		return capacity;
	}

	void pop_back()
	{
		vector[num_elements] = nullptr;
		num_elements--;
	}

	

	



};


#endif
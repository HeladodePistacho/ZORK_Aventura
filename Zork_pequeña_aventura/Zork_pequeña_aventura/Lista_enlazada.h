#ifndef _LIST_
#define _LIST_


//FER PUSHBACK I PUSHFRONT

template <class TYPE>

class my_list
{
public: //should be private

	struct node
	{
		TYPE data;
		node* next = nullptr;

		node(const TYPE& data_member) : data(data_member) {}
	};

	node* first_node = nullptr;

public:

	bool empty() const
	{
		return first_node == nullptr;
	}

	unsigned int size() const
	{
		node* next_node = first_node;
		unsigned int i = 0;

		while (next_node != nullptr)
		{
			next_node = next_node->next;
			i++;
		}

		return i;
	}

	node* end() const
	{
		node* next_node = first_node;

		if (first_node != nullptr)
		{
			while (next_node->next != nullptr)
				next_node = next_node->next;

		}

		return next_node;

	}

	void PushBack(const TYPE& new_element)
	{
		node* added_node = new node(new_element);

		if (first_node == nullptr)
		{
			first_node = added_node;
		}
		else
		{
			node* last_node = end();
			last_node->next = added_node;
		}

	}

	void PushFront(const TYPE& new_node)
	{
		node* frontal_node = first_node;
		first_node = new node(new_node);
		first_node->next = frontal_node;
	}

	void PopBack()
	{
		if (first_node != nullptr)
		{
			if (first_node->next != nullptr)
			{
				node*  final_element = first_node;
				node*  penultim_node = first_node;

				while (final_element->next != nullptr) final_element = final_element->next;
				while (penultim_node->next != final_element) penultim_node = penultim_node->next;

				penultim_node->next = nullptr;
				delete final_element;

			}
			else
			{
				delete first_node;
				first_node = nullptr;
			}
		}

	}

	node* PopBack()
	{
		if (first_node != nullptr)
		{
			if (first_node->next != nullptr)
			{
				node*  final_element = first_node;
				node*  penultim_node = first_node;

				while (final_element->next != nullptr) final_element = final_element->next;
				while (penultim_node->next != final_element) penultim_node = penultim_node->next;

				penultim_node->next = nullptr;
				return final_element;
				delete final_element;

			}
			else
			{
				return first_node;
				delete first_node;
				first_node = nullptr;
			}
		}
	}

	void PopFront()
	{
		if (first_node != nullptr)
		{
			if (first_node->next != nullptr)
			{
				node* deleted_node = first_node;
				first_node = deleted_node->next;
				delete deleted_node;
			}
			else
			{
				delete first_node;
				first_node = nullptr;
			}
		}
	}

	void Erase(unsigned int position)
	{

		if (position <= size() - 1)
		{
			node* erased_node = first_node;
			node* pre_erased_node = first_node;

			while (position > 0)
			{
				erased_node = erased_node->next;
				position--;
			}

			if (erased_node != first_node)
			{
				while (pre_erased_node->next != erased_node) pre_erased_node = pre_erased_node->next;
				pre_erased_node->next = erased_node->next;
				delete erased_node;
			}
			else {
				delete first_node;
				first_node = nullptr;
			}



		}

	}

	node* Erase(node* erased_node)
	{
		if (erased_node != nullptr)
		{
			node<TYPE>* pre_erased_node = first_node;

			if (erased_node == first_node)
			{
				return first_node;
				delete first_node;
				first_node = nullptr;
			}
			else
			{
				while (pre_erased_node->next != erased_node) pre_erased_node = pre_erased_node->next;
				pre_erased_node->next = erased_node->next;
				return erased_node;
				delete erased_node;
			}

		}
	}

	void Erase(node* erased_node)
	{
		if (erased_node != nullptr)
		{
			node<TYPE>* pre_erased_node = first_node;

			if (erased_node == first_node)
			{
				delete first_node;
				first_node = nullptr;
			}
			else
			{
				while (pre_erased_node->next != erased_node) pre_erased_node = pre_erased_node->next;
				pre_erased_node->next = erased_node->next;
				delete erased_node;
			}

		}
	}


	void Insert(const TYPE& new_element, unsigned int position)
	{


		if (position <= size() - 1)
		{
			node* moved_node = first_node;
			node* pre_moved_node = first_node;
			node* inserted_node = new node(new_element);

			while (position > 0)
			{
				moved_node = moved_node->next;
				position--;
			}

			if (moved_node != first_node)
			{
				while (pre_moved_node->next != moved_node) pre_moved_node = pre_moved_node->next;
				pre_moved_node->next = inserted_node;
			}
			else first_node = inserted_node;
			
			inserted_node->next = moved_node;
		}


	}

	
	

};


#endif

//erase(node* i el deletea)
#include <iostream>

template< class T >
struct List
{
  T data;
  List< T >* next;
};

template< class T >
List< T >* reverse_with_list(List< T >* head)
{
  List< T >* stackHead = nullptr;
  List< T >* current = head;

  while (current != nullptr)
  {
    List< T >* newNode = new List< T >{current->data, stackHead};
    stackHead = newNode;
    current = current->next;
  }
  return stackHead;

}

template< class T >
List< T >* reverce_cleanly(List< T >* head) noexcept
{
  return nullptr;
}

template< class T >
List< T >* reverse_recursively(List< T >* head) noexcept
{
  return nullptr;
}

template< class T >
void free_list(List< T >* head)
{
  List< T >* current = head;
  while (current != nullptr)
  {
    List< T >* next = current->next;
    delete current;
    current = next;
  }
}

template< class T >
void print_list(std::ostream& out, List< T >* head)
{
  List< T >* current = head;
  while (current != nullptr)
  {
    out << current->data;
    current = current->next;
  }
}

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    return 1;
  }
  int num = 0;
  std::cin >> num;
  List< int >* head = new List< int >{num, nullptr};
  try
  {
    while(std::cin >> num)
    {
      if (!std::cin)
      {
        std::cerr << "incorrect input\n";
        free_list(head);
        return 1;
      }
      List< int >* newNode = new List< int >{num, nullptr};
      List< int >* current = head;
      while (current->next != nullptr)
      {
        current = current->next;
      }
      current->next = newNode;
    }
  }
  catch (const std::bad_alloc&)
  {
    free_list(head);
    return 1;
  }

  std::string param = argv[1];
  if (param == "0")
  {
    head = reverse_with_list(head);
  }


  print_list(std::cout, head);
  std::cout << "\n";

  free_list(head);
}

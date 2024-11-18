#include <iostream>

class myArray {
private:
    int total_size;
    int used_size;
    int *ptr;
public:
    myArray(int tSize);
    ~myArray();
    void insert(int index, int value);
    void remove(int index);
    int search(int value);
    void sort();
    void resize(int newSize);
    void display();
    void update(int index, int value);
    void setVal(int totalItems);
};

// constructor - creates array as a abstract data type
myArray::myArray(int tSize){
    total_size = tSize;
    used_size = 0;
    ptr = new int[total_size];
    std::cout << "Array created" << std::endl;
}

// destructor - releases memory of ptr 
myArray::~myArray(){
    delete [] ptr;
}

//display method - iterating over a for loop to display the items in the array
void myArray::display(){
    std::cout << "[ "; 
    for(int i=0; i<used_size; i++){
        std::cout << ptr[i] <<  " ";
    }
    std::cout << " ]" << std::endl;
}

//insert method - moves item behind the index and add adds index if the conditions are valid 
void myArray::insert(int index, int value){
    if(used_size>=total_size){
        std::cout << "Array is full" << std::endl;
        return;
    }
    if(index<0 || index>used_size){
        std::cout << "Index out of range" << std::endl;
        return;
    }

    /*  
    So if used_size is equal to i then I will be pointing to the empty same next to the last item of array
    after that the for loop will move the array items one step backward till the array box and them puts the value.
     */
    for(int i=used_size; i>index; i--){
        ptr[i] = ptr[i-1];
    }
    ptr[index] = value;
    used_size++;
    std::cout << value << " inserted successfully" << std::endl;
}

void myArray::setVal(int totalItems){
    used_size = totalItems;
    for(int i=0; i<used_size; i++){
        std::cout << "Enter value for item: [" << i << "] : ";
        std::cin >> ptr[i]; 
    }
    std::cout << totalItems << " items entered." << std::endl;
}

int main(){
    myArray a1(10);
    a1.setVal(3);
    a1.display();
    a1.insert(0, 10);
    a1.display();

    return 0;
}
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
    void append(int value);
    
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

void myArray::remove(int index){
    if (index >= 0 && index < used_size) {
        for(int i=index; i<used_size; i++){
            ptr[i] = ptr[i+1];
        }
        used_size--;
        std::cout << "Item removed" << std::endl;
    } else {
        std::cout << "Item removed unsuccessful" << std::endl;
    }
}

int myArray::search(int value){
    for(int i=0; i<used_size; i++){
        if(ptr[i] == value){
            return i;
        }
    }
    return -1;
}

void myArray::sort(){
    if(used_size <= 1) return;
    int temp = 0;
    for(int i=0; i<used_size; i++){
        for(int j=i+1; j<used_size; j++){
            if(ptr[i]>ptr[j]){
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
    std::cout << "Sorting Successful" << std::endl;
}

void myArray::update(int index, int value){
    if(index>0 && index<used_size){
        ptr[index] = value;
        std::cout << "Value updated" << std::endl;
    }
}

void myArray::resize(int newSize){
    int * new_ptr = new int[newSize];
    for(int i=0; i<used_size; i++){
        new_ptr[i] = ptr[i];
    }
    delete [] ptr;
    total_size = newSize;
    ptr = new_ptr;
}

void myArray::append(int value){
    if(used_size<total_size){
        ptr[used_size] = value;
        used_size++;
    } else {
        std::cout << "Array Size Full" << std::endl;
    }
}
int main(){
    myArray a1(3);
    a1.append(10);
    a1.append(3);
    a1.append(1);
    a1.append(8);
    a1.append(5);
    a1.display();
    a1.sort();
    a1.display();
    a1.resize(5);
    a1.append(10);
    a1.append(20);
    a1.append(30);
    a1.display();

    return 0;
}
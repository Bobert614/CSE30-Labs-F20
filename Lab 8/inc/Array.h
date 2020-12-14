#ifndef Array_h
#define Array_h

#include <iostream>
#include <ostream>

struct ResizableArray {
    // This is the poiner to the start of our array
    std::string* data;
    
    // Keep track of how much memory we have allocated
    long capacity;
    
    // Keep track of how much memory we have used
    long count;
    
    // A default constructor
    ResizableArray(){
        // Start off by allocating memory for 1 int
        data = new std::string[1];
        
        // This means we have allocated for 1
        capacity = 1;
        
        // And we are currently using 0
        count = 0;
    }

	// This is a copy constructor. It specifies what happens when
	// the array needs to be copied. In this case it performs
	// a deep copy, which is what we need
	ResizableArray(const ResizableArray& other){
		capacity = other.capacity;
		count = other.count;
		data = new std::string[other.capacity];

		for (long i = 0; i < other.count; i++){
			data[i] = other.data[i];
		}
	}

    void operator=(const ResizableArray& other){
        std::cout << "HI" << std::endl;
		capacity = other.capacity;
		count = other.count;
		data = new std::string[other.capacity];

		for (long i = 0; i < other.count; i++){
			data[i] = other.data[i];
		}
    }

    std::string& operator[](long index) const {
        return data[index];
    }

	// Overloading the == operator. Now we can compare 
	// two ResizableArrays with the == operator
	bool operator==(const ResizableArray rhs) const {
		// If the capacitys or counts are different, it's not a match
		if (capacity != rhs.capacity){
			return false;
		}
		if (count != rhs.count){
			return false;
		}

		// Assume the arrays match
		bool same = true;

		// And try to find a contradiction
		for (long i = 0; i < count; i++){
			if (data[i] != rhs.data[i]){
				return false;
			}
		}
		
		// Colud not get a contradiction
		return true;
	}
    
    // Print the contents we have
    void print(){
        for (long i = 0; i < count; i++){
            std::cout << data[i] << std::endl;
        }
    }
    
	// Get the value at a specified position
    std::string get(long index){
        return data[index];
    }
    
	// Set the value at a specified position with a given integer
    void set(long index, std::string value){
        data[index] = value;
    }

	void insert(long index, std::string value){
        if (index < capacity){
            for(long i = count; i > index; i--){
                data[i] = data[i-1];
            }
            data[index] = value;
            count++;
            if (count == capacity){
                long oldcapacity = capacity;
                
                capacity = capacity * 2;
                
                std::string* newArr = new std::string[capacity];
            
                for (long i = 0; i < oldcapacity; i++) {
                    newArr[i] = data[i];
                }
                
                delete[] data;
                
                data = newArr;
            }
        }
        else{
            long oldcapacity = capacity;
            while (index+1 >= capacity){
                capacity *=2;
            }
            if (capacity > oldcapacity){
                std::string* newArr = new std::string[capacity];
                
                for (long i = 0; i < oldcapacity; i++) {
                    newArr[i] = data[i];
                }
                
                delete[] data;
                
                data = newArr;
            }
            
            for (long i = count; i < index; i++){
                data[i] = "";
            }
            
            data[index] = value;
            count = index + 1;
        }
    }
    
    
    // Store a new value in the array
    void append(std::string value){
        // The very first time this is called
        // we know we have enough storage allocated
        // because we allocated space for 1 int
        // so we store it
        data[count] = value;
        // and increase the count
        count++;
        
        // If we are out of space, i.e. we have
        // stored as much as we have allocated
        // then we need to increase our storage space
        if (count == capacity){
            // Just for convenience, store the old capacity
            long oldcapacity = capacity;
            
            // Let's double the amount of storage we have
            capacity = capacity * 2;
            
            // Allocate another chunk of memory
            // twice as big as the first
            std::string* newArr = new std::string[capacity];
            
            // Copy all elements from the old location
            // to the new location
            for (long i = 0; i < oldcapacity; i++) {
                newArr[i] = data[i];
            }
            
            // Release the old location
            delete[] data;
            
            // Make our data pointer point to the new location
            data = newArr;
            
        }
    }
	
	// This is called a destructor. It simply releases the 
	// memory we have been using.
	~ResizableArray(){
		delete[] data;
	}
};

// This is an overload of the << operator, which allows us
// to print out the ResizableArray with cout <<
std::ostream& operator<<(std::ostream& os, const ResizableArray& arr) {
    for (long i = 0; i < arr.count; i++){
		os << arr.data[i] << " ";
	}

    return os;
}

#endif

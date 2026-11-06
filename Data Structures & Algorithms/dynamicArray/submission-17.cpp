class DynamicArray {
private:
    int arrCapacity;
    int* dynamicArr;
    int size;
public:

    DynamicArray(int capacity) {
        arrCapacity = capacity;
        size = 0;
        dynamicArr = new int[arrCapacity]; 
        for(int i = 0; i < capacity; i++){
            (dynamicArr)[i] = 0;
        }
    }

    int get(int i) {
        return (dynamicArr)[i];
    }

    void set(int i, int n) {
        (dynamicArr)[i] = n;
    }

    void pushback(int n) {
        if(size == arrCapacity){
            resize();
        }

        (dynamicArr)[size] = n; 
        size++;
    }

    int popback() {
        int popped = (dynamicArr)[size - 1];
        (dynamicArr)[size - 1] = 0;
        size--;
        return popped;
    }

    void resize() {
        int* newArr = new int[2*arrCapacity];

        for(int i = 0; i < size; i++){
            newArr[i] = dynamicArr[i];
        }

        arrCapacity *= 2;
        delete [] dynamicArr;
        dynamicArr = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return arrCapacity;
    }
};

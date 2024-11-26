import random
def binarySearchRecursive(arr, element, low, high):
    while(low<=high): 
        mid = low + (high - low) // 2

        if arr[mid] == element:
            return mid
        elif arr[mid] > element:
            return binarySearchRecursive(arr, element, low, mid-1)
        else :
            return binarySearchRecursive(arr, element, mid+1, high)
    return -1;

def binarySearchIterative(arr, element):
    low = 0
    high = len(arr) - 1
    while(low <= high):
        mid = low + (high - low) // 2;
        if arr[mid] == element:
            return mid
        elif arr[mid] < element:
            low = mid + 1
        else: 
            high = mid - 1
    return -1


def sort(arr):
    for i in range(len(arr)):
        for j in range(i+1,len(arr)):
            if arr[i] > arr[j]:
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

    return arr


if __name__ == "__main__":
    test1Array = [2,4,1,0,3,6,5,9,7,8];
    searchingValue = random.choice(test1Array)
    sortedArray = sort(test1Array[:])
    print(sortedArray)
    print("The search value is ",searchingValue)
    print("Binary Search Iterative ->",binarySearchIterative(sortedArray,searchingValue))

    print("Binary Search Recursive ->", binarySearchRecursive(sortedArray, searchingValue, 0, len(sortedArray)-1))
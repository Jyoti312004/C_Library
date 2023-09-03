//// generic swap function to swap the elements
void Swap(void* a, void* b, size_t size) ;
// generic mini function to get the minium element
void* mini(const void* arr, size_t total_size, size_t size, int (*compar)(const void*, const void*));
// generic maxi function to get the maximum element
void* maxi(const void* arr, size_t total_size, size_t size, int (*compar)(const void*, const void*));

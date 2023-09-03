void* linear_search(const void* arr, size_t total_size, size_t size, const void* target, int (*compar)(const void*, const void*)) ;
void* binary_search(const void* arr, size_t total_size, size_t size, const void* target, int (*compar)(const void*, const void*));
void* searching(const void* arr, size_t total_size, size_t size, const void* key, int (*compar)(const void*, const void*)) ;
// int compare_int(const void *a, const void *b);
// int compare_double(const void *a, const void *b);
// int compare_char(const void *a, const void *b);

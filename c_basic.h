void Swap(void* a, void* b, size_t size) ;
int Compare( const void* a, const void* b);
void* min(const void* arr, size_t total_size, size_t size, int (*compar)(const void*, const void*));
void* max(const void* arr, size_t total_size, size_t size, int (*compar)(const void*, const void*));
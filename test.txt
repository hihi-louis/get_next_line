#include <stdio.h>
#include <stdlib.h>

static char *custom_free(char **s)
{
    if (*s) {
        free(*s);    // Free the memory
        //*s = NULL; // Commented out to simulate the issue
    }
    return (NULL);    // Return NULL for consistency
}

void test_without_null()
{
    char *str = malloc(20 * sizeof(char));

    if (!str) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Assign some value to the allocated memory
    snprintf(str, 20, "Hello, World!");
    printf("Before free: Address: %p, Content: %s\n", (void *)str, str);

    // Free the memory using the custom_free function
    custom_free(&str);

    // Attempt to access the pointer after free
    printf("After free: Address: %p, Content: %s\n", (void *)str, str);

    // Attempt to free the pointer again (double free)
    free(str);  // This may crash the program since `str` is not NULL
}

int main()
{
    printf("Testing without setting pointer to NULL:\n");
    test_without_null();
    return 0;
}


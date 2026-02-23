void foo(int *a) {
    *a = *a + 1; // acessa ponteiro
}

int main(void) {
    int a = 0;
    int b = 0;

    while (1) {
        foo(&a);

        if (a > 5) {
            b = 1;
            break;
        }
    }
    printf("B agora vale %d\n", b);

    return 0;
}
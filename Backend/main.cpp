#include "backend.h"

int main(int argc, char *argv[])
{
    FILE *tree     = fopen(argv[1], "rb");
    FILE *asm_code = fopen(argv[2], "wb");

    if (!tree && !asm_code)
        printf("\nSorry, file \"%s\" doesn't exist and file \"%s\" cannot be open (system error)\n", argv[1], argv[2]);
    else if (!tree)
    {
        printf("\nSorry, file \"%s\" doesn't exist\n", argv[1]);
        fclose(asm_code);
    }
    else if (!asm_code)
    {
        printf("\nSorry, file \"%s\" cannot be opened (system error).\n", argv[2]);
        fclose(tree);
    }
    else
    {
        backend(tree, asm_code);

        fclose(tree);
        fclose(asm_code);

        printf("OK. The program has been compiled into assembler file.\n");
    }

    return 0;
}
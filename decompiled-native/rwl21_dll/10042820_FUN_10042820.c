// 10042820 FUN_10042820 [Global]
// program: RWL21.DLL

undefined4 FUN_10042820(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = 0;
    if (*(char *)(param_1 + 0x3a) != '\0') {
      piVar1 = (int *)(param_1 + 0x3c);
      do {
        iVar2 = iVar2 + 1;
        *piVar1 = param_2 + (((*piVar1 - *(int *)(*(int *)(param_1 + 0x34) + 0x88)) + -0xc) / 0x74)
                            * 0x74 + 0xc;
        piVar1 = piVar1 + 1;
      } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x3a));
    }
    iVar2 = FUN_10042820(*(int *)(param_1 + 0x30),param_2);
    if (iVar2 == 0) {
      return 0;
    }
  }
  return 1;
}


